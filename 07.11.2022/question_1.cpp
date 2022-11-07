#include <iostream>


int main() {
	std::cout << std::boolalpha;

	int i = 42;
	int *m = &i;

	std::cout << (m == &m[0]) << std::endl;
	std::cout << (m + 5 == &m[5]) << std::endl;
	std::cout << *m << ' ' << m[0] << std::endl;
	std::cout << *(m + 5) << ' ' << m[5] << std::endl;

	return 0;
}
