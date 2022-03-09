//Smallest multiple
//Problem 5
//
//2520 is the smallest number that can be divided by each of 
//the numbers from 1 to 10 without any remainder.
//
//What is the smallest positive number that is evenly divisible by 
//all of the numbers from 1 to 20?

#include <iostream>

int main()
{
	int smallestMultiple = 0;
	for (int i = 1; ; i++)
	{
		bool isSmallestMultiple = true;
		for (int j = 1; j <= 20; j++)
		{
			if (i%j != 0)
			{
				isSmallestMultiple = false;
				break;
			}
		}
		if (isSmallestMultiple)
		{
			smallestMultiple = i;
			break;
		}
	}
	
	std::cout << "Result is: " << smallestMultiple << "\n";
	
	return 0;
}
