#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include "String.hpp"
#include "State.hpp"

class CommandLine {
private:
	static library::String text;
	static bool is_open;
public:
	static State open(library::String&);
	static State save(library::String&);
	static State saveAs(library::String&);
	static void help();
	static State close();
    static void exit();
	static library::String getText();
	static void setText(const library::String&);
};
