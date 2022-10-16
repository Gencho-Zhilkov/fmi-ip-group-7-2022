#include <iostream>

void printBinary(int n) {
	if (n != 0) {
		printBinary(n / 2);
		std::cout << n % 2;
	}
}

int main() {
	std::cout << "Enter number: ";
	int n;
	std::cin >> n;

	if (n == 0) {
		std::cout << 0;
	} else {
		printBinary(n);
	}

	std::cout << std::endl;
	return 0;
}
