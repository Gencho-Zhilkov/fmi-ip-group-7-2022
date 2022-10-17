#include <iostream>


int main() {
	int n;
	std::cin >> n;

	int maxDigit = -1;
	while (n > 0) {
		const int lastDigit = n % 10;
		if (lastDigit > maxDigit) {
			maxDigit = lastDigit;
		}
		n /= 10;
	}

	std::cout << maxDigit << std::endl;
	return 0;
}
