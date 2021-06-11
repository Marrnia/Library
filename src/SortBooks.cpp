#include "BookDatabase.hpp"


void BookDatabase :: sortByYear(const String& direct)
{
    size_t size = books.getSize();
    for (size_t i = 0; i < size - 1; ++i)

        for (size_t j = 0; j < size - i - 1; ++j)
        {
            unsigned elem1 = books[j].getYear();
            unsigned elem2 = books[j + 1].getYear();
            size_t k = j + 1;
            if (direct == "asc" && elem1 > elem2) {
                books.swap(books[j], books[k]);
            } else if(direct == "desc" && elem1 < elem2) {
                books.swap(books[j], books[k]);
            }
        }
}

void BookDatabase :: sortByRating(const String& direct)
{
    size_t size = books.getSize();
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - i - 1; ++j) {
            double elem1 = books[j].getRating();
            double elem2 = books[j + 1].getRating();
            size_t k = j + 1;
            if (direct == "asc" && elem1 > elem2) {
                books.swap(books[j], books[k]);
            } else if(direct == "desc" && elem1 < elem2) {
                books.swap(books[j], books[k]);
            }
        }
    }
}

void BookDatabase :: sortByTitle(const String& direct) {
    size_t size = books.getSize();
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - i - 1; ++j) {
            String elem1 = books[j].getTitle();
            String elem2 = books[j + 1].getTitle();
            size_t k = j + 1;
            if (direct == "asc" && elem1 > elem2) {
                books.swap(books[j], books[k]);
            }
            else if (direct == "desc" && elem1 < elem2) {
                books.swap(books[j], books[k]);
            }
        }
    }
}

void BookDatabase :: sortByAuthor(const String& direct) {
    size_t size = books.getSize();
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            String elem1 = books[j].getAuthor();
            String elem2 = books[j + 1].getAuthor();
            size_t k = j + 1;
            if (direct == "asc" && elem1 > elem2) {
                books.swap(books[j], books[k]);
            }
            else if (direct == "desc" && elem1 < elem2) {
                books.swap(books[j], books[k]);
            }
        }
    }
}