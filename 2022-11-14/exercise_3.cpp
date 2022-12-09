#include <iostream>


bool hasRepeatingDigits(unsigned n) {
	while (n > 9) {
		const unsigned d = n % 10;
		n /= 10;

		for (unsigned n1 = n; n1 > 0; n1 /= 10) {
			if (n1 % 10 == d) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	std::cout << std::boolalpha;
	for (unsigned n : {1234, 7395, 12235}) {
		std::cout << n << ' ' << hasRepeatingDigits(n) << std::endl;
	}
	return 0;
}
