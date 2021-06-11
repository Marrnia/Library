#include "CommandLine.hpp"


void CommandLine :: exit() {
    std::cout << "Exiting the program...\n";
}

void CommandLine :: help() {
    std::cout << "The following command are supported:\n";
    std::cout << std::setw(40) << std::left << "open [books | users] <file>" << std::setw(10) << std::left << "opens a file\n";
    std::cout << std::setw(40) << std::left << "close" << std::setw(10) << std::left << "closes currently opened file\n";
    std::cout << std::setw(40) << std::left << "save" << std::setw(10) << std::left << "saves the currently open file\n";
    std::cout << std::setw(40) << std::left << "save as" << std::setw(10) << std::left << "saves the currently open file in <file>\n";
    std::cout << std::setw(40) << std::left << "help" << std::setw(10) << std::left << "prints this information\n";
    
    std::cout << std::setw(40) << std::left << "login" << std::setw(5) << std::left << "login\n";
    std::cout << std::setw(40) << std::left << "logout" << std::setw(5) << std::left << "logout\n";
    std::cout << std::setw(40) << std::left << "books all" << std::setw(10) << std::left << "info of the books\n";
    std::cout << std::setw(40) << std::left << "books info <isbn_value>" << std::setw(10) << std::left << "info of the specific book\n";
    std::cout << std::setw(40) << std::left << "books find <option> <option_string>" << std::setw(10) << std::left << "searching for a book\n";
    std::cout << std::setw(40) << std::left << "books sort <option> [asc | desc]" << std::setw(10) << std::left << "sorting the books in category\n";
    std::cout << std::setw(40) << std::left << "users add <user> <password>" << std::setw(10) << std::left << "adding new user with pass and name\n";
    std::cout << std::setw(40) << std::left << "user remove <user>" << std::setw(10) << std::left << "erase the specific user\n";
}
