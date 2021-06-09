#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest.h"
#include "String.hpp"

using namespace library;

TEST_CASE("Constructors") {
    library::String s1("text");
    library::String s2(s1);
    String s3(s2);
    String s;
    String s4(100, 'a');
    std::cout << s4 << "\n";
    String s5(s4);
    CHECK(s1.length() == s2.length());
    CHECK(s2.length() == s3.length());
    std::cout << "Size of s: " << s.length() << "\n";
    CHECK(s4.length() == s5.length());
    String s6('a');
    CHECK(s6[0]=='a');
}

TEST_CASE("Assignment") {
    std::cout << "Assignment:\n";
    String s1("text");
    std::cout << s1 << std::endl;
    String s2 = s1;
    String s3 = 'a';
    CHECK(s1.length() == 4);
    CHECK(s2.length() == s1.length());
    CHECK(s3.length() == 1);
    std::cout << "s1: " << s1 << "\n";
    std::cout << "s2: " << s2 << "\n";
    std::cout << "s3: " << s3 << "\n";
}

TEST_CASE("operator[]") {
    String s = "text";
    const String s_const = "text";
    CHECK(s[0]=='t');
    CHECK(s[1]=='e');
    CHECK(s[2]=='x');
    CHECK(s[3]=='t');
    CHECK(s_const[0]=='t');
    CHECK(s_const[1]=='e');
    CHECK(s_const[2]=='x');
    CHECK(s_const[3]=='t');
    //s_const[0] = 'a';
}

TEST_CASE("Capacity") {
    String s;
    CHECK(s.empty() == true);
    s.setString("text");
    CHECK(s.empty() == false);
    CHECK(s.length() == 4);
}

TEST_CASE("Operations") {
    String s1("Martin");
    String s2("Jivkov");
    String s3;
    std::cout << "s1 + s2 = " << s1 + s2 << "\n";
    std::cout << "s2 + s1 = " << s2 + s1 << "\n";
    std::cout << "array + s1 = " << "text" + s1 << "\n";
    std::cout << "s1 + array = " << s1 + "text" << "\n";
    std::cout << "char + string = " << 'a' + s1 << "\n";
    std::cout << "string + char = " << s1 + 'a' << "\n";
    s3 += s1 + s2;
    std::cout << "Name: " << s3 << '\n';
    if (s1 != s2) {
        std::cout << "YES\n";
    }
    else std::cout << "NO\n";
    s1.clear();
    CHECK(s1.empty() == true);
    s2.insert('!', 3);
    CHECK(s2[3] == '!');
    std::cout << "s2 after insert: " << s2 << '\n';
    std::cout << "s1 and s2: " << s1 << " " << s2 <<  '\n';
    String::swap(s1,s2);
    std::cout << "s1 and s2 after swap: " << s1 << " " << s2 << '\n';
    s1 = "text";
    s2 = s1.substr(1,3);
    CHECK(s2[0] == 'e');
    CHECK(s2[1] == 'x');
    CHECK(s2[2] == 't');
    CHECK(s2.length() == 3);
}

TEST_CASE("Search") {
    String s("text");
    CHECK(s.find("ext") == 1);
    CHECK(s.find('a') == -1);
    CHECK(s.find('t') == 0);
    String s2 = "te";
    CHECK(s.find(s2) == 0);
}

TEST_CASE("Input && Output") {
    String s;
    std::cin >> s;
    std::cout << s << '\n';
}