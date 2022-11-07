#include <cmath>
#include <iostream>


double f(const double x) {
	return std::pow(x, 2) * std::exp(-x) * std::sin(x);
}

int main() {
	double xMin, xMax;
	int n;
	std::cin >> xMin >> xMax >> n;

	const double deltaX = (xMax - xMin) / n;

	double res = 0, x = xMin;
	for (int i = 0; i < n; i ++, x += deltaX) {
		res += f(x);
	}
	res *= deltaX;

	std::cout << res << std::endl;
	return 0;
}
