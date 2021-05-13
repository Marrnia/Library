#include "User.hpp"

library::String User::username;
library::String User::password;
bool User::administrator;

User :: User() {
    username = " ";
    password = " ";
    administrator = true;
}

void User :: setUsername(const library::String& name) {
    username = name;
}

void User :: setPassword(const library::String& pass) {
    password = pass;
}
library::String User :: getUsername() {
    return username;
}

library::String User :: getPassword() {
    return password;
}

bool User :: is_administrator() {
    return administrator;
}