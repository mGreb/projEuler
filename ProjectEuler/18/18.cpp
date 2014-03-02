//Maximum path sum I
//Problem 18
//
//By starting at the top of the triangle below and moving to adjacent numbers on 
//the row below, the maximum total from top to bottom is 23.
//
//   3
//  7 4
// 2 4 6
//8 5 9 3
//
//That is, 3 + 7 + 4 + 9 = 23.
//
//Find the maximum total from top to bottom of the triangle below:
//
//               75
//              95 64
//             17 47 82
//            18 35 87 10
//           20 04 82 47 65
//          19 01 23 75 03 34
//         88 02 77 73 07 63 67
//        99 65 04 28 06 16 70 92
//       41 41 26 56 83 40 80 70 33
//      41 48 72 33 47 32 37 16 94 29
//     53 71 44 65 25 43 91 52 97 51 14
//    70 11 33 28 77 73 17 78 39 68 17 57
//   91 71 52 38 17 14 91 43 58 50 27 29 48
//  63 66 04 68 89 53 67 30 73 16 69 87 40 31
//04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
//
//NOTE: As there are only 16384 routes, it is possible to solve this problem by 
//trying every route. However, Problem 67, is the same challenge with a triangle 
//containing one-hundred rows; it cannot be solved by brute force, and requires a 
//clever method! ;o)

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
	const char* filePath = "18.txt";
	const char* mode = "r+";
	FILE* file;
	fopen_s(&file, filePath, mode);
	int readLength = 3;
	char* buffer = (char*)calloc(readLength, sizeof(char));
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
	printf("Maximum route weight is: %d", arr[0]);
	_getch();
	return 0;
}
