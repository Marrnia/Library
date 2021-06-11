#pragma once
#include <iostream>
#include "String.hpp"
#include <fstream>

using namespace library;

class User {
private:
protected:
    String username;
    String password;
    bool administrator;
public:
   /* User();
    static void setUsername(const library::String&);
    static void setPassword(const library::String&);
    static library::String getUsername();
    static library::String getPassword();
    bool is_administrator();*/

    User();
    User(const String&);
    User(const String&, const String&, bool);
    User(const User&);

    bool operator==(const User&) const;
    bool operator!=(const User&) const;

    void setUsername(const String&);
    void setPassword(const String&);
    void setAdmin(const bool&);

    const String getUsername() const;
    const String getPassword() const;
    const bool getAdmin() const;
    bool is_administrator() const;

    const void save(std::ofstream&) const;
    void load(std::ifstream&);

    friend std::ostream &operator<<(std::ostream &, const User &);

    void print() const;
};