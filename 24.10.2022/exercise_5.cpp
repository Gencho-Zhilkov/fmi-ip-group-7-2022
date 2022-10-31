#include <iostream>


int main() {
	int x;
	std::cin >> x;

	while (x > 1) {
		std::cout << x << ' ';

		if (x % 2 == 0) {
			x /= 2;
		} else {
			x = 3 * x + 1;
		}
	}

	if (x != 1) {
		std::cerr << "Collatz sequence ended with x = " << x << "!" << std::endl;
		return 1;
	}

	std::cout << x << std::endl;
	return 0;
}
