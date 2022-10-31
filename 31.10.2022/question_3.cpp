#include <iostream>
#include <iomanip>
#include <bitset>


int main() {

	const double x = 1.e16;;
	const double y = x + 1;
	std::cout << std::boolalpha << (x == y) << std::endl;

	std::cout << std::setprecision(1000);
	std::cout << 1e-310 << std::endl;
	std::cout << (y - x) << std::endl;

	std::cout << std::bitset<64>(x) << std::endl;
	std::cout << std::bitset<64>(y) << std::endl;

	return 0;
}
