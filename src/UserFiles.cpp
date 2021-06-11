#include "UserDatabase.hpp"

State UserDatabase :: save(const String &filename) {

    std::ofstream file;
    file.open(filename.getString(), std::ios::out);
    if (file.fail()) {
        return FAIL;
    }
    size_t size = users.getSize();
    for (size_t i = 0; i < size; ++i) {
        users[i].save(file);
        if(i < size-1) file << '\n';
    }
    file.close();
    return SUCCESS;
}

State UserDatabase :: open(const String &filename, std::ifstream& file){
    
    if (!doesItExist(filename)) {
        std::ofstream in(filename.getString());
        in.close();
        return NOTMATCH;
    }

    if (filename.substr(filename.length() - 4, filename.length() - 1) != ".txt") {
		return WRONGTYPE;
	}

    //std::ifstream file;
    file.open(filename.getString());

    if (!file) {
        return FAIL;
    }
    is_open = true;
    /*bool isEmptyFile = file.peek() == std::ifstream::traits_type::eof();
    if (isEmptyFile) {
        return EMPTYFILE;
    }*/
    String username, password;
    bool admin;
    char *buffer = new char[1000];

    while (!file.eof()) {
        User user;
        file.getline(buffer, '\n');
        user.setUsername(buffer);
        file.getline(buffer, '\n');
        user.setPassword(buffer);
        file.getline(buffer,'\n');
        String temp{buffer};
        admin = temp.toBool();
        user.setAdmin(admin);
        users.push_back(user);
    }
    delete[] buffer;
    file.close();
    return SUCCESS;
}

State UserDatabase :: close(std::ifstream& file) {
	if (is_open) {
		is_open = false;
		file.close();
	}
	else {
		return NOTOPEN;
	}
	return SUCCESS;
}