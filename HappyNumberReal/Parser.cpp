#include "Parser.hpp"
#include <iostream>
#include <ios>
#include <fstream>
#include <string>

Parser::Parser(std::istream& _input):input{ _input } {
	//input.open(file_name, ios::in);
	//if (!input.is_open())
		//throw std::out_of_range("Bad filename");
}

Parser::~Parser() {
}

int Parser::getNext() {
	std::string out;
	if (!(std::getline(input, out)))
		return -1;
	if (out == "")
		;
	int output = stoi(out);
	if (output <= 0) {
		throw std::invalid_argument("Invalid line: " + output);
	}
	return output;
	/*try {
	}������
	catch (std::exception& exc) {
		std::cerr << exc.what();
	}*/
}

//����� �� ����
//bool Parser::check_valid(int num) {
//
//}