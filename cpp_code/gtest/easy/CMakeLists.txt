cmake_minimum_required(VERSION 3.15)

link_libraries(gtest pthread easy_lib)
add_executable("IsPalindromeTest" test_isPalindrome.cpp)


install(TARGETS "IsPalindromeTest" DESTINATION ${CMAKE_SOURCE_DIR}/build/bin)