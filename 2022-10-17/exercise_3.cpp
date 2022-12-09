#include <iostream>


int main() {
	int n;
	std::cin >> n;

	int sumDigits = 0;
	int pos = 0;
	while (n > 0) {
		const int lastDigit = n % 10;
		if (pos % 2 == 0 && lastDigit % 3 == 0) {
			sumDigits += lastDigit;
		}
		n /= 10;
		pos ++;
	}

	std::cout << sumDigits << std::endl;
	return 0;
}
