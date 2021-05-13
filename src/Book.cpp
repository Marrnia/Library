#include "Book.hpp"

unsigned Book::unique_id = 0;

Book :: Book () : author{String()}, title{String()}, genre{String()}, description{String()} {
    year = 0;
    rating = 0.0;
    id = ++unique_id;
}