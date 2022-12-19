#include <iostream>


bool twoSum(const int * const xs, const size_t len, const int s) {
	for (size_t i = 0; i < len; i ++) {
		const int temp = s - xs[i];
		for (size_t j = i + 1; j < len; j ++) {
			if (xs[j] == temp) {
				return true;
			}
		}
	}
	return false;
}


bool twoSumSorted(const int * const xs, const size_t len, const int s) {
	size_t left = 0, right = len - 1;
	while(left < right) {
		const int temp = xs[left] + xs[right];
		if (temp < s) {
			left ++;
		} else if (temp > s) {
			right --;
		} else {
			return true;
		}
	}
	return false;
}

int main() {
	int xs[] = {1, 3, 4, 7, 12, 21};
	std::cout << std::boolalpha;
	std::cout << twoSum(xs, 6, 19) << std::endl;
	std::cout << twoSum(xs, 6, 71) << std::endl;
	std::cout << twoSum(xs, 6, 32) << std::endl;
	std::cout << std::endl;
	std::cout << twoSumSorted(xs, 6, 19) << std::endl;
	std::cout << twoSumSorted(xs, 6, 71) << std::endl;
	std::cout << twoSumSorted(xs, 6, 32) << std::endl;
	return 0;
}
