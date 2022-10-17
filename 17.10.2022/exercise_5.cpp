#include <iostream>

int main() {
	int a, b;
	std::cin >> a >> b;

	int a0 = a, b0 = b;
	bool res = false;
	while (a > 0) {
		const int aDigit = a % 10;
		const int bDigit = b % 10;

		if (aDigit == bDigit) {
			a /= 10;
			b /= 10;
			if (b == 0) {
				res = true;
				break;
			}
		} else {
			a0 /= 10;
			a = a0;
			b = b0;
		}
	}

	std::cout << res << std::endl;
	return 0;
}
