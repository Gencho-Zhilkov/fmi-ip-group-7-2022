#include <iostream>
#include <cassert>


size_t countIncreasing(const int * const xs, const size_t len) {
	for (size_t i = 1; i < len; i++) {
		if(xs[i] <= xs[i-1]) {
			return i;
		}
	}
	return len;
}

size_t longestIncreasing(const int *xs, size_t len) {
	size_t maxLen = 0;
	while (len > 0) {
		const size_t subLen = countIncreasing(xs, len);
		if (subLen > maxLen) {
			maxLen = subLen;
		}
		xs += subLen;
		len -= subLen;
	}
	return maxLen;
}

int main() {
	int xs[] = {1, 2, 3, 2, 3, 5, 7, 2, 5, 5, 6, 3};
	const size_t xlen = sizeof(xs) / sizeof(xs[0]);

	std::cout << longestIncreasing(xs, xlen) << std::endl;
	return 0;
}
