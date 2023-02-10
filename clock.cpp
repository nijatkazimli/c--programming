#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "clock.hpp"

Period::Period(const char* p) : designation(false) {
	if (0 == strcmp(p, "am"))
		designation = false;
	else if (0 == strcmp(p, "pm"))
		designation = true;
};

std::istream& operator>>(std::istream& cin, Clock& a) {

	std::cout << "Enter hours: ";
	std::cin >> a.hour;
	while (a.hour > 12 || a.hour < 1) {
		std::cout << "Invalid input, please try again!" << std::endl;
		std::cout << "Enter hours: ";
		std::cin >> a.hour;
	}

	std::cout << "Enter minutes: ";
	std::cin >> a.minute;
	while (a.minute < 0 || a.minute > 60) {
		std::cout << "Invalid input, please try again!" << std::endl;
		std::cout << "Enter minutes: ";
		std::cin >> a.minute;
	}
	std::cout << "Enter seconds: ";
	std::cin >> a.second;
	while (a.second < 0 || a.second > 60) {
		std::cout << "Invalid input, please try again!" << std::endl;
		std::cout << "Enter seconds: ";
		std::cin >> a.second;
	}
	std::cout << "Enter your period: ";
	char p[3];
	std::cin >> p;
	Period pp(p);
	a.period = pp;


	return cin;
}

std::ostream& operator<<(std::ostream& cout, const Clock& a) {
	if (a.format == true) {
		if(a.hour >=10)
			std::cout << a.hour << ":";
		else
			std::cout << 0 << a.hour << ":";
		if (a.minute >= 10)
			std::cout << a.minute << ":";
		else
			std::cout << 0 << a.minute << ":";
		if (a.second >= 10)
			std::cout << a.second << a.getPeriod();
		else
			std::cout << 0 << a.second << a.getPeriod();
	}
	else {
		if (a.getPeriod() == "am") {
		
			if (a.hour >= 10) {
				if (a.hour == 12) {
					std::cout << 0 << 0 << ":";
				}
				else {
					std::cout << a.hour << ":";
				}

			}
			else
				std::cout << 0 << a.hour << ":";
			if (a.minute >= 10)
				std::cout << a.minute << ":";
			else
				std::cout << 0 << a.minute << ":";
			if (a.second >= 10)
				std::cout << a.second;
			else
				std::cout << 0 << a.second;
		}
		else {
			if (a.hour == 12) {
				std::cout << a.hour << ":";
			}
			else
				std::cout << a.hour + 12 << ":";
			if (a.minute >= 10)
				std::cout << a.minute << ":";
			else
				std::cout << 0 << a.minute << ":";
			if (a.second >= 10)
				std::cout << a.second;
			else
				std::cout << 0 << a.second;
		}
	}

	return cout;
}

bool& Clock::SetFormat() {
	return format;
}

bool operator==(const Clock& a, const Clock& b) {
	if (a.hour == b.hour && a.minute == b.minute && a.second == b.second && a.getPeriod() == b.getPeriod())
		return true;
	else
		return false;
}

Clock operator+(Clock& a, int b) {
	a.second++;

	return a;
}




