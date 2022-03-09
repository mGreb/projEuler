//Special Pythagorean triplet
//Problem 9
//
//A Pythagorean triplet is a set of three natural 
//numbers, a < b < c, for which,
//a^2 + b^2 = c^2
//
//For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
//
//There exists exactly one Pythagorean triplet 
//for which a + b + c = 1000.
//Find the product abc.

#include <cstdio>

bool isTriplet(int a, int b, int c){
	if (a >= b)
		return false;
	
	if ((a*a + b*b) == c*c)
		return true;
	
	return false;
}

int main()
{
	for (int a = 1; a <= 1000; a++)
	{
		for (int b = 1; b <= 1000; b++)
		{
			for (int c = 1; c <= 1000; c++)
			{
				if ((a+b+c) == 1000)
				{
					if (isTriplet(a,b,c))
					{
						const int product = a*b*c;
						printf("a=%d, b=%d, c=%d\n", a, b, c);
						printf("Result: %d\n", product);
						return 0;
					}
				}
			}
		}
	}
}
