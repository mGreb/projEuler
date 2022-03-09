//Summation of primes
//Problem 10
//
//The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
//
//Find the sum of all the primes below two million.

#include <cstdio>
#include <cmath>

int isPrime(int x)
{
	if (x == 1) return 0;
	if (x == 2) return 2;
	if (x > 3 && x % 3 == 0) return 0;
	
	const int sqrt = std::floor(std::sqrt(x));
	for (int i = 2; i <= sqrt; i++)
		if (x % i == 0)
			return 0;
	
	return x;
}

int main()
{
	const int twoMillion = 2000000;
	double sum = 2;
	for (int i = 1; i <= twoMillion; i += 2)
		sum += isPrime(i);
	
	printf("Result: %lf\n", sum);
	
	return 0;
}
