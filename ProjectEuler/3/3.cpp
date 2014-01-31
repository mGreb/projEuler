//Largest prime factor
//Problem 3
//
//The prime factors of 13195 are 5, 7, 13 and 29.
//
//What is the largest prime factor of the number 600.851.475.143 ?
#include <stdio.h>
#include <conio.h>
#include <math.h>

void isItPrime(int x){
	bool res = true;
	for (int i = 2; i < x; i++){
		if (i%x == 0){
			res = false;
			break;
		}
	}
	printf("%d\n", res);
}

int main(){
	isItPrime(137);
	int result = 0;
	double largeNumber = 600851475143.;
	printf("largeNumber: %lf\n", largeNumber);
	double squareRoot = sqrt(largeNumber);
	printf("squareRoot: %lf\n", squareRoot);
	int floorRoot = (int)floor(squareRoot);
	printf("floorRoot: %d\n", floorRoot);
	bool notOkay = false;
	double cont = 0;
	for (int i = 1; i < floorRoot; i += 2){
		notOkay = true;
		if (i%3 == 0){
			continue;
		}
		if (i%5 == 0){
			continue;
		}
		if (i%7 == 0){
			continue;
		}
		for (int j = 2; j < i; j++){
			if (i%j == 0){
				notOkay = false;
				break;
			}
		}
		if (notOkay == true){
			cont = largeNumber/(double)i;
			if (cont == floor(cont)){
				result = i;
				printf("%d\n", i);
			}
		}
	}
	printf("It`s over!\n");
	printf("Result: %lf\n", result);
	_getch();
	return 0;
}