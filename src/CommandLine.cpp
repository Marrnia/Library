#include "CommandLine.hpp"

library::String CommandLine::text;
bool CommandLine::is_open;

void CommandLine :: exit() {
    std::cout << "Exiting the program...\n";
}

void CommandLine :: help() {
    std::cout << "The following command are supported:\n";
    std::cout << std::setw(40) << std::left << "open <file>" << std::setw(10) << std::left << "opens a file\n";
    std::cout << std::setw(40) << std::left << "close" << std::setw(10) << std::left << "closes currently opened file\n";
    std::cout << std::setw(40) << std::left << "save" << std::setw(10) << std::left << "saves the currently open file\n";
    std::cout << std::setw(40) << std::left << "saveas" << std::setw(10) << std::left << "saves the currently open file in <file>\n";
    std::cout << std::setw(40) << std::left << "help" << std::setw(10) << std::left << "prints this information\n";
    
    std::cout << std::setw(40) << std::left << "login" << std::setw(5) << std::left << "login\n";
    std::cout << std::setw(40) << std::left << "logout" << std::setw(5) << std::left << "logout\n";
    std::cout << std::setw(40) << std::left << "books all" << std::setw(10) << std::left << "info of the books\n";
    std::cout << std::setw(40) << std::left << "books info <isbn_value>" << std::setw(10) << std::left << "info of the specific book\n";
    std::cout << std::setw(40) << std::left << "books find <option> <option_string>" << std::setw(10) << std::left << "searching for a book\n";
    std::cout << std::setw(40) << std::left << "books sort <option> [asc | desc]" << std::setw(10) << std::left << "sorting the books in category\n";
    std::cout << std::setw(40) << std::left << "users add <user> <password>" << std::setw(10) << std::left << "adding new user with pass and name\n";
    std::cout << std::setw(40) << std::left << "user remove <user>" << std::setw(10) << std::left << "erase the specific user\n";
}

State CommandLine :: open(library::String& file_name) {
	if (is_open) {
		return OPENED;
	}
	std::ifstream in;
	char* buffer = nullptr;
	size_t size = 0;
	if (file_name.substr(file_name.length() - 4, file_name.length() - 1) != ".txt") {
		return WRONGTYPE;
	}
	in.open(file_name.getString());
	if (in) {
		in.seekg(0, std::ios::end);
		size = in.tellg();
		in.seekg(0, std::ios::beg);
		try {
			buffer = new char[size + 1];
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		in.read(buffer, size);
		buffer[size] = '\0';
		text = buffer;
	}
	else {
		return FAIL;
	}
	in.close();
	is_open = true;
	return SUCCESS;
}

State CommandLine :: close() {
	if (is_open) {
		text.~String();
		is_open = false;
	}
	else {
		return NOTOPEN;
	}
	return SUCCESS;
}

State CommandLine :: save(library::String& file_name) {
	if (!is_open) {
		return NOTOPEN;
	}
	std::ofstream out;
	out.open(file_name.getString());
	if (!out) {
		return FAIL;
	}
	out << text;
	out.close();
	return SUCCESS;
}

State CommandLine :: saveAs(library::String& file_name) {
	return save(file_name);
}

library::String CommandLine :: getText() {
	return text;
}

void CommandLine :: setText(const library::String& newText) {
	text = newText;
}