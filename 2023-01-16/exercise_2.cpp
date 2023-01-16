#include <iostream>

double avg(double xs[], size_t n) {
	if (n < 1) {
		throw "Average of empty array!";
	} else if (n == 1) {
		return xs[0];
	} else {
		return xs[n-1] / n + ((double)(n - 1)) / n * avg(xs, n - 1);
	}
}

int main() {
	double xs[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::cout << avg(xs, 10) << std::endl;

	return 0;
}
