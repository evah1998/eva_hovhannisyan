#ifndef DATE_H
#define DATE_H

class Date {
	private:
    	int _year;
    	int _month;
    	int _day;
	public:
		int age();
	int getYear();
	int getMonth();
	int getDay();
	Date(int year, int month, int day);
};

#endif
