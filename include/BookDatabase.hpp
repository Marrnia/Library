#pragma once
#include "State.hpp"
#include "Vector.hpp"
#include "Book.hpp"
#include "String.hpp"
#include <fstream>
#include "Database.hpp"

class BookDatabase : public Database{
    private:
        Vector<Book> books;
        bool is_open;

    public:
    BookDatabase() {};

    //State add() override;
    //bool remove(const size_t&) override;

    State add(const bool&, const bool&);
    State remove(const String&, const bool&, const bool&);
 
    State viewBooks(const bool&) const;
    State viewInfo(const unsigned&, const bool&);
    
    void sortByYear(const String&);
    void sortByRating(const String&);
    void sortByTitle(const String&);
    void sortByAuthor(const String&);
    
    void searchByTitle(const String&);
    void searchByAuthor(const String&);
    void searchByByKeyword(const String&);

    State open(const String&, std::ifstream&);  
    State save(const String&);
    State close(std::ifstream&);

    /*void open(const String&);
    void openDB();    

    void save(const String&);*/
};