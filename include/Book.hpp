#pragma once
#include <iostream>
#include "String.hpp"

using namespace library;

class Book {
private:
    String author;
    String title;
    String genre;
    String description;
    unsigned year;
    float rating;
    static unsigned unique_id;
    unsigned id;
public:
    Book();
    Book(const String&, const String&,
        const String&, const String&,
        const unsigned&, const float&);
    Book(const Book&);
    Book& operator=(const Book&);

    void setAuthor(const String&);
    void setTitle(const String&);
    void setGenre(const String&);
    void setDescription(const String&);
    void setYear(const unsigned&);
    void setRating(const float&);

    String getAuthor() const;
    String getTitle() const;
    String getGenre() const;
    String getDescription() const;
    unsigned getYear() const;
    float getRating() const;
};

