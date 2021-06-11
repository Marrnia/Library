#include "BookDatabase.hpp"

void BookDatabase :: searchByTitle(const String &title) {
    size_t size = books.getSize();
    for (size_t i = 0; i < size && books[i].getTitle() == title; ++i) {
        books[i].print();
    }
}

void BookDatabase :: searchByAuthor(const String &author) {
    size_t size = books.getSize();
    for (size_t i = 0; i < size && books[i].getAuthor() == author; ++i) {
        books[i].print();
    }
}

void BookDatabase :: searchByByKeyword(const String &keyword) {
    size_t size = books.getSize();
    for (int i = 0; i < size && books[i].getKeywords().isExistName(keyword); ++i) {
        books[i].print();
    }
}