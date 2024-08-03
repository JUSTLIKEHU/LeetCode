// #include <any>
// #include <functional>
// #include <iostream>
// #include <map>
// #include <stdexcept>
// #include <string>
// #include <vector>

// class MyClass {
// public:
//   int func1(int a) {
//     std::cout << "func1 called with " << a << std::endl;
//     return a + 1;
//   }

//   std::string func2(const std::string &str) {
//     std::cout << "func2 called with " << str << std::endl;
//     return str + " World";
//   }

//   template <typename Ret, typename... Args>
//   void registerFunction(const std::string &name,
//                         Ret (MyClass::*func)(Args...)) {
//     funcMap[name] = [func](MyClass &obj,
//                            std::vector<std::any> &args) -> std::any {
//       return callHelper<Ret, decltype(func), Args...>(
//           obj, func, args, std::index_sequence_for<Args...>{});
//     };
//   }

//   template <typename Ret, typename... Args>
//   Ret callFunction(const std::string &name, Args... args) {
//     auto it = funcMap.find(name);
//     if (it != funcMap.end()) {
//       std::vector<std::any> anyArgs = {args...};
//       std::any result = it->second(*this, anyArgs);
//       return std::any_cast<Ret>(result);
//     } else {
//       throw std::runtime_error(
//           "Function not found or incorrect argument types.");
//     }
//   }

// private:
//   std::map<std::string,
//            std::function<std::any(MyClass &, std::vector<std::any> &)>>
//       funcMap;

//   template <typename Ret, typename Func, typename... Args, std::size_t... I>
//   static Ret callHelper(MyClass &obj, Func func, std::vector<std::any> &args,
//                         std::index_sequence<I...>) {
//     return (obj.*func)(std::any_cast<Args>(args[I])...);
//   }
// };

// int main() {
//   MyClass myObject;

//   myObject.registerFunction("func1", &MyClass::func1);
//   myObject.registerFunction("func2", &MyClass::func2);

//   try {
//     int result1 =
//         myObject.callFunction<int>("func1", 42); // 调用func1并传递int参数
//     std::cout << "Result of func1: " << result1 << std::endl;

//     std::string result2 = myObject.callFunction<std::string>(
//         "func2", std::string("Hello")); // 调用func2并传递string参数
//     std::cout << "Result of func2: " << result2 << std::endl;

//     // 错误参数类型
//     myObject.callFunction<int>("func1", std::string("Hello"));
//   } catch (const std::exception &e) {
//     std::cout << e.what() << std::endl;
//   }

//   try {
//     // 测试不存在的函数
//     myObject.callFunction<int>("nonexistent", 42);
//   } catch (const std::exception &e) {
//     std::cout << e.what() << std::endl;
//   }

//   return 0;
// }

#include <any>
#include <functional>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

class MyClass {
public:
    int func1(int& a) {
        std::cout << "func1 called with " << a << std::endl;
        return a + 1;
    }

    std::string func2(const std::string &str) {
        std::cout << "func2 called with " << str << std::endl;
        return str + " World";
    }

    template<typename Ret, typename... Args>
    void registerFunction(const std::string &name, Ret (MyClass::*func)(Args...)) {
        auto lambda = [func, this](Args... args) -> Ret {
            return (this->*func)(args...);
        };
        std::function<Ret(Args...)> funcWrapper = lambda;
        funcMap[name] = funcWrapper;
    }

    template<typename Ret, typename... Args>
    Ret callFunction(const std::string &name, Args... args) {
        auto it = funcMap.find(name);
        if (it != funcMap.end()) {
            auto func = std::any_cast<std::function<Ret(Args...)>>(it->second);
            return func(args...);
        } else {
            throw std::runtime_error("Function not found or incorrect argument types.");
        }
    }

private:
    std::map<std::string, std::any> funcMap;
};

int main() {
    MyClass myObject;

    myObject.registerFunction("func1", &MyClass::func1);
    myObject.registerFunction("func2", &MyClass::func2);

    try {
        int value = 5;
        int result1 = myObject.callFunction<int, int&>("func1", value); // 调用func1并传递int&参数
        std::cout << "Result of func1: " << result1 << std::endl;

        std::string result2 = myObject.callFunction<std::string, const std::string&>(
            "func2", std::string("Hello")); // 调用func2并传递string参数
        std::cout << "Result of func2: " << result2 << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
