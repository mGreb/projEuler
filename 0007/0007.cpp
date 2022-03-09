//10001st prime
//Problem 7
//
//By listing the first six prime numbers: 2, 3,
// 5, 7, 11, and 13, we can see that the 6th 
// prime is 13.
//
//What is the 10 001st prime number?

#include <cstdio>

int isPrime(int x)
{
	for (int i = 2; i < x; i++)
		if (x % i == 0)
			return 0;
	
	return x;
}

int main(){
	int result = 0;
	int num = 0;
	int primeNum = 10001;
	for(int i = 2; ; i++)
	{
		const int prime = isPrime(i);
		if (prime != 0)
		{
			num++;
			printf("%d: %d\n", num, prime);
		}
		if (num == primeNum)
		{
			result = prime;
			break;
		}
	}
	printf("Result: %d\n", result);
	
	return 0;
}