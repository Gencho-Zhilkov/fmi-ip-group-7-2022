#include <iostream>


int sumDivisors(const int n) {
	int res = 0;
	for (int i = 1; i <= n / 2; i ++) {
		if (n % i == 0) {
			res += i;
		}
	}
	return res;
}

bool isPerfect(const int n) {
	return n == sumDivisors(n);
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i ++) {
		if (isPerfect(i)) {
			std::cout << i << std::endl;
		}
	}
	return 0;
}
