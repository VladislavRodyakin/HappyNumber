#pragma once
#include <vector>

class Checker {
public:
	Checker(int input) :original{ input } {
	}
	bool check_happines(int num);
private:
	int original;
	int calc_number(int num);
	//std::vector <int> checked; в функцию
};