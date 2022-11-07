#include <cmath>
#include <exception>
#include <iostream>


double norm(const double x, const double y) {
	return std::sqrt(x * x + y * y);
}

// 1. Напишете функция, която пресмята разстоянието между две точки в равнината.
double pointDistance(const double x1, const double y1, const double x2, const double y2) {
	return norm(x2 - x1, y2 - y1);
}

// 2. Напишете функция, която пресмята разстоянието от точка до окръжност (център + радиус).
double circleDistance(const double xC, const double yC, const double r, const double x, const double y) {
	return pointDistance(xC, yC, x, y) - r;
}

// 3. Напишете функция, която пресмята скаларното произведенение на два двуизмерни вектора.
double dotProduct(const double x1, const double y1, const double x2, const double y2) {
	return x1 * x2 + y1 * y2;
}

// 4. Напишете функция, която пресмята ъгъла между два двуизмерни вектора.
double angle(const double x1, const double y1, const double x2, const double y2) {
	const double l1 = norm(x1, y1);
	const double l2 = norm(x2, y2);
	if (l1 == 0 || l2 == 0) {
		throw std::underflow_error("Zero-length vector!");
	}
	const double cos =  dotProduct(x1, y1, x2, y2) / (l1 * l2);
	return std::acos(cos);
}

// 5. Напишете функция, която пресмята лицето на тригълник по три точки.
double heronArea(const double a, const double b, const double c) {
	// Calculate semi-perimeter:
	const double s = (a + b + c) / 2;
	if (s < 0 || s < a || s < b || s < c) {
		throw std::invalid_argument("Invalid triangle!");
	}
	return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

double triangleArea(const double x1, const double y1,
					const double x2, const double y2,
					const double x3, const double y3) {
	const double d12 = pointDistance(x1, y1, x2, y2);
	const double d13 = pointDistance(x1, y1, x3, y3);
	const double d23 = pointDistance(x2, y2, x3, y3);
	return heronArea(d12, d13, d23);
}

int main() {
	const double x1 = 1, y1 = 0, x2 = 0, y2 = 1, x3 = 1, y3 = 1;
	std::cout << pointDistance(x1, y1, x2, y2) << std::endl;
	std::cout << pointDistance(x1, y1, x3, y3) << std::endl;

	std::cout << circleDistance(0, 0, 1, x1, y1) << std::endl;
	std::cout << circleDistance(0, 0, 1, x3, y3) << std::endl;

	std::cout << dotProduct(x1, y1, x2, y2) << std::endl;
	std::cout << dotProduct(x1, y1, x3, y3) << std::endl;

	std::cout << 2 * angle(x1, y1, x2, y2) << std::endl;
	std::cout << 4 * angle(x1, y1, x3, y3) << std::endl;

	std::cout << triangleArea(x1, y1, x2, y2, x3, y3) << std::endl;
	return 0;
}
