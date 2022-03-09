//Largest palindrome product
//Problem 4
//
//A palindromic number reads the same both ways. 
//The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
//
//Find the largest palindrome made from the product of two 3-digit numbers.

//Dirk Diggler made me do this!!

#include <iostream>

int isPalindrome(int x)
{
	bool isPalindrome = true;
	int res = 0;
	int arr[6];
	
	for (int i = 0; i < 6; i++)
	{
		arr[i] = x % 10;
		x = x / 10;
	}
	
	for (int i = 0; i < 3; i++)
	{
		if (arr[i] != arr[5-i])
		{
			isPalindrome = false;
			break;
		}
	}
	
	if (isPalindrome)
	{
		int k = 1;
		for (int i = 0; i < 6; i++)
		{
			res += arr[i] * k;
			k = k * 10;
		}
	}
	
	return res;
}

int main()
{
	int biggestPalindrome = 0;
	const int up = 1000;
	for (int i = 100; i < up; i++)
		for (int j = 100; j < up; j++)
			biggestPalindrome = std::max(biggestPalindrome, isPalindrome(i*j));
	
	std::cout << "Result: " << biggestPalindrome << "\n";
	
	return 0;
}