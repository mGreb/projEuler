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


#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

int elemNum(int a)
{
	int res = 0;
	for (int i = 1; i <= a; i++)
	{
		res += i;
	}
	return res;
}

int printTriangle(int height, int* tree)
{
	int k = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%d ", tree[k]);
			k++;
		}
		printf("\n");
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	const char* filePath = "67.txt";
	const char* mode = "r+";
	FILE* file;
	fopen_s(&file, filePath, mode);
	int readLength = 3;
	char* buffer = (char*)calloc(readLength+1, sizeof(char));
	int num = 0;//height of the triangle
	fread(buffer, sizeof(char), readLength, file);
	num = atoi(buffer);
	int elemQuantity = elemNum(num);//total amount of elements in the 
	printf("Height of the triangle: %d\n", num);
	printf("Quantity of elements: %d\n", elemQuantity);
	
	int* arr = (int*)calloc(elemQuantity, sizeof(int));
	for (int i = 0; i < elemQuantity; i++)
	{
		fread(buffer, sizeof(char), readLength, file);
		arr[i] = atoi(buffer);
	}
	
	fclose (file);

	printTriangle(num, arr);

	//main count cycle
	int firstRoute = 0;
	int secondRoute = 0;
	int nextLayerStartPos =  elemQuantity - num;
	int currLayerStartPos = nextLayerStartPos - num + 1;
	for (int i = num - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			firstRoute = arr[currLayerStartPos+j] + arr[nextLayerStartPos+j];
			secondRoute = arr[currLayerStartPos+j] + arr[nextLayerStartPos+j+1];
			if (firstRoute > secondRoute)
			{
				arr[currLayerStartPos+j] = firstRoute;
			}
			else
			{
				arr[currLayerStartPos+j] = secondRoute;
			}
		}
		nextLayerStartPos =  currLayerStartPos;
		currLayerStartPos = currLayerStartPos - i + 1;
	}
	printf("Maximum route weight is: %d\n", arr[0]);
	_getch();
	return 0;
}
