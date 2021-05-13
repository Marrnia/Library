#pragma once
#include <iostream>
#include "String.hpp"
#include <fstream>

class User {
private:
protected:
    static library::String username;
    static library::String password;
    static bool administrator;
public:
    User();
    static void setUsername(const library::String&);
    static void setPassword(const library::String&);
    static library::String getUsername();
    static library::String getPassword();
    static bool is_administrator();
};