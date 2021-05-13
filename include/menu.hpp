#pragma once
#include <iostream>
#include "String.hpp"
#include "CommandLine.hpp"
#include "State.hpp"
#include "LibraryCommands.hpp"

class Menu {
private:
    library::String command;
    library::String file_name;
    bool logged;

    void choice();
 
public:
    Menu();
};