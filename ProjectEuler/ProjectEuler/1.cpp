//Multiples of 3 and 5
//Problem 1
//
//If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
//The sum of these multiples is 23.
//
//Find the sum of all the multiples of 3 or 5 below 1000.
#include <stdio.h>
#include <conio.h>

int count(int number, int upValue){
	int sum = 0;
	for (int i = number; i < upValue; i = i + number){
		sum = sum + i;
	}
	return sum;
}

int main(){
	int upValue = 1000;
	int three = 3;
	int five = 5;
	int fifteen = 15;
	int sumThree = 0;
	int sumFive = 0;
	int sumFifteen = 0;
	int result = 0;
	sumThree = count(three, upValue);
	sumFive = count(five, upValue);
	sumFifteen = count(fifteen, upValue);
	result = sumThree + sumFive - sumFifteen;
	printf("%d", result);
	_getch();
	return 0;
}