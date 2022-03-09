//Largest prime factor
//Problem 3
//
//The prime factors of 13195 are 5, 7, 13 and 29.
//
//What is the largest prime factor of the number 600.851.475.143 ?

#include <iostream>
#include <cmath>

int main()
{
	const double largeNumber = 600851475143.;
	const double squareRoot = sqrt(largeNumber);
	const int floorRoot = (int)floor(squareRoot);
	std::cout << "largeNumber: " << largeNumber << "\n";
	std::cout << "squareRoot: " << squareRoot << "\n";
	std::cout << "floorRoot: " << floorRoot << "\n";
	
	int result = 0;
	for (int i = 1; i < floorRoot; i += 2)
	{
		if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0 || i % 11 == 0 || i % 13 == 0 || i % 17 == 0 || i % 19 == 0)
			continue;
		bool notOkay = true;
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				notOkay = false;
				break;
			}
		}
		if (notOkay)
		{
			const double cont = largeNumber / (double)i;
			if (cont == floor(cont))
				result = i;
		}
	}
	
	std::cout << "It`s over!\n";
	std::cout << "Result: " << result << "\n";
	
	return 0;
}
