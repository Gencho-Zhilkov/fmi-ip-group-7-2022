#include <iostream>
#include <cmath>
#include <cassert>


// Helper functions.
bool isSign(const char c) {
	return c == '+' || c == '-';
}

bool isDigit(const char c) {
	return '0' <= c && c <= '9';
}

int toDigit(const char c) {
	assert(isDigit(c));
	return c - '0';
}

// Clear all symbols until we reach the start of a number.
const char *lstrip(const char *str) {
	while (*str != '\0') {
		if (isDigit(str[0]) || (isSign(str[0]) && isDigit(str[1]))) {
			break;
		}
		str ++;
	}
	return str;
}

// Parse the floating point number starting from str[0]
// and store the resuls in res.
// Return a pointer to the first char after the number.
const char *parseFraction(const char *str, double &res) {
	double mask = 0.1;
	while (isDigit(*str)) {
		res += toDigit(*str) * mask;
		str ++;
		mask /= 10;
	}
	return str;
}

const char *parseNumber(const char *str, double &res) {
	assert(isDigit(str[0]) || (isSign(str[0]) && isDigit(str[1])));

	bool negative = false;
	if (isSign(str[0])) {
		negative = str[0] == '-';
		str ++;
	}

	double f = 0;
	while (*str != '\0') {
		if (*str == '.') {
			str = parseFraction(str+1, f);
			break;
		} else if (isDigit(*str)) {
			f = 10 * f + toDigit(*str);
			str ++;
		} else {
			break;
		}
	}

	if(negative) {
		f = -f;
	}
	res = f;
	return str;
}

double findMaxNumber(const char *str) {
	double max = -INFINITY;

	while (*str != '\0') {
		str = lstrip(str);
		if (*str == '\0') {
			break;
		}

		double num;
		str = parseNumber(str, num);
		if (num > max) {
			max = num;
		}
	}

	return max;
}

int main() {
	std::cout << findMaxNumber("Lorem ipsum dolor sit amet") << std::endl;
	std::cout << findMaxNumber("Alexander was born in 336 BC and died at the age of 32.") << std::endl;
	std::cout << findMaxNumber("The Earth is 4.5 billon years old.") << std::endl;
	std::cout << findMaxNumber("-3 is larger than -7.6.") << std::endl;
	return 0;
}
