#include "Book.hpp"

unsigned Book::unique_id = 0;

Book :: Book () : author{String()}, title{String()}, genre{String()}, description{String()}, keywords{Vector<String>()} {
    year = 0;
    rating = 0.0;
    id = ++unique_id;
}

Book :: Book(const String& author, const String& title, const String& genre, const String& description, const unsigned& year, const Vector<String>& keywords, const float& rating)
: author(author), title(title), genre(genre), description(description), year(year), keywords(keywords), rating(rating) {
    id = ++unique_id;
}

Book :: Book(const Book& other) :
author(other.author), title(other.title), genre(other.genre), description(other.description), year(other.year), keywords(other.keywords), rating(other.rating) {
    id = ++unique_id;
}

Book& Book :: operator=(const Book& other) {
    this->author = other.author;
    this->title = other.title;
    this->genre = other.genre;
    this->description = other.description;
    this->year = other.year;
    this->keywords = other.keywords;
    this->rating = other.rating;
    return *this;
}

void Book :: setAuthor(const String& author) {
    this->author = author;
}

void Book :: setTitle(const String& title) {
    this->title = title;
}

void Book :: setGenre(const String& genre) {
    this->genre = genre;
}

void Book :: setDescription(const String& des) {
    this->description = des;
}

void Book :: setYear(const unsigned& year) {
    this->year = year;
}

void Book :: setKeywords(const Vector<String>& keywords) {
    this->keywords = keywords;
}

void Book::setKeyWordsFromString(const String& tags) {
    VectorString::splitIntoWords(tags, keywords);
}

void Book :: setRating(const float& rating) {
    this->rating = rating;
}

const String Book :: getAuthor() const {
    return author;
}

const String Book :: getTitle() const {
    return title;
}

const String Book :: getGenre() const {
    return genre;
}

const String Book :: getDescription() const {
    return description;
}

const unsigned Book ::  getYear() const {
    return year;
}

const Vector<String>& Book :: getKeywords() const {
    return this->keywords;
}

const float Book :: getRating() const {
    return rating;
}

const unsigned Book :: getID() const {
    return id;
}

void Book :: save(std::ofstream& file) const {
    file << this->title << '\n';
    file << this->author << '\n';
    file << this->genre << '\n';
    file << this->description << '\n';
    file << this->year << '\n';
    for(int i = 0; i < this->keywords.getSize();++i) {
        file << this->keywords[i] << " ";
    }
    file << '\n';
    file << this->rating << '\n';
}

void Book :: print() const {
    std::cout << "Title: " << this->title << '\n';
    std::cout << "Author: " << this->author << '\n';
    std::cout << "Genre:  " << this->genre << '\n';
    std::cout << "ID: " << this->id << '\n';
}

void Book :: printDetail() const {
    std::cout << "Title: " << this->title;
    std::cout << "Author: " << this->author;
    std::cout << "Genre:  " << this->genre;
    std::cout << "Description: " << this->description;
    std::cout << "Keywords: ";
    this->keywords.print();
    std::cout << "Year: " << this->year;
    std::cout << "Rating: " << this->rating;
    std::cout << "ID: " << this->id;
    }