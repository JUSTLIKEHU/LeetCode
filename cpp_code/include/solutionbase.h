#pragma once

#include <map>
#include <stdexcept>
#include <string>
#include <any>
#include <functional>

class solutionBase{
 public:
  template <typename Ret, typename... Args>
  void registerStaticFunction(const std::string &name,
                        Ret (*func)(Args...)) {
    auto lambda = [this, func](Args... args) -> Ret {
      return func(args...);
    };
    std::function<Ret(Args...)> lambda_func = lambda;
    staticFuncMap_[name] = lambda_func;
  }

  template <typename Ret, typename... Args>
  Ret callStaticFunction(const std::string &name, Args... args) {
    auto it = staticFuncMap_.find(name);
    if (it != staticFuncMap_.end()) {
      auto func = std::any_cast<std::function<Ret(Args...)>>(it->second);
      return func(args...);
    } else {
      throw std::runtime_error(
          "Function not found or incorrect argument types.");
    }
  }
  std::map<std::string, std::any> staticFuncMap_;
};