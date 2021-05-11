cmake_minimum_required(VERSION 3.17)

project(Library)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("include"
                "src"
                "doctest")

add_executable(library "main.cpp"
                "src/menu.cpp"
                "src/String.cpp")

add_executable(test "Tests/main.cpp"
                "doctest/doctest.h")

add_executable(string "Tests/string.cpp"
                "include/String.hpp"
                "src/String.cpp"
                "doctest/doctest.h")