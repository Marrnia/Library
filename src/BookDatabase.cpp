#include "BookDatabase.hpp"

State BookDatabase :: add(const bool& logged, const bool& admin) {
    if (!logged) {
        return NOTLOGGED;
    }
    if (!admin) {
        return NOTADMIN;
    }
    Book book;
    String temp;
    unsigned year = 0;
    float rating = 0.0;
    std::cout << "Title: ";
    std::cin >> temp;
    if (temp.length() > 50) {
        std::cout << "Length of the title is too large!\n";
        return FAIL;
    }
    std::cout << "Author: ";
    std::cin >> temp;
    if (temp.length() > 40) {
        std::cout << "Length of the author is too large!\n";
        return FAIL;
    }
    book.setAuthor(temp);
    book.setTitle(temp);
    std::cout << "Genre: ";
    std::cin >> temp;
    if (temp.length() > 20) {
        std::cout << "Length of the genre is too large!\n";
        return FAIL;
    }
    book.setGenre(temp);
    std::cout << "Description: ";
    std::cin >> temp;
    if (temp.length() > 150) {
        std::cout << "Length of the description is too large!\n";
        return FAIL;
    }
    book.setDescription(temp);
    std::cout << "Year of publish: ";
    std::cin >> year;
    std::cin.ignore(100,'\n');
    if (year > 2021) {
        std::cout << "Invalid year!\n";
        return FAIL;
    }
    book.setYear(year);
    std::cout << "Keywords(with spaces): ";
    std::cin >> temp;
    book.setKeyWordsFromString(temp);
    std::cout << "Rating(1-5): ";
    std::cin >> rating;
    std::cin.ignore(100,'\n');
    if (rating < 1.0 || rating > 5.0) {
        std::cout << "The rating is not in the interval of 1 to 5!\n";
        return FAIL;
    }
    book.setRating(rating);
    books.push_back(book);
    return SUCCESS;
}

State BookDatabase :: remove(const String& title, const bool& logged, const bool& admin) {
    if (!logged) {
        return NOTLOGGED;
    }
    if (!admin) {
        return NOTADMIN;
    }
    for (size_t i = 0; i < books.getSize(); ++i) {
        if (books[i].getTitle() == title) {
            books.remove(i);
            return SUCCESS;
        }
    }
    return NOTMATCH;
}

State BookDatabase :: viewBooks(const bool& logged) const {
    if (logged == false) {
        return NOTLOGGED;
    }
    for (size_t i = 0; i < books.getSize(); ++i) {
        books[i].print();
    }
    return SUCCESS;
}

State BookDatabase :: viewInfo(const unsigned& id, const bool& logged) {
    if (!logged) {
        return NOTLOGGED;
    }
    for (size_t i = 0; i < books.getSize(); ++i) {
        if (books[i].getID() == id) {
            books[i].printDetail();
            return SUCCESS;
        }
    }
    return NOTMATCH;
}

