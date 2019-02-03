cmake_minimum_required(VERSION 3.0.0)
project(more_effe_cpp VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS 
  ${CMAKE_CXX_FLAGS} "-Weverything -std=c++14")

#set(CMAKE_CXX_FLAGS 
#  ${CMAKE_CXX_FLAGS} "-O0 -Weffc++ -Wall -Wextra -pedantic -Wconversion -Wdouble-promotion")

add_subdirectory(src/1_Intro)
add_subdirectory(src/2_Basic_Func)
add_subdirectory(src/3_Abstraction)
add_subdirectory(src/4_Standard_Lib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

