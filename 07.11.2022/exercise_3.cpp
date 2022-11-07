#include <iostream>

void printCommonElements(const int * const array1, const size_t size1,
						 const int * const array2, const size_t size2) {
	for (size_t i = 0; i < size1; i++) {
		for(size_t j = 0; j < size2; j++) {
			if (array1[i] == array2[j]) {
				std::cout << "i = " << i << ", j = " << j << ", element = " << array1[i] << std::endl;
			}
		}
	}
}

int main() {
	const int arr1[] = {1, 2, 3, 4};
	const int arr2[] = {3, 7, 5, 1, 8, 2};

	printCommonElements(arr1, 4, arr2, 6);
	return 0;
}
