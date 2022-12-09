#include <iostream>


int main() {
	const double PI = 3.14;
	std::cout << "Enter circle radius: ";

	double r;
	std::cin >> r;

	double perimeter = 2 * PI * r;
	std::cout << "Perimeter:" << perimeter << std::endl;

	double area = PI * r * r;
	std::cout << "Area:" << area << std::endl;

	return 0;
}
