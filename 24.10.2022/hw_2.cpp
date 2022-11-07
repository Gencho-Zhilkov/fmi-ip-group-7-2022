#include <exception>
#include <iostream>


bool isLeapYear(const int year) {
	return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

int daysInMonth(const int month, const int year) {
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		return 31;
	} else if (month == 2) {
		return isLeapYear(year)? 29 : 28;
	} else {
		return 30;
	}
}

void validateDate(const int day, const int month, const int year) {
	if (month < 1 || month > 12) {
		throw std::out_of_range("Invalid month!");
	}

	if (day < 1 || day > daysInMonth(month, year)) {
		throw std::out_of_range("Invalid day of month!");
	}
}

int daysInYear(const int year) {
	return isLeapYear(year)? 366 : 365;
}

int dayOfYear(const int day, const int month, const int year) {
	validateDate(day, month, year);

	int res = day;
	for (int currentMonth = 1; currentMonth < month; currentMonth ++) {
		res += daysInMonth(currentMonth, year);
	}
	return res;
}

int daysBetween(const int day1, const int month1, const int year1,
				const int day2, const int month2, const int year2) {
	int res = dayOfYear(day2, month2, year2) - dayOfYear(day1, month1, year1);
	for (int year = year1; year < year2; year ++) {
		res += daysInYear(year);
	}
	return res;
}


int main() {
	try {
		int day1, month1, year1;
		std::cout << "Enter start date: ";
		std::cin >> day1 >> month1 >> year1;

		int day2, month2, year2;
		std::cout << "Enter end date: ";
		std::cin >> day2 >> month2 >> year2;

		std::cout << daysBetween(day1, month1, year1, day2, month2, year2) << std::endl;

		return 0;
	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
}
