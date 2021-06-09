cmake_minimum_required(VERSION 3.17)

project(Library)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Werror=return-type)                   # error on missing return type
add_compile_options(-Werror=format)                        # error on wrong printf formats

include_directories("include"
                "src"
                "doctest")

add_executable(library "main.cpp"
                "src/menu.cpp"
                "src/String.cpp"
                "src/User.cpp"
                "src/Administrator.cpp"
                "src/CommandLine.cpp"
                "src/LibraryCommands.cpp"
                "src/Book.cpp"
                )

add_executable(test "Tests/main.cpp"
                "doctest/doctest.h")

add_executable(string "Tests/string.cpp"
                "include/String.hpp"
                "src/String.cpp"
                "doctest/doctest.h")

add_executable(vector_string "Tests/vector_strings.cpp"
                "include/vector_strings.hpp"
                "include/String.hpp"
                "src/String.cpp"
                "doctest/doctest.h")