#include <iostream>
#include "Vector.hpp"
#include "String.hpp"

class VectorString {
public:
    static void splitIntoWords(library::String sentence, library::Vector<library::String>& words) {
        size_t to = 0;
        size_t from = 0;
        bool first = true;
        int counter = 0;
		while (to < sentence.length()) {
            ++counter;
            to = sentence.find(' ', to+1, sentence.length());
            if (to > sentence.length() && first) {
                words.push_back(sentence);
                return;
            }
            if (to > sentence.length()) {
                words.push_back(sentence.substr(from+1,sentence.length()-1));
                return;
            }
            if (first) {
                words.push_back(sentence.substr(from,to-1));
            }
            else {
                words.push_back(sentence.substr(from+1,to-1));
            }
            from = to;
            first = false;
            if (counter == 3) {
                if ((words[0] == "books" && words[1] == "find" && words[2] == "title") || (words[0] == "books" && words[1] == "find" && words[2] == "author")) {
                    words.push_back(sentence.substr(from+1,sentence.length()));
                    break;
                }
            }
		}
    }

};