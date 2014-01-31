//Summation of primes
//Problem 10
//
//The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
//
//Find the sum of all the primes below two million.

#include <stdio.h>
#include <conio.h>

inline int isPrime(int x){
	if (x == 1){
		return 0;
	}
	if (x == 2){
		return 2;
	}
	for (int i = 2; i < x; i++){
		if (x%i == 0){
			return 0;
		}
	}
	return x;
}

int main(){
	double sum = 2;
	int twoMillion = 2000000;
	for (int i = 1; i <= twoMillion; i += 2){
		sum += isPrime(i);
	}
	printf("Result: %lf\n", sum);
	_getch();
	return 0;
}