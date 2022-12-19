#include <iostream>


size_t findMissing(unsigned *xs, size_t n) {
	size_t res = n * (n + 1) / 2;
	for (size_t i = 0; i < n - 1; i++) {
		res -= xs[i];
	}
	return res;
}

int main() {
	unsigned xs[] = {2, 3, 1, 6, 5};
	std::cout << findMissing(xs, 6) << std::endl;

	return 0;
}
