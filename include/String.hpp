#pragma once
#include <iostream>

namespace library {
    class String {
    private:
        size_t size = 0;
        char* data = nullptr;

        static size_t strlen(const char*);
        static char* create(const size_t&);
        void copy_string(const char*);
        void copy_element(const char&);
        void erase();
    public:
        String(); // Default constructor
        String(const char&); // char constructor
        String(const char *); // array char constructor
        String(const size_t &, const char &); // Fill constructor
        String(const String &); // Copy constructor
        ~String(); // Destructor

        // Assign
        String &operator=(const String &);
        String &operator=(const char *);
        String &operator=(const char &);

        // Element access
        const char &operator[](const size_t &) const;
        char &operator[](const size_t &);

        // Capacity
        bool empty() const;
        void setString(const char *);
        size_t length() const;

        // Operations
        String operator+(const String &) const;
        String operator+(const char *) const;
        String operator+(const char &) const;
        friend char* operator+(const char* lhs, const String& rhs) {
            char* result = nullptr;
            size_t s = String::strlen(lhs) + rhs.size;
            result = String::create(s + 1);
            strcpy_s(result, String::strlen(lhs) + 1, lhs);
            for (size_t i = strlen(lhs); i < s; ++i) {
                result[i] = rhs.data[i];
            }
            result[s] = '\0';
            return result;
        }
        friend char* operator+(const char& lhs, const String& rhs) {
            char* result = nullptr;
            size_t s = 1 + rhs.size;
            result = String::create(s + 1);
            result[0] = lhs;
            for (size_t i = 1; i < s; ++i) {
                result[i] = rhs.data[i];
            }
            result[s] = '\0';
            return result;
        }
        String& operator+=(const String &);
        String& operator+=(const char *);
        String& operator+=(const char &);
        bool operator==(const String &) const;
        bool operator==(const char *) const;
        bool operator==(const char&) const;
        friend bool operator==(const char* lhs, const String& rhs) {
            if (strlen(lhs) != rhs.size) {
                return false;
            }
            for (size_t i = 0; i < rhs.size; ++i) {
                if (lhs[i] != rhs.data[i]) {
                    return false;
                }
            }
            return true;
        }
        friend bool operator==(const char& lhs, const String& rhs) {
            if (rhs.size != 1) {
                return false;
            }
            if (rhs.data[0] != lhs) {
                return false;
            }
            return true;
        }
        bool operator!=(const String &) const;
        bool operator!=(const char *) const;
        bool operator!=(const char &) const;
        friend bool operator!=(const char* lhs, const String& rhs) {
            return !(lhs == rhs);
        }
        friend bool operator!=(const char& lhs, const String& rhs) {
            return !(lhs == rhs);
        }
        void clear();
        void insert(const char&, const size_t&);
        static void swap(String&, String&);
        String substr(const size_t&, const size_t&) const; // from, to

        //Search
        size_t find(const String&);
        size_t find(const char*);
        size_t find(const char&);

        // IO
        friend std::ostream &operator<<(std::ostream &out, const String &object)
        {
            out << object.data;
            return out;
        }

        friend std::istream &operator>>(std::istream &in, String &object)
        {
            char *buffer = new char[1000];
            in >> buffer;
            object = String{buffer};
            delete[] buffer;
            return in;
        }

    };
}