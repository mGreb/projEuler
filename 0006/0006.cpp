//Sum square difference
//Problem 6
//
//The sum of the squares of the first ten natural numbers is,
//1^2 + 2^2 + ... + 10^2 = 385
//
//The square of the sum of the first ten natural numbers is,
//(1 + 2 + ... + 10)^2 = 552 = 3025
//
//Hence the difference between the sum of the squares of the first ten natural 
//numbers and the square of the sum is 3025 − 385 = 2640.
//
//Find the difference between the sum of the squares of the first one hundred 
//natural numbers and the square of the sum.

#include <iostream>

int main()
{
	double sumOfSquares = 0;
	double squareOfSum = 0;
	for (int i = 1; i <= 100; i++)
	{
		sumOfSquares += i * i;
		squareOfSum += i;
	}
	squareOfSum = squareOfSum * squareOfSum;
	const double result = squareOfSum - sumOfSquares;
	
	std::cout << "squareOfSum: " << squareOfSum << "\n";
	std::cout << "sumOfSquares: " << sumOfSquares << "\n";
	std::cout << "Result is: " << std::fixed << result << "\n";
	
	return 0;
}