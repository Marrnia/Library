#pragma once
#include <iostream>
#include <fstream>
#include "String.hpp"
#include "CommandLine.hpp"
#include "State.hpp"
#include "Vector.hpp"
#include "vector_strings.hpp"
#include "UserDatabase.hpp"
#include "BookDatabase.hpp"
#include "Database.hpp"

using namespace library;

class Menu {
private:
    library::String command;
    library::String file_name;
    bool logged;
    bool administrator;

    String targetFile;

    std::ifstream file_open;
    std::ofstream file_save;

    UserDatabase users;
    BookDatabase books;

    void choice();
 
public:
    Menu();
};