#include "Administrator.hpp"

Administrator :: Administrator() {
    username = "admin";
    password = "i<3c++";
    administrator = true;
    std::ofstream in;
    in.open("Users.txt");
    if (in.is_open()) {
        in << username << '\n';
        in << password << '\n';
        in.close();
    }
    else {
        std::cout << "Unable to open Users.txt\n";
    }
}