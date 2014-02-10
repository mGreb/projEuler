//Number letter counts
//Problem 17
//
//If the numbers 1 to 5 are written out in words: one, two, three, four, five, 
//then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
//
//If all the numbers from 1 to 1000 (one thousand) inclusive were written out 
//in words, how many letters would be used?
//
//NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and 
//forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 
//letters. The use of "and" when writing out numbers is in compliance with 
//British usage.

#include <stdio.h>
#include <conio.h>

int getThousands(int a)
{
	int res = 0;
	return res;
}

int getLetNumOnes(int a)
{
	int res = 0;
	if ((a == 1) || (a == 2) || (a == 6))
	{
		res = 3;//one, two, six - three letters
		return res;
	}
	if ((a == 3) || (a == 7) || (a == 8))
	{
		res = 5;//three, seven, eight - five letters
		return res;
	}
	if ((a == 4) || (a == 5) || (a == 9))
	{
		res = 4;//four, five, nine - four letters
		return res;
	}
	return res;
}

int getLetNumTens(int a)
{
	int res = 0;
	//ten - nineteen
	if (a == 10)
	{
		res = 3;
		return res;
	}
	if ((a == 11) || (a == 12))
	{
		res = 6;
		return res;
	}
	if ((a == 13) || (a == 14) || (a == 18) || (a == 19))
	{
		res = 8;
		return res;
	}
	if ((a == 15) || (a == 16))
	{
		res = 7;
		return res;
	}
	if (a == 17)
	{
		res = 9;
		return res;
	}
	//twenty - ninety
	if ((a == 20) || (a == 30)|| (a == 80) || (a == 90))
	{
		res = 6;
		return res;
	}
	if ((a == 40) || (a == 50) || (a == 60))
	{
		res = 5;
		return res;
	}
	if (a == 70)
	{
		res = 7;
		return res;
	}
	return res;
}

int getLetNum(int a)
{
	int ones = a % 10;
	int tens = (a - ones) % 100;
	int hundreds = (a - ones - tens) % 1000 / 100;
	int thousands = (a - ones - tens - hundreds) % 10000 / 1000;
	int andLet = 3;
	int hundred = 7;
	int thousand = 8;
	bool isTeen = false;
	int res = 0;
	if (thousands == 1)
	{
		res += 3 + thousand;//one thousand
	}
	if (hundreds != 0)
	{
		res += getLetNumOnes(hundreds) + hundred;//something hundreds
	}
	if (((tens != 0) || (ones != 0)) && ((thousands != 0) || (hundreds != 0)))
	{
		res += andLet;//adding and if there is some hundreds and thousands
	}
	if ((tens != 0) && (tens < 20) && (ones != 0))
	{
		res += getLetNumTens(tens + ones);//***teen something
		isTeen = true;
	}
	if (isTeen == false)
	{
		res += getLetNumTens(tens) + getLetNumOnes(ones);//not ***teen case
	}
	return res;
}

int main()
{
	int result = 0;
	for (int i = 1; i <= 1000; i++)
	{
		result += getLetNum(i);
	}
	printf("Result: %d\n", result);
	_getch();
	return 0;
}