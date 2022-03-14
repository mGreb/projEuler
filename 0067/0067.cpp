//Maximum path sum II
//Problem 67
//
//By starting at the top of the triangle below and moving to adjacent numbers on 
//the row below, the maximum total from top to bottom is 23.
//
//3
//7 4
//2 4 6
//8 5 9 3
//
//That is, 3 + 7 + 4 + 9 = 23.
//
//Find the maximum total from top to bottom in triangle.txt 
//(right click and 'Save Link/Target As...'), a 15K text file containing a 
//triangle with one-hundred rows.
//
//NOTE: This is a much more difficult version of Problem 18. It is not possible 
//	  to try every route to solve this problem, as there are 2^99 altogether! 
//	  If you could check one trillion (1012) routes every second it would take 
//	  over twenty billion years to check them all. There is an efficient 
//	  algorithm to solve it. ;o)

#include <iostream>
#include <fstream>
#include <vector>

int elemNum(int a)
{
	int res = 0;
	for (int i = 1; i <= a; i++)
		res += i;
	
	return res;
}

int main()
{
	std::ifstream stream;
	stream.open("../../0067/triangle.txt");
	int num; stream >> num;
	const int elemQuantity = elemNum(num);  //total amount of elements in the triangle
	printf("Height of the triangle: %d\n", num);
	printf("Quantity of elements: %d\n", elemQuantity);
	
	std::vector<int> arr(elemQuantity);
	for (int i = 0; i < elemQuantity; i++)
	{
		int val; stream >> val;
		arr[i] = val;
	}
	
	stream.close();
	
	int nextLayerStartPos =  elemQuantity - num;
	int currLayerStartPos = nextLayerStartPos - num + 1;
	for (int i = num - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			const int firstRoute = arr[currLayerStartPos+j] + arr[nextLayerStartPos+j];
			const int secondRoute = arr[currLayerStartPos+j] + arr[nextLayerStartPos+j+1];
			if (firstRoute > secondRoute)
				arr[currLayerStartPos+j] = firstRoute;
			else
				arr[currLayerStartPos+j] = secondRoute;
		}
		nextLayerStartPos =  currLayerStartPos;
		currLayerStartPos = currLayerStartPos - i + 1;
	}
	
	std::cout << "Maximum route weight is: " << arr[0] << "\n";
	
	return 0;
}
