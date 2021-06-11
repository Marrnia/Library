#include "menu.hpp"

Menu :: Menu() {
    UserDatabase();
    logged = false;
    administrator = false;
    choice();
}

void Menu :: choice() {
    std::cin >> command;
    command.toLower();
    command.removeSpaces();
    Vector<String> words;
    VectorString::splitIntoWords(command, words);
    if (words.getSize() == 1) {
        if (words[0] == "help") {
            CommandLine::help();
        }
        else if (words[0] == "close") {
            State condition;
            if (targetFile == "books") {
                condition = books.close(file_open);
            }
            else {
                condition = users.close(file_open);
            }
            if (condition == SUCCESS) {
                std::cout << "Successfully closed " << file_name << '\n'; 
            } else if (condition == FAIL) {
                std::cout << "Cannot close the file.\n";
            }
            else if (condition == NOTOPEN) {
                std::cout << "There is no opened file.\n";
            }
        }
        else if (words[0] == "exit") {
            CommandLine::exit();
            return;
        }
        else if (words[0] == "save") {
            State condition;
            if (targetFile == "books") {
                condition = books.save(file_name);
            }
            else {
                condition = users.save(file_name);
            }
            if (condition == SUCCESS) {
                std::cout << "Successfully saved " << file_name << '\n';
            }
            else if (condition == FAIL) {
                std::cout << "Failed at saving the file.\n";
            }
            else if (condition == NOTOPEN) {
                std::cout << "The file is not opened.\n";
            }
        }
        else if (words[0] == "login") {
            State condition = users.login(logged, administrator);
            if (condition == SUCCESS) {
                std::cout << "Successfully logged in!\n";
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
        else if (words[0] == "logout") {
            State condition = users.logout(logged, administrator);
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
    }
    else if (words.getSize() == 2) {
        if (words[0] == "books" &&  words[1] == "add") {
            State condition = books.add(logged, administrator);
            if (condition == SUCCESS) {
                std::cout << "Successfully added a new book!\n";
            }
            else if (condition == FAIL) {
                std::cout << "Failed to save a new record of a book!\n";
            }
            else if (condition == NOTLOGGED) {
                std::cout << "You are not logged in!\n";
            }
            else if (condition == NOTADMIN) {
                std::cout << "You are not administrator!\n";
            }
        }
        else if (words[0] == "books" && words[1] == "all") {
            State condition = books.viewBooks(logged);
            if (condition == SUCCESS) {
                
            }
            else if (condition == NOTLOGGED) {
                std::cout << "You are not logged in!\n";
            }
        }
        else {
            std::cerr << "Invalid command!\n";
            std::cin.clear();
        }
    }
    else if (words.getSize() == 3) {
        if (words[0] == "save" && words[1] == "as") {
            State condition;
            if (targetFile == "books") {
                condition = books.save(words[2]);
            }
            else {
                condition = users.save(words[2]);
            }
            if (condition == SUCCESS) {
                std::cout << "Successfully saved " << words[2] << '\n';
            }
            else if (condition == FAIL) {
                std::cout << "Failed at saving " << words[2] << '\n';
            }
            else if (condition == NOTOPEN) {
                std::cout << "The file is not opened.\n";
            }
        }
        else if (words[0] == "users" &&  words[1] == "remove") {
            State condition = users.remove(words[2], logged, administrator);
            if (condition == SUCCESS) {
                std::cout << "Successfully removed user with name " << words[2] << '\n';
            }
            else if (condition == NOTMATCH) {
                std::cout << "There is no such user!\n";
            }
            else if (condition == FAIL) {
                std::cout << "Cannot remove current user!\n";
            }
            else if (condition == NOTADMIN) {
                std::cout << "You are not logged in as an administrator!\n";
            }
            else if (condition == NOTLOGGED) {
                std::cout << "You are not logged in!\n";
            }
        }
        else if (words[0] == "books" &&  words[1] == "remove") {
            State condition = books.remove(words[2], logged, administrator);
            if (condition == SUCCESS) {
                std::cout << "Successfully removed book with title " << words[2] << '\n';
            }
            else if (condition == NOTMATCH) {
                std::cout << "There is no such book!\n";
            }
            else if (condition == NOTADMIN) {
                std::cout << "You are not logged in as an administrator!\n";
            }
            else if (condition == NOTLOGGED) {
                std::cout << "You are not logged in!\n";
            }
        }
        else if (words[0] == "books" && words[1] == "info") {
            State condition = books.viewInfo(words[2].toUnisgned(), logged);
            if (condition == SUCCESS) {

            }
            else if (condition == NOTMATCH) {
                std::cout << "There is no such book with that id!\n";
            }
            else if (condition == NOTLOGGED) {
                std::cout << "You are not logged in!\n";
            }
        }
        else if (words[0] == "books" && words[1] == "sort") {
            String asc = "asc";
            if (words[2] == "title") {
                if (logged) books.sortByTitle(asc);
                else std::cout << "You are not logged in!\n";
            }
            else if (words[2] == "author") {
                if (logged)
                    books.sortByAuthor(asc);
                else std::cout << "You are not logged in!\n";
            }
            else if (words[2] == "year") {
                if (logged) books.sortByYear(asc);
                else std::cout << "You are not logged in!\n";
            }
            else if (words[2] == "rating") {
                if (logged) books.sortByRating(asc);
                else std::cout << "You are not logged in!\n";
            }
            else {
                std::cerr << "Invalid command!\n";
                std::cin.clear();
            }
        }
        else if (words[0] == "open" && words[1] == "books") {
            State condition = books.open(words[2], file_open);
            if (condition == SUCCESS) {
                file_name = words[2];
                targetFile = "books";
                std::cout << "Successfully opened " << file_name << '\n';
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
            else if (condition == EMPTYFILE) {
                std::cout << "The file is empty!\n";
            }
            else if (condition == NOTMATCH) {
                std::cout << "Creates a new file with the name - "<< words[2] << '\n';
            }
        }
        else if (words[0] == "open" && words[1] == "users") {
            State condition = users.open(words[2], file_open);
            if (condition == SUCCESS) {
                file_name = words[2];
                targetFile = "users";
                std::cout << "Successfully opened " << file_name << '\n';
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
            else if (condition == EMPTYFILE) {
                std::cout << "The file is empty!\n";
            }
            else if (condition == NOTMATCH) {
                std::cout << "Creates a new file with the name - "<< words[2] << '\n';
            }
        }
        else {
            std::cerr << "Invalid command!\n";
            std::cin.clear();
        }
    }
    else if (words.getSize() == 4) {
        if (words[0] == "users" && words[1] == "add") {
            State condition = users.add(words[2], words[3], logged, administrator);
            if (condition == SUCCESS) {
                std::cout << "Successfully saved user.\n";
            }
            else if (condition == NOTADMIN) {
                std::cout << "You are not administrator to add new users!\n";
            }
            else if (condition == NOTMATCH) {
                std::cout << "Already exist user with that name!\n";
            }
            else if (condition == NOTLOGGED) {
                std::cout << "You are not logged in!\n";
            }
        }
        else if (words[0] == "books" && words[1] == "sort") {
            if (words[2] == "title") {
                if (words[3] == "asc") {
                    if(logged) books.sortByYear(words[3]);
                    else std::cout << "You are not logged in!\n";
                }
                else if (words[3] == "desc") {
                    if (logged) books.sortByYear(words[3]);
                    else std::cout << "You are not logged in!\n";
                }
                else {
                    std::cerr << "Invalid command!\n";
                    std::cin.clear();
                }
            }
            else if (words[2] == "author") {
                if (words[3] == "asc") {
                    if (logged) books.sortByAuthor(words[3]);
                    else std::cout << "You are not logged in!\n";
                }
                else if (words[3] == "desc") {
                    if (logged) books.sortByAuthor(words[3]);
                    else std::cout << "You are not logged in!\n";
                }
                else {
                    std::cerr << "Invalid command!\n";
                    std::cin.clear();
                }
            }
            else if (words[2] == "year") {
                if (words[3] == "asc") {
                    if (logged) books.sortByYear(words[3]);
                    else std::cout << "You are not logged in!\n";
                }
                else if (words[3] == "desc") {
                    if (logged) books.sortByYear(words[3]);
                    else std::cout << "You are not logged in!\n";
                }
                else {
                    std::cerr << "Invalid command!\n";
                    std::cin.clear();
                }
            }
            else if (words[2] == "rating") {
                if (words[3] == "asc") {
                    if (logged) books.sortByRating(words[3]);
                    else std::cout << "You are not logged in!\n";
                }
                else if (words[3] == "desc") {
                    if (logged) books.sortByRating(words[3]);
                    else std::cout << "You are not logged in!\n";
                }
                else {
                    std::cerr << "Invalid command!\n";
                }
            }
            else {
                std::cerr << "Invalid command!\n";
                std::cin.clear();
            }
        }
        else if (words[0] == "books" && words[1] == "find") {
            if (words[2] == "author") {
                if (logged) books.searchByAuthor(words[3]);
                else std::cout << "You are not logged in!\n";
            }
            else if (words[2] == "title") {
                if (logged) books.searchByTitle(words[3]);
                else std::cout << "You are not logged in!\n";
            }
            else if (words[2] == "tag") {
                if (logged) books.searchByByKeyword(words[3]);
                else std::cout << "You are not logged in!\n";
            }
            else {
                std::cerr << "Invalid command!\n";
                std::cin.clear();
            }
        }
        else {
            std::cerr << "Invalid command!\n";
            std::cin.clear();
        }
    }
    else {
        std::cerr << "Invalid command!\n";
        std::cin.clear();
    }
    choice();
}

