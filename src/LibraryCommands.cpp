#include "LibraryCommands.hpp"

bool LibraryCommands::is_logged;

LibraryCommands :: LibraryCommands() {
    is_logged = false;
}

State LibraryCommands :: login() {
    if (is_logged) {
        return NOTLOGGED;
    }
    library::String user;
    library::String pass;
    std::cout << "Username: ";
    std::cin >> user;
    User::setUsername(user);
    std::cout << "Password: ";
    std::cin >> pass;
    User::setPassword(pass);
    std::ifstream read;
    read.open("Users.txt");
    if (read) {
        library::String firstLine = "*";
        library::String secondLine = "*";
        while (firstLine[0] != '\0' || secondLine[0] != '\0') {
            read >> firstLine;
            read >> secondLine;
            if (firstLine == user && secondLine == pass) {
                read.close();
                is_logged = true;
                std::cout << "Welcome, " << user << '!' << '\n';
                return SUCCESS;
            }
        }
    }
    else {
        return FAIL;
    }
    return NOTMATCH;
}

State LibraryCommands :: logout() {
    if (is_logged) {
        is_logged = false;
        return SUCCESS;
    }
    return NOTLOGGED;
}

State LibraryCommands :: users_add() {
    library::String user;
    std::cin >> user;
    library::String pass;
    std::cin >> pass;
    std::ofstream write;
    write.open("Users.txt");
    if (write) {
        write << user;
        write << '\n';
        write << pass;
        write.close();
        return SUCCESS;
    }
    else return FAIL;
}