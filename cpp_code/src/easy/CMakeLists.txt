cmake_minimum_required(VERSION 3.15)

project(easy)

file(GLOB_RECURSE ${PROJECT_NAME}_cxx "${CMAKE_CURRENT_SOURCE_DIR}/*.c*")

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_cxx})

# build static lib for gtest
list(FILTER ${PROJECT_NAME}_cxx EXCLUDE REGEX "main.c*")
# message("filter ${PROJECT_NAME}_cxx: ${${PROJECT_NAME}_cxx}")
add_library(${PROJECT_NAME}_lib STATIC ${${PROJECT_NAME}_cxx})

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_SOURCE_DIR}/build/bin)
install(TARGETS ${PROJECT_NAME}_lib DESTINATION ${CMAKE_SOURCE_DIR}/build/bin)
