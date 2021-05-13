#pragma once
#include <iostream>
#include <fstream>
#include "CommandLine.hpp"
#include "String.hpp"
#include "State.hpp"
#include "User.hpp"

class LibraryCommands {
private:
    static bool is_logged;
public:
    static State login();
    static State logout();

    static void books_all();
    static void books_info();
    static void books_find();
    static void books_sort();
    static void users_add();
    static void users_remove();

    LibraryCommands();
};