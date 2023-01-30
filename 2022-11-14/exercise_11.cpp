#include <cassert>
#include <iostream>

template <typename T>
void printArray(const T* const xs, const size_t size) {
	for (size_t i = 0; i < size; i++) {
		std::cout << xs[i] << ' ';
	}
	std::cout << std::endl;
}

size_t partition(int *arr, size_t len, int pivot) {
	size_t k = 0;
	for(size_t i = 0; i < len; i++) {
		assert(k <= i);
		if (arr[i] <= pivot) {
			if (k < i) {
				std::swap(arr[k], arr[i]);
			}
			k++;
		}
	}
	return k;
}

int main() {
	int arr1[] = {2, 3, 1, 2, 5, 3};
	int arr2[] = {2, 3, 1, 2, 5, 3};
	int arr3[] = {2, 3, 1, 2, 5, 3};

	printArray(arr1, 6);
	std::cout << partition(arr1, 6, 1) << std::endl;
	printArray(arr1, 6);
	std::cout << partition(arr2, 6, 2) << std::endl;
	printArray(arr2, 6);
	std::cout << partition(arr3, 6, 3) << std::endl;
	printArray(arr3, 6);

	return 0;
}
