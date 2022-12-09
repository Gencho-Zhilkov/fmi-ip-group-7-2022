#include <iostream>
#include <cmath>

double sqrt(double x, double epsilon) {
	double xPrev, xN = x;
	do {
		xPrev = xN;
		xN = 0.5 * (xPrev + x / xPrev);
	} while (fabs(xN - xPrev) > epsilon);
	// } while (fabs(xN*xN - x) >= epsilon);
	return xN;
}


int main() {
	double x, epsilon = 1e-6;
	std::cin >> x;
	std::cout << sqrt(x, epsilon) << std::endl;
	return 0;
}
