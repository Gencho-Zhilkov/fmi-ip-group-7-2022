#include <iostream>


bool isLeapYear(int year) {
	return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
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
	int day, month, year;
	std::cout << "Enter date: ";
	std::cin >> day >> month >> year;

	if (month < 1 || month > 12) {
		std::cerr << "Wrong month: must be between 1 and 12." << std::endl;
		return 1;
	}

	if (day < 1 || day > daysInMonth(month, year)) {
		std::cerr << "Wrong day: must be between 1 and " << daysInMonth(month, year) << std::endl;
		return 1;
	}

	int totalDays = 0;
	// int currentMonth = 1;
	// while (currentMonth < month) {
	// 	totalDays += daysInMonth(currentMonth, year);
	// 	currentMonth ++;
	// }
	for (int currentMonth = 1; currentMonth < month; currentMonth ++) {
		totalDays += daysInMonth(currentMonth, year);
	}
	totalDays += day;

	std::cout << "Day of year is: " << totalDays << std::endl;
	return 0;
}
