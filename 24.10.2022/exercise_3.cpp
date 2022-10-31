#include <iostream>
#include <iomanip>


bool isPrime(const long long n) {
	if (n < 2) {
		return false;
	}
	for (long long i = 2; i <= n / 2; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int countDigits(long long n) {
	int res = 1;
	while (n > 10) {
		n /= 10;
		res ++;
	}
	return res;
}


int main() {
	int k;
	std::cin >> k;

	for (long long pow = 2; countDigits(pow - 1) <= k; pow *= 2) {
		if (pow < 0) {
			std::cerr << "Program exiting due to integer overflow: " << pow << std::endl;
			return 1;
		}

		const long long p = pow - 1;
		if (isPrime(p)) {
			std::cout << p << ' ';
		}
	}

	std::cout << std::endl;
	return 0;
}
