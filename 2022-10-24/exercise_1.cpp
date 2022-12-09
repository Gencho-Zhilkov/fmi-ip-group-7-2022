#include <iostream>


bool compareDates_v1(const int d1, const int m1, const int y1, const int d2, const int m2, const int y2) {
	/**
	 * Базово решение: Първо сравняваме годините. Ако те са равни,
	 * сравняваме месеците. Ако и те са равни, сравняваме дните от
	 * месеца.
	 */
	if (y1 < y2) {
		return true;
	} else if (y1 > y2) {
		return false;
	} else {
		if (m1 < m2) {
			return true;
		} else if (m2 > m1) {
			return false;
		} else {
			if (d1 < d2) {
				return true;
			} else {
				return false;
			}
		}
	}
}

bool compareDates_v2(const int d1, const int m1, const int y1, const int d2, const int m2, const int y2) {
	/**
	 *  По кратък и четим вариант на предното решение.
	 */
	if (y1 != y2) {
		return y1 < y2;
	} else if (m1 != m2) {
		return m1 < m2;
	} else {
		return d1 < d2;
	}
}

bool compareDates_v3(const int d1, const int m1, const int y1, const int d2, const int m2, const int y2) {
	/**
	 * Същото като предното, но записано като един единствен булев израз.
	 * Въпреки, че това решение е по-кратко от предното, според мен е и
	 * по-трудно за разбиране, а също и за дебъгване/евентуална бъдеща промяна.
	 */
	return (y1 < y2) || ((y1 == y2) && ((m1 < m2) || ((m1 == m2) && (d1 < d2))));
}

bool compareDates_v4(const int d1, const int m1, const int y1, const int d2, const int m2, const int y2) {
	/**
	 * Имплементация със само едно сравнение: Идеята е да запишем (кодираме)
	 * всяка дата в едно единствено число, като за целта запишем деня от месеца
	 * в последните 2 цифри, месеца в предните 2, и годината в най-предните цифри.
	 * Използваме `long long` (64 бита), за да намалим шанса от евентуален overflow.
	 */
	const long long x1 = 10000 * y1 + 100 * m1 + d1;
	const long long x2 = 10000 * y2 + 100 * m2 + d2;
	return x1 < x2;
}

bool compareDates_v5(const int d1, const int m1, const int y1, const int d2, const int m2, const int y2) {
	/**
	 * "Оптимизиран" вариант на предната функция: Идеята е да заменим умноженията
	 * със степени на десятката с умножения със степени на двойката, тъй като
	 * последните са "по-бързи" (могат да бъдат имплементирани посредствм right-shift).
	 *
	 * Тъй като дните в месеца са винаги от 1 до 31 имаме нужда от 5 бита
	 * за тях (* 32). За месеците (1-12) са ни достатъчни само 4 бита (* 16).
	 */
	const long long x1 = (16*32) * y1 + 32 * m1 + d1;
	const long long x2 = (16*32) * y2 + 32 * m2 + d2;
	return x1 < x2;
}


int main() {
	std::cout << std::boolalpha;
	std::cout << compareDates_v2(1, 1, 2000, 1, 1, 2000) << std::endl;

	std::cout << compareDates_v2(1, 1, 2000, 1, 1, 2001) << std::endl;
	std::cout << compareDates_v2(1, 1, 2000, 1, 2, 2000) << std::endl;
	std::cout << compareDates_v2(1, 1, 2000, 2, 1, 2000) << std::endl;

	std::cout << compareDates_v2(1, 1, 2001, 1, 1, 2000) << std::endl;
	std::cout << compareDates_v2(1, 2, 2000, 1, 1, 2000) << std::endl;
	std::cout << compareDates_v2(2, 1, 2000, 1, 1, 2000) << std::endl;
	return 0;
}
