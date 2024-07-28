cmake_minimum_required(VERSION 3.15)

project(easy)

file(GLOB_RECURSE ${PROJECT_NAME}_cxx "${CMAKE_CURRENT_SOURCE_DIR}/*.c*")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_cxx})

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
