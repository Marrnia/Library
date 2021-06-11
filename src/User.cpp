#include "User.hpp"


User :: User() : username("user"), password("user"), administrator(false) {}

User :: User(const String &username, const String &password, bool admin = false) : username(username), password(password), administrator(admin) {}

User :: User(const User &other) {
    this->username = other.username;
    this->password = other.password;
    this->administrator = other.administrator;
}

bool User :: operator==(const User &other) const {
    if (this->username == other.username && this->password == other.password) {
        return true;
    }
    return false;
}

bool User :: operator!=(const User &other) const {
    return (!(*this == other));
}

void User :: setUsername(const library::String& name) {
    this->username = name;
}

void User :: setPassword(const String& pass) {
    this->password = pass;
}

void User :: setAdmin(const bool& admin) {
    this->administrator = admin;
}

const String User :: getUsername() const{
    return username;
}

const String User :: getPassword() const{
    return password;
}

const bool User :: getAdmin() const {
    return administrator;
}

bool User :: is_administrator() const {
    return administrator;
}

const void User::save(std::ofstream &file) const
{
    file << this->username << "\n";
    file << this->password << "\n";
    file << std::boolalpha << this->administrator;
}

void User::load(std::ifstream& file) {
    char *buffer = new char[1000];
    file.getline(buffer, '\n');
    this->username = buffer;
    file.clear();
    file.ignore(10000, '\n');
    file.getline(buffer, '\n');
    this->password = buffer;
    file.clear();
    file.ignore(10000,'\n');
    file >> this->administrator;
    delete [] buffer;
    // file >> this->username >> this->password >> this->admin;
    // file.ignore(10000, '\n');
}

std::ostream &operator<<(std::ostream &out, const User &user)
{
    out << "Username: " << user.getUsername() << '\n';
    out << "Password: " << user.getPassword() << '\n';
    out << "Admin: ";
    (user.is_administrator() ? (out << "Yes") : (out << "No"));
    out << '\n';
    return out;
}