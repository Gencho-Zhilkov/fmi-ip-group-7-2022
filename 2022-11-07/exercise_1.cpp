#include <iostream>

size_t hammingDistance(const int * const xs, const int * const ys, const size_t size) {
	size_t res = 0;
	for (size_t i = 0; i < size; i++) {
		if (xs[i] != ys[i]) {
			res ++;
		}
	}
	return res;
}

int main() {
	const int arr1[] = {1, 2, 3, 4};
	const int arr2[] = {1, 2, 2, 4};
	const int arr3[] = {1, 2, 4, 3};

	std::cout << hammingDistance(arr1, arr2, 4) << std::endl;
	std::cout << hammingDistance(arr1, arr3, 4) << std::endl;
	return 0;
}
