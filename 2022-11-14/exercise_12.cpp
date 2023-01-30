#include <cassert>
#include <iostream>

template <typename T>
void printArray(const T* const xs, const size_t size) {
	for (size_t i = 0; i < size; i++) {
		std::cout << xs[i] << ' ';
	}
	std::cout << std::endl;
}

bool find(int x, int *xs, size_t len) {
	for(size_t i = 0; i < len; i++) {
		if (xs[i] == x) {
			return true;
		}
	}
	return false;
}

size_t dedup(int *arr, size_t len) {
	size_t k = 0;
	for(size_t i = 0; i < len; i++) {
		assert(k <= i);
		if (!find(arr[i], arr, k)) {
			if (k < i) {
				std::swap(arr[k], arr[i]);
			}
			k++;
		}
	}
	return k;
}

int main() {
	int arr1[] = {1, 2, 3, 4, 5, 6};
	int arr2[] = {2, 3, 1, 2, 5, 3};
	int arr3[] = {2, 3, 3, 2, 5, 3};
	int arr4[] = {3, 3, 3, 2, 5, 3};

	std::cout << dedup(arr1, 6) << std::endl;
	printArray(arr1, 6);
	std::cout << dedup(arr2, 6) << std::endl;
	printArray(arr2, 6);
	std::cout << dedup(arr3, 6) << std::endl;
	printArray(arr3, 6);
	std::cout << dedup(arr4, 6) << std::endl;
	printArray(arr4, 6);

	return 0;
}
