#include <iostream>


unsigned pow(unsigned n, unsigned k) {
	unsigned res = 1;
	for (unsigned i = 0; i < k; i++) {
		res *= n;
	}
	return res;
}

unsigned sumDigits(unsigned n) {
	unsigned res = 0;
	while (n > 0) {
		res += n % 10;
		n /= 10;
	}
	return res;
}

unsigned prodDigits(unsigned n) {
	unsigned res = 1;
	do {
		res *= n % 10;
		n /= 10;
	} while (n > 0);
	return res;
}

int main() {
	std::cout << "Enter a number: ";
	unsigned n;
	std::cin >> n;
	if (n < 1) {
		std::cerr << "n must be >= 1!" << std::endl;
		return 1;
	}

	for (unsigned i = pow(10, n-1); i < pow(10, n); i++) {
		if (sumDigits(i) == prodDigits(i)) {
			std::cout << i << std::endl;
		}
	}
	return 0;
}
