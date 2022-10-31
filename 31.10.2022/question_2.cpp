#include <iostream>
#include <iomanip>


int main() {
	const double x = 1.5e7*3+1;
	std::cout << x << std::endl;
	std::cout << std::setprecision(10) << x << std::endl;

	return 0;
}
