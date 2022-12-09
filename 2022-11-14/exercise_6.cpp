#include <iostream>
#include <cmath>


bool isPrime(const unsigned n) {
	for (unsigned i = 2; i <= std::sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

bool isSpecial(const unsigned n) {
	for (unsigned mask = 10; mask < n; mask *= 10) {
		unsigned prefix = n / mask, suffix = n % mask;
		if (!(isPrime(prefix) && isPrime(suffix))) {
			return false;
		}
	}
	return isPrime(n);
}


int main() {
	for (unsigned i = 1000; i < 10000; i++) {
		if (isSpecial(i)) {
			std::cout << i << std::endl;
		}
	}
	return 0;
}
