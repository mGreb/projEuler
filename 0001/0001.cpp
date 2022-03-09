//Multiples of 3 and 5
//Problem 1
//
//If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
//The sum of these multiples is 23.
//
//Find the sum of all the multiples of 3 or 5 below 1000.

#include <iostream>

int count(int number, int upValue){
	int sum = 0;
	for (int i = number; i < upValue; i += number){
		sum = sum + i;
	}
	return sum;
}

int main(){
	const int upValue = 1000;
	const int three = 3;
	const int five = 5;
	const int fifteen = 15;
	const int sumThree = count(three, upValue);
	const int sumFive = count(five, upValue);
	const int sumFifteen = count(fifteen, upValue);
	const int result = sumThree + sumFive - sumFifteen;
	std::cout << result << std::endl;
	return 0;
}