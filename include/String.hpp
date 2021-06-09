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
        const char* getString() const;
        const size_t length() const;

        // Operations
        String operator+(const String &) const;
        String operator+(const char *) const;
        String operator+(const char &) const;
        friend char* operator+(const char* lhs, const String& rhs) {
            char* result = nullptr;
            size_t s = String::strlen(lhs) + rhs.size;
            result = String::create(s + 1);
            strcpy_s(result, String::strlen(lhs) + 1, lhs);
            for (size_t i = strlen(lhs), j = 0; i < s && j < rhs.size; ++i, ++j) {
                result[i] = rhs.data[j];
            }
            result[s] = '\0';
            return result;
        }

        friend char* operator+(const char& lhs, const String& rhs) {
            char* result = nullptr;
            size_t s = 1 + rhs.size;
            result = String::create(s + 1);
            result[0] = lhs;
            for (size_t i = 1, j = 0; i < s && j < s-1; ++i, ++j) {
                result[i] = rhs.data[j];
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
        void toLower() noexcept;
        void toUpper() noexcept;
        void removeElement(const size_t&);
        void removeSpaces();

        //Search
        int find(const String&);
        int find(const char*);
        int find(const char&);
        size_t find(const char&, const size_t&, const size_t&) const;

        // IO
        friend std::ostream &operator<<(std::ostream &out, const String &object)
        {
            if (object.data != nullptr)
                out << object.data;
            else {
                out << "nullptr";
            }
            return out;
        }

        friend std::istream &operator>>(std::istream &in, String &object)
        {
            char *buffer = nullptr;
            try
            {
                buffer = new char[1000];
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            in.get(buffer, 1000);
            object = String{buffer};
            delete[] buffer;
            return in;
        }

    };
}