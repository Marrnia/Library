cmake_minimum_required(VERSION 3.17)

project(Library)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("include"
                "src"
                "doctest")

add_executable(library "main.cpp"
                src/menu.cpp)

add_executable(test "Tests/main.cpp"
                "doctest/doctest.h")