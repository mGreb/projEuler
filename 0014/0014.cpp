//Longest Collatz sequence
//Problem 14
//
//The following iterative sequence is defined for the set of positive integers:
//
//n → n/2 (n is even)
//n → 3n + 1 (n is odd)
//
//Using the rule above and starting with 13, we generate the following sequence:
//13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
//
//It can be seen that this sequence (starting at 13 and finishing at 1) contains 
//10 terms. Although it has not been proved yet (Collatz Problem), it is thought
//that all starting numbers finish at 1.
//
//Which starting number, under one million, produces the longest chain?
//
//NOTE: Once the chain starts the terms are allowed to go above one million.

#include <cstdio>

int collatzLength(int inp)
{
	int length = 1;
	unsigned long iinp = inp;
	for (;;)
	{
		if (iinp == 1)
			break;
		
		if (iinp%2 == 0)
			iinp = iinp/2;
		else
			iinp = 3*iinp + 1;
		
		length++;
	}
	
	return length;
}

int main()
{
	int length = 0;
	int number = 0;
	for (int i = 1; i < 1000000; i++)
	{
		const int currLength = collatzLength(i);
		if (length < currLength)
		{
			number = i;
			length = currLength;
		}
	}
	
	printf("Collatz length: %d\n", length);
	printf("Result: %d\n", number);
	
	return 0;
}
