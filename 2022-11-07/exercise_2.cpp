#include <iostream>

int countDigit(int number, const int digit) {
	// Handle negative numbers
	number = abs(number);

	int res = 0;
	do {
		const int lastDigit = number % 10;
		res += (lastDigit == digit);
		number /= 10;
	} while(number > 0);
	return res;
}

int countDigit(const int * const numbers, const size_t size, const int digit) {
	int res = 0;
	for (size_t i = 0; i < size; i++) {
		res += countDigit(numbers[i], digit);
	}
	return res;
}

int main() {
	const int numbers[] = {1, 2, -333, 7};
	std::cout << countDigit(numbers, 4, 1) << std::endl;
	std::cout << countDigit(numbers, 4, 3) << std::endl;
	return 0;
}
