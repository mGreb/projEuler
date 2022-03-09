//Amicable numbers
//Problem 21
//
//Let d(n) be defined as the sum of proper divisors of n (numbers less than n
//which divide evenly into n).
//If d(a) = b and d(b) = a, where a != b, then a and b are an amicable pair and
//each of a and b are called amicable numbers.
//
//For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44,
//55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4,
//71 and 142; so d(284) = 220.
//
//Evaluate the sum of all the amicable numbers under 10000.

#include <iostream>
#include <vector>

int getDivisorsSum(int input)
{
	int sum = 0;
	for (int i = 1; i < input; i++)
		if (input % i == 0)
			sum += i;
	
	return sum;
}

int countSum(int bord)
{
	int temp3 = 0;
	int sum = 0;
	
	for(int i = 1; i < bord; i++)
	{
		const int temp1 = getDivisorsSum(i);
		const int temp2 = getDivisorsSum(temp1);
		if (temp2 == i && temp1 != temp3)
		{
			if (temp1 != temp2)
			{
				sum += temp1;
				sum += temp2;
			}
			temp3 = i;
		}
	}
	
	return sum;
}

int main()
{
	std::cout << "Result: " << countSum(10000) << std::endl;
	return 0;
}
