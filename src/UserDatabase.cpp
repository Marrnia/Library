#include "UserDatabase.hpp"

UserDatabase :: UserDatabase() {
    User defaultUser("admin", "admin", true);
    users.push_back(defaultUser);
}

State UserDatabase :: login(bool& logged, bool& admin) {
    if (logged) {
        return NOTLOGGED;
    }
    String temp;
    char ch;
    char pass[25];
    const char BACKSPACE = 8;
    const char RETURN = 13;
    size_t i = 0;
    String username;
    String password;
    std::cout << "Enter username:";
    std::cin >> username;
    std::cout << "Enter password:";
    while (ch != RETURN) {
        ch = getch();
        if (ch != RETURN && ch != BACKSPACE) {
            putch('*');
            pass[i] = ch;
            ++i;
        }
        if (ch == BACKSPACE && i > 0) {
            --i;
            std::cout << "\b \b";
            continue;
        }
    }
    pass[i] = '\0';
    std::cout << '\n';

    User temp_user;
    temp_user.setUsername(username);
    password = pass;
    temp_user.setPassword(password);

    if (users.isExist(temp_user)) {
        logged = true;
        admin = temp_user.is_administrator();
        currentName = username;
        return SUCCESS;
    }   
    logged = false;
    admin = false;
    return NOTMATCH;
}

State UserDatabase :: logout(bool& isLogged, bool& admin) {
    if (isLogged) {
        isLogged = false;
        admin = false;
        return SUCCESS;
    }
    return NOTLOGGED;
}

State UserDatabase :: add(const String& name, const String& pass, const bool& logged, const bool& admin) {
    if (!admin) {
        return NOTADMIN;
    }
    User user(name, pass ,false);
    if (users.isExist(user)) {
        return NOTMATCH;
    }
    char ch;
    std::cout << "Admin rights (Y/N): ";
    std::cin >> ch;
    if (ch == 'y' || ch == 'Y') {
        user.setAdmin(true);
    }
    else if (ch == 'n' || ch == 'N') {
        user.setAdmin(false);
    }
    else user.setAdmin(false);
    std::cin.ignore(100, '\n');
    users.push_back(user);
    return SUCCESS;
}

State UserDatabase :: remove(const String& username, const bool& logged, const bool& admin) {
    if (!logged) {
        return NOTLOGGED;
    }
    if (!admin) {
        return NOTADMIN;
    }
    if (username == currentName) {
        return FAIL;
    }
    for (size_t i = 0; i < users.getSize(); ++i) {
        if (users[i].getUsername() == username) {
            users.remove(i);
            return SUCCESS;
        }
    }
    return NOTMATCH;
}
