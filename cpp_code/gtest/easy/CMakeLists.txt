cmake_minimum_required(VERSION 3.15)

link_libraries(gtest gmock pthread easy_lib)
add_executable("IsPalindromeTest" test_isPalindrome.cpp)
add_executable("romanToIntTest" romanToInt_test.cpp)


install(TARGETS "IsPalindromeTest" DESTINATION ${CMAKE_SOURCE_DIR}/build/bin)
install(TARGETS "romanToIntTest" DESTINATION ${CMAKE_SOURCE_DIR}/build/bin)