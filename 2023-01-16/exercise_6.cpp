// N.B. This is a **very** inefficient (epxonential!) algorithm.
// Do not test with n > ~20, unless you want to wait forever!
//
// More efficient implementations use the same principle as this one but
// employ dynamic programming techniques to vastly improve the runtime.
#include <iostream>
#include <cassert>
#include <cstring>


// We assume used is set to all `false` in the begining!
unsigned knapsack(unsigned weights[], bool used[], size_t n, unsigned capacity) {
	if(n == 0 || capacity == 0) { // no more objects or no more space
		return 0;
	}

	// Optimal solution w.o. using `weights[n-1]`
	const unsigned x0 = knapsack(weights, used, n - 1, capacity);
	const unsigned wn = weights[n - 1];

	if (wn <= capacity) {
		// If there's enough space for last item, try using it
		// and see if this does not lead to a better solution.
		bool *temp = new bool[n-1]();
		unsigned x1 = wn + knapsack(weights, temp, n - 1, capacity - wn);
		if (x1 > x0) {
			memcpy(used, temp, (n - 1) * sizeof(bool));
			used[n - 1] = true;
			return x1;
		}
	}

	return x0;
}

int main() {
	size_t n;
	std::cout << "Enter number of items: ";
	std::cin >> n;
	if (n > 20) {
		std::cerr << "More than 20 items: program may take a long time to finish!" << std::endl;
	}

	unsigned *weights = new unsigned[n];
	std::cout << "Enter item weights: ";
	for (size_t i = 0; i < n; i++) {
		std::cin >> weights[i];
	}

	unsigned capacity;
	std::cout << "Enter knapsack capacity: ";
	std::cin >> capacity;

	bool *used = new bool[n]();
	unsigned w = knapsack(weights, used, n, capacity);

	std::cout << "Max weight: " << w << std::endl;
	std::cout << "Items used: ";
	for (size_t i = 0; i < n; i++) {
		if (used[i]) {
			std::cout << "[" << i << "]=" << weights[i] << " ";
		}
	}
	std::cout << std::endl;

	return 0;
}
