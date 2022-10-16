#include <iostream>

int countBinaryDigits(int n) {
	int res = 0;
	while (n != 0) {
		res ++;
		n /= 2;
	}
	return res;
}

int main() {
	std::cout << "Enter number: ";
	int n;
	std::cin >> n;

	if (n == 0) {
		std::cout << 0;
	} else {
		int count = countBinaryDigits(n);
		for (int i = count-1; i >= 0; i --) {
			// Same as digit = (n / (2 ** i)) % 2;
			int digit = (n >> i) & 0x1;
			std::cout << digit;
		}
	}

	std::cout << std::endl;
	return 0;
}
