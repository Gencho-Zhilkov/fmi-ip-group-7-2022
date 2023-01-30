#include <iostream>


bool isSubsequence(int *subs, size_t slen, int *arr, size_t len) {
	size_t j = 0;
	for(size_t i = 0; i < slen; i++) {
		for(; j < len; j++) {
			if (subs[i] == arr[j]) {
				break;
			}
		}
		if (j == len) {
			return false;
		}
	}
	return true;
}

int main() {
	int subs[] = {1, 2, 3};
	int arr1[] = {2, 3, 1, 2, 3, 5};
	int arr2[] = {2, 3, 1, 2, 5, 3};
	int arr3[] = {2, 3, 1, 2, 5, 2};

	std::cout << std::boolalpha;
	std::cout << isSubsequence(subs, 3, subs, 3) << std::endl;
	std::cout << isSubsequence(subs, 3, arr1, 6) << std::endl;
	std::cout << isSubsequence(subs, 3, arr2, 6) << std::endl;
	std::cout << isSubsequence(subs, 3, arr3, 6) << std::endl;

	return 0;
}
