#include <iostream>


int pow_simple(int n, int k) {
	int res = 1;
	for (int i = 0; i < k; i ++) {
		res *= n;
	}
	return res;
}

int pow_fast(int n, int k) {
	int res = 1;
	int pow = n;
	while (k > 0) {
		if (k % 2 != 0) {
			res *= pow;
		}
		k /= 2;
		pow *= pow;
	}
	return res;
}


int main() {
	int n, k;
	std::cin >> n >> k;
	std::cout << pow_simple(n, k) << std::endl;
	std::cout << pow_fast(n, k) << std::endl;
	return 0;
}
