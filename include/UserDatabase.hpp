#pragma once
#include <iostream>
#include "State.hpp"
#include "String.hpp"
#include "Vector.hpp"
#include "User.hpp"
#include "Database.hpp"

using namespace library;

class UserDatabase : public Database {
    private:
    Vector<User> users;
    String currentName;
    bool is_open;
    public:
    UserDatabase();

    State add(const String&, const String&, const bool&, const bool&);
    State remove(const String&, const bool&, const bool&);

    State login(bool&, bool&);
    State logout(bool&, bool&);

    State open(const String &, std::ifstream&);
    State save(const String &);

    State close(std::ifstream&);
};