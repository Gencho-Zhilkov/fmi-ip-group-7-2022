#include <iostream>


bool isLeapYear(int year) {
	return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

int daysInYear(int year) {
	return isLeapYear(year) ? 366: 365;
}

int daysInMonth(int month, int year) {
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		return 31;
	} else if (month == 2) {
		if (isLeapYear(year)) {
			return 29;
		} else {
			return 28;
		}
	} else {
		return 30;
	}
}


int main() {
	int year;
	std::cout << "Enter year: ";
	std::cin >> year;

	int dayOfYear;
	std::cout << "Enter day of the year: ";
	std::cin >> dayOfYear;

	if (dayOfYear < 1 || dayOfYear > daysInYear(year)) {
		std::cerr << "Invalid day of the year: " << dayOfYear << std::endl;
		return 1;
	}

	int month = 1;
	while (dayOfYear > daysInMonth(month, year)) {
		dayOfYear -= daysInMonth(month, year);
		month += 1;
	}

	std::cout << "Date is: " << dayOfYear << '.' << month << '.' << year << std::endl;
	return 0;
}
