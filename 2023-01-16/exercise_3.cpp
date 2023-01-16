#include <cassert>
#include <iostream>
#include <cmath>


bool isPrime_helper(const int n, int k, const int sqrtN) {
	assert(n >= 2);

	if (k > sqrtN) {
		return true;
	} else if (n % k == 0) {
		return false;
	} else {
		return isPrime_helper(n, k+1, sqrtN);
	}
}

bool isPrime(int n) {
	if (n < 2) {
		return false;
	} else {
		return isPrime_helper(n, 2, sqrt(n));
	}
}

int main() {
	for (int i = 0; i < 100; i++) {
		if (isPrime(i)) {
			std::cout << i << ' ';
		}
	}
	std::cout << std::endl;
	return 0;
}
