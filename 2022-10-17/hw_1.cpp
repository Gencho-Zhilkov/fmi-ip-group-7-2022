#include <iostream>

/*
1. Напишете програма, която прочита цяло число и отпечатва
дали десетичните му цифри са подредени в нарастващ ред.

_Примери:_
1234 -> true
1127 -> true
1244 -> true
1243 -> false
*/
bool incDigits(int n) {
	while (n != 0) {
		const int lastDigit = n % 10;
		const int prevDigit = (n / 10) % 10;
		if (lastDigit < prevDigit) {
			return false;
		}
		n /= 10;
	}
	return true;
}

int main() {
	std::cout << std::boolalpha;

	// Print out the examples
	for (int n : {1234, 1127, 1244, 1243}) {
		std::cout << n << " -> " << incDigits(n) << std::endl;
	}

	// Read a number and print the result
	int n;
	std::cin >> n;
	std::cout << incDigits(n) << std::endl;
	return 0;
}
