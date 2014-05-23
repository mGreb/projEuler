﻿//Names scores
//Problem 22
//
//Using names.txt (right click and 'Save Link/Target As...'), a 46K text file
//containing over five-thousand first names, begin by sorting it into
//alphabetical order. Then working out the alphabetical value for each name,
//multiply this value by its alphabetical position in the list to obtain a
//name score.
//
//For example, when the list is sorted into alphabetical order, COLIN,
//which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list.
//So, COLIN would obtain a score of 938 × 53 = 49714.
//
//What is the total of all the name scores in the file?

#include <cstdio>

const int size = 20;

struct name
{
	name* prevName;
	name* nextName;
	char thisIsName[size];
} sFirstName;

bool compare (char a[size], char b[size])
{
	bool AisBigger = true;
	int i = 0;
	for (i = 0; i < size; i++)
	{
		if (a[i]<b[i])
		{
			AisBigger = false;
			return AisBigger;
		}
	}
	return AisBigger;
}

char* getName(const char* fileName)
{
	FILE *fp;
	fopen_s( &fp, fileName, "r");
	char symbol = '0';
	char name[size] = {'0'};
	int i = 0;
	while (symbol != EOF)
	{
		symbol = fgetc(fp);
		if (symbol != '"' || symbol != ',')
		{
		}
		i++;
	}
	fclose(fp);
	return 0;
}

int main()
{
	char a = 'a';
	char b = 'A';
	printf("%d, %d", (int)a, (int)b);
	return 0;
}