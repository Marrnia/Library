#pragma once
#include <iostream>
#include <fstream>
#include "String.hpp"
#include "Vector.hpp"
#include "vector_strings.hpp"

using namespace library;

class Book {
private:
    String author;
    String title;
    String genre;
    String description;
    unsigned year;
    Vector<String> keywords;
    float rating;
    static unsigned unique_id;
    unsigned id;
public:
    Book();
    Book(const String&, const String&,
        const String&, const String&,
        const unsigned&, const Vector<String>&, const float&);
    Book(const Book&);

    Book& operator=(const Book&);

    void setAuthor(const String&);
    void setTitle(const String&);
    void setGenre(const String&);
    void setDescription(const String&);
    void setYear(const unsigned&);
    void setKeywords(const Vector<String>&);
    void setKeyWordsFromString(const String&);
    void setRating(const float&);

    const String getAuthor() const;
    const String getTitle() const;
    const String getGenre() const;
    const String getDescription() const;
    const unsigned getYear() const;
    const Vector<String>& getKeywords() const;
    const float getRating() const;
    const unsigned getID() const;

    void save(std::ofstream&) const; 
    void open(const std::fstream&);

    void print() const;
    void printDetail() const;
};

