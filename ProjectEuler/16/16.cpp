//Power digit sum
//Problem 16
//
//2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
//
//What is the sum of the digits of the number 2^1000?
#include <stdio.h>
#include <malloc.h>

int* bigPow(int a, int b, int n)
{
	int maxDigit = 9;
	int base = 10;
	int* result = (int*)calloc(n*b, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		result[i] = a;
	}
	for (int i = 1; i < b; i++)
	{
		//multiply
		for (int j = 0; j < n * b; j++)
		{
			result[j] = result[j] * a;
		}
		//spread
		for (int k = 0; k < n * b - 1; k++)
		{
			if (result[k] > maxDigit)
			{
				result[k+1] += (result[k] - result[k] % base) / base;
				result[k] = result[k] % base;
			}
		}
	}
	return result;
}

int main()
{
	int sum = 0;
	int power = 1000;
	int base = 2;
	int lengthOfBase = 1;//number of digits in base
	int* result = bigPow(base, power, lengthOfBase);
	for (int i = 0; i < power * lengthOfBase; i++)
	{
		sum += result[i];
	}
	printf("Result is: %d\n", sum);
	return 0;
}