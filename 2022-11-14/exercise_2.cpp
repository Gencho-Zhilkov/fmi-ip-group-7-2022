#include <iostream>


unsigned countDigits(unsigned n) {
	unsigned res = 1;
	while (n > 9) {
		n /= 10;
		res++;
	}
	return res;
}

unsigned pow(unsigned n, unsigned k) {
	unsigned res = 1;
	for (unsigned i = 0; i < k; i++) {
		res *= n;
	}
	return res;
}

bool isCyclical(const unsigned n) {
	const unsigned c = countDigits(n) - 1;
	const unsigned p = pow(10, c);
	unsigned rot = n;

	for (unsigned i = 0; i < c; i++) {
		rot =  p * (rot % 10) + (rot / 10);
		if (rot == n) {
			return true;
		}
	}
	return false;
}


int main() {
	std::cout << std::boolalpha;
	std::cout << isCyclical(123123) << std::endl;
	std::cout << isCyclical(1231235) << std::endl;
	return 0;
}
