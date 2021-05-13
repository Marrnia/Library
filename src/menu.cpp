#include "menu.hpp"

Menu :: Menu() {
    logged = false;
    choice();
}

void Menu :: choice() {
    std::cin >> command;
    if (command == "help") { /////////////
        CommandLine::help();
    }
    else if (command == "open") { //////////////
        std::cin >> command;
        if (CommandLine::open(command) == SUCCESS) {
            file_name = command;
            std::cout << "Successfully opened " << command << '\n';
        }
        else if (CommandLine::open(command) == FAIL) {
            std::cout << "Failed to opened the given file.\n";
        }
        else if (CommandLine::open(command) == WRONGTYPE) {
            std::cout << "Wrong type of the file.\n";
        }
        else if (CommandLine::open(command) == OPENED) {
            std::cout << "Already a file is opened.\n";
        }
    }
    else if (command == "close") { //////////////////////
        if (CommandLine :: close() == SUCCESS) {
            std::cout << "Successfuly closed " << file_name; 
        } else if (CommandLine :: close() == FAIL) {
            std::cout << "Cannot close the file.\n";
        }
        else if (CommandLine::close() == NOTOPEN) {
            std::cout << "There is no opened file.\n";
        }
    }
    else if (command == "exit") { //////////////////
        CommandLine::exit();
        return;
    }
    else if (command == "save") { ////////////////
        if (CommandLine::save(file_name) == SUCCESS) {
            std::cout << "Successfulyy saved " << file_name << '\n';
        }
        else if (CommandLine::save(file_name) == FAIL) {
            std::cout << "Failed at saving the file.\n";
        }
        else if (CommandLine::save(file_name) == NOTOPEN) {
            std::cout << "The file is not opened.\n";
        }
    }
    else if (command == "saveas") { ///////////////
        std::cin >> command;
        if (CommandLine::saveAs(command) == SUCCESS) {
            std::cout << "Successfully saved " << command << '\n';
        }
        else if (CommandLine::saveAs(command) == FAIL) {
            std::cout << "Failed at saving " << command << '\n';
        }
        else if (CommandLine::saveAs(command) == NOTOPEN) {
            std::cout << "The file is not opened.\n";
        }
    }
    else if (command == "login") { ///////////////
        LibraryCommands::login();
    }
    else {
        std::cerr << "Invalid command!\n";
        std::cin.clear();
    }
    std::cout << '\n';
    choice();
}

