#include <iostream>
#include <iomanip>


bool isPrime(const unsigned int n) {
	if (n < 2) {
		return false;
	}
	for (unsigned int i = 2; i <= n / 2; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}


int main() {
	std::cout << std::boolalpha;
	for (unsigned int i = 0; i < 30; i++) {
		std::cout << std::setw(2) << i << std::setw(7) << isPrime(i) << std::endl;
	}

	return 0;
}
