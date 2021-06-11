#pragma once
#include <iostream>
#include "User.hpp"
#include "Book.hpp"
#include "String.hpp"
#include "State.hpp"
#include <fstream>

class Database {
public:
    Database() {};

    
    virtual State remove(const String&, const bool&, const bool&) = 0;
    bool doesItExist(const String &name) {
        std::ifstream f(name.getString());
        return f.good();
    }

    virtual State open(const String &, std::ifstream&) = 0;
    virtual State save(const String &) = 0;
    virtual State close(std::ifstream&) = 0;
};