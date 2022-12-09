#include <iostream>
#include <cassert>


void merge(int *xs, const size_t xlen, int *ys, const size_t ylen, int *res) {
	size_t i = 0, j = 0, k = 0;
	while (i < xlen && j < ylen) {
		if(xs[i] <= ys[j]) {
			res[k++] = xs[i++];
		} else {
			res[k++] = ys[j++];
		}
	}

	// Assert that we've exhausted one of the arrays!
	assert(i == xlen || j == ylen);

	// Copy the remaining elements.
	// N.B. Only one of the 2 loops will execute!
	for (size_t q = i; q < xlen; q++, k++) {
		res[k] = xs[q];
	}
	for (size_t q = j; q < ylen; q++, k++) {
		res[k] = ys[q];
	}

	// Assert that all elements have been copied into the result array!
	assert(k == xlen + ylen);
}

int main() {
	int xs[4] = {1, 2, 15, 27};
	int ys[3] = {8, 12, 25};
	int zs[7];

	merge(xs, 4, ys, 3, zs);
	for (size_t i = 0; i < 7; i++) {
		std::cout << zs[i] << ' ';
	}
	std::cout << std::endl;
	return 0;
}
