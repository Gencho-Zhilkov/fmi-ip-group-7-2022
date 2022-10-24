#include <iostream>


int main() {
	int n;
	std::cin >> n;

	int sumDigits = 0;
	while (n > 0) {
		const int lastDigit = n % 10;
		sumDigits += lastDigit;
		n /= 10;
	}

	std::cout << sumDigits << std::endl;
	return 0;
}
