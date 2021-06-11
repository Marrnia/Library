#include "BookDatabase.hpp"

State BookDatabase :: save(const String &filename) {
    std::ofstream file;
    file.open(filename.getString(), std::ios::out);
    if (file.fail()) {
        return FAIL;
    }
    size_t size = books.getSize();
    for (size_t i = 0; i < size; ++i) {
        books[i].save(file);
        if (i < size - 1)
            file << '\n';
    }
    file.close();
    return SUCCESS;
}

State BookDatabase :: open(const String &filename, std::ifstream& file) {
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
    String title, author, genre, description, tags;
    unsigned year = 0;
    double rating = 0.0;
    char *buffer = new char[1000];

    while (!file.eof()) {
        Book book;
        file.clear();
        file.getline(buffer, 1000, '\n');
        book.setTitle(buffer);
        file.getline(buffer, 1000, '\n');
        book.setAuthor(buffer);
        file.getline(buffer, 1000, '\n');
        book.setGenre(buffer);
        file.getline(buffer, 1000, '\n');
        book.setDescription(buffer);
        file.getline(buffer, 1000, '\n');
        String temp{buffer};
        year = temp.toInt();
        book.setYear(year);
        file.getline(buffer, 1000, '\n');
        book.setKeyWordsFromString(buffer);
        file.getline(buffer, 1000, '\n');
        temp = buffer;
        rating = temp.toDouble();
        book.setRating(rating);
        books.push_back(book);
    }
    delete[] buffer;
    file.close();
    return SUCCESS;
}

State BookDatabase :: close(std::ifstream& file) {
	if (is_open) {
		is_open = false;
		file.close();
	}
	else {
		return NOTOPEN;
	}
	return SUCCESS;
}