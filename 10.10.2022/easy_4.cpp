#include <iostream>


int main() {
	std::cout << "Enter three numbers: ";

	double a, b, c;
	std::cin >> a >> b >> c;

	bool isValidTriangle = (a < b + c) && (b < a + c) && (c < a + b);
	if (isValidTriangle) {
		std::cout << "The three sides do form a valid triange." << std::endl;
	} else {
		std::cout << "The three sides do not form a valid triange." << std::endl;
	}

	return 0;
}
