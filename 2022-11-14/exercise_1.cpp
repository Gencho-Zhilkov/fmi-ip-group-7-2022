#include <iostream>
#include <cmath>


bool isPrime(unsigned n) {
	for (unsigned i = 2; i <= std::sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}


int main() {
	std::cout << "Enter a number: ";
	unsigned n;
	std::cin >> n;

	for (unsigned i = 2; n > 1; i++) {
		if (isPrime(i)) {
			while (n % i == 0) {
				std::cout << i << ' ';
				n /= i;
			}
		}
	}

	std::cout << std::endl;
	return 0;
}
