#include "Checker.hpp"
#include <string>
#include <set>

bool Checker::check_happines(int num) {
	std::set <int> checked;
	while (num != 1) {
		checked.insert(num);
		num = calc_number(num);
		if (std::find(checked.begin(), checked.end(), num) != checked.end())
			return false;
	}
	return true;
}

int Checker::calc_number(int num) {
	int result = 0;
	while (num > 0) {
		int tmp = (num % 10);
		result += tmp*tmp;
		num = num/10;
	}
	return result;
}