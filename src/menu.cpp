#include "menu.hpp"

Menu :: Menu() {
    LibraryCommands();
    Administrator();
    choice();
}

void Menu :: choice() {
    std::cin >> command;
    if (command == "help") { /////////////
        CommandLine::help();
    }
    else if (command == "open") { //////////////
        std::cin >> command;
        State condition = CommandLine::open(command);
        if (condition == SUCCESS) {
            file_name = command;
            std::cout << "Successfully opened " << command << '\n';
        }
        else if (condition == FAIL) {
            std::cout << "Failed to opened the given file.\n";
        }
        else if (condition == WRONGTYPE) {
            std::cout << "Wrong type of the file.\n";
        }
        else if (condition == OPENED) {
            std::cout << "Already a file is opened.\n";
        }
    }
    else if (command == "close") { //////////////////////
        State condition = CommandLine::close();
        if (condition == SUCCESS) {
            std::cout << "Successfuly closed " << file_name; 
        } else if (condition == FAIL) {
            std::cout << "Cannot close the file.\n";
        }
        else if (condition == NOTOPEN) {
            std::cout << "There is no opened file.\n";
        }
    }
    else if (command == "exit") { //////////////////
        CommandLine::exit();
        return;
    }
    else if (command == "save") { ////////////////
        State condition = CommandLine::save(file_name);
        if (condition == SUCCESS) {
            std::cout << "Successfulyy saved " << file_name << '\n';
        }
        else if (condition == FAIL) {
            std::cout << "Failed at saving the file.\n";
        }
        else if (condition == NOTOPEN) {
            std::cout << "The file is not opened.\n";
        }
    }
    else if (command == "saveas") { ///////////////
        std::cin >> command;
        State condition = CommandLine::saveAs(command);
        if (condition == SUCCESS) {
            std::cout << "Successfully saved " << command << '\n';
        }
        else if (condition == FAIL) {
            std::cout << "Failed at saving " << command << '\n';
        }
        else if (condition == NOTOPEN) {
            std::cout << "The file is not opened.\n";
        }
    }
    else if (command == "login") { ///////////////
        State condition = LibraryCommands::login();
        if (condition == SUCCESS) {
        }
        else if (condition == NOTLOGGED) {
            std::cout << "You are already logged in!\n";
        }
        else if (condition == FAIL) {
            std::cout << "Unable to open the file Users.txt\n";
        }
        else if (condition == NOTMATCH) {
            std::cout << "Wrong username or password!\n";
        }
    }
    else if (command == "logout") {
        State condition = LibraryCommands::logout();
        if (condition == SUCCESS) {
            std::cout << "Successfully logout!\n";
        }
        else if (condition == NOTLOGGED) {
            std::cout << "You are not logged in!\n";
        }
    }
    else {
        std::cerr << "Invalid command!\n";
        std::cin.clear();
    }
    std::cout << '\n';
    choice();
}

