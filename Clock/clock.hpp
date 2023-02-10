#pragma once

#include <iostream>
#include <string>

struct Period {
	bool designation;
	Period(const char* p = "am");
	const char* getPeriod() const 
		{ if (!designation) return "am"; else return "pm"; };
};

class Clock
{
	int hour;
	int minute;
	int second;
	Period period; 		// am OR pm

	bool format = true;	// select format for << operator
						// true - format12h - default storage
						// false - format24h - should be converted on display

public:
//fill missing


	bool& SetFormat();
	const char* getPeriod() const { return period.getPeriod(); };
	
	void Plan(int class_duration, const int* breaks, int nr, Clock* class_start) const;


	//Operator overloaders below:
	friend std::istream& operator>>(std::istream& cin, Clock& a);
	friend std::ostream& operator<<(std::ostream& cout, const Clock& a);
	friend bool operator==(const Clock& a, const Clock& b);
	friend Clock operator+(Clock& a, int b);


	//Constructors below:
	Clock(int hour_ = 1, int minute_ =0, int second_ = 0, const char* s_ = "am") {

		hour = hour_;
		minute = minute_;
		second = second_;
		period = s_;
	}

	Clock(std::string a) {
		hour = std::stoi(a.substr(0, 2));
		minute = std::stoi(a.substr(4, 2));
		second = std::stoi(a.substr(7, 2));
		Period pp(a.substr(10, 2).c_str());
		period = pp;
	}

	
};

int TimeOffset(const Clock& z1, const Clock& z2);




