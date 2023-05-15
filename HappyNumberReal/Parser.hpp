#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Parser {
public:
	//Parser(std::istream _input);
	Parser(std::istream& input);
	~Parser();
	int getNext();
private:
	std::istream& input;
	bool check_valid(int num);
};