//Counting Sundays
//Problem 19
//
//You are given the following information, but you may prefer to do some
//research for yourself.
//
//    1 Jan 1900 was a Monday.
//    Thirty days has September,
//    April, June and November.
//    All the rest have thirty-one,
//    Saving February alone,
//    Which has twenty-eight, rain or shine.
//    And on leap years, twenty-nine.
//
//A leap year occurs on any year evenly divisible by 4, but not on a
//century unless it is divisible by 400.
//
//How many Sundays fell on the first of the month during the twentieth
//century (1 Jan 1901 to 31 Dec 2000)?

#include <iostream>
#include <array>

std::array<int, 12> daysInMonths = {
	31, //January
	28, //February
	31, //March
	30, //April
	31, //May
	30, //June
	31, //July
	31, //August
	30, //September
	31, //October
	30, //November
	31 //December
};

const int startYear = 1900;
const int endYear = 2000;

bool isRegular(int x)
{
	bool res = false;
	if (x % 4 == 0)
		res = true;
	
	if ((x % 4 == 0)&&(x % 100 == 0))
		res = false;
	
	if ((x % 400 == 0)&&(x % 4 == 0)&&(x % 100 == 0))
		res = true;
	
	return res;
}

int cnt()
{
	int sundaysQuantity = 0;
	int temp = 7;
	for (int i = startYear; i <= endYear; i++)
	{
		if (isRegular(i))
			daysInMonths[1] = 29;
		else
			daysInMonths[1] = 28;
		
		for (int j = 0; j < daysInMonths.size(); j++)
		{
			for (;;)
			{
				if ((i != startYear) && (temp == 1))
				{
					sundaysQuantity++;
					std::cout << "year: " << i << " month: " << j << " day: " << temp << "\n";
				}
				temp += 7;
				if (temp > daysInMonths[j])
				{
					temp = temp - daysInMonths[j];
					break;
				}
			}
			
		}
	}
	return sundaysQuantity;
}

int main()
{
	std::cout << "There are " << cnt() << " sundays in XX century that fell on the first of the month!\n";
	return 0;
}
