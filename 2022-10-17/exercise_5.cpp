#include <iostream>


bool isSuffix(int a, int b) {
	do {
		const int aDigit = a % 10;
		const int bDigit = b % 10;
		if (aDigit != bDigit) {
			return false;
		}
		a /= 10;
		b /= 10;
	} while (b > 0);

	return true;
}

int main() {
	int a, b;
	std::cin >> a >> b;

	bool found = false;
	while (a > 0) {
		found = isSuffix(a, b);
		if (found) {
			break;
		}
		a /= 10;
	}

	std::cout << std::boolalpha << found << std::endl;
	return 0;
}
