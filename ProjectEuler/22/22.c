/* 	
	Using names.txt (right click and 'Save Link/Target As...'), a 46K text file 
	containing over five-thousand first names, begin by sorting it into 
	alphabetical order. Then working out the alphabetical value for each name, 
	multiply this value by its alphabetical position in the list to obtain 
	a name score.

	For example, when the list is sorted into alphabetical order, 
	COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name 
	in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

	What is the total of all the name scores in the file? 
*/

#include <stdio.h>
#include <malloc.h>

#define bool int
#define true 1
#define false 0

int compare (char*, char*, int);

int main ()
{
	FILE* fileWithNames; 			 // pointer fo file structure
	char filename[10] = "names.txt"; // name of the file
	char** listOfAllNames = NULL; 	 // two dimentional array to store names
	char buffer; 					 // one letter buffer
	bool insideName = false; 		 // inducates that we are inside the name
	int nameCount = 0; 				 // total number of names
	int maxNameLength = 0; 			 // maximum length of a name
	int nameLength = 0; 			 // current name length
	printf ("This is Project Euler 22\n");
	
	// figure out number of names in the file ----------------------------------
	fileWithNames = fopen (filename, "r");
	while (EOF != (buffer = fgetc (fileWithNames)) )
	{
		if (buffer == '"')
		{
			if (insideName == false)
			{
				insideName = true;
				nameCount++;
			} else {
				insideName = false;
			}
		}
		if (insideName == true)
		{
			nameLength++;
		} else {
			if (maxNameLength < nameLength)
			{
				maxNameLength = nameLength;
			}
			nameLength = 0;
		}
	}
	printf ("Number of names in the file: %d\n", nameCount);
	printf ("Maximum name length: %d\n", maxNameLength);
	fclose (fileWithNames);
	// -------------------------------------------------------------------------

	// put all the names into two dimensional array ----------------------------
	listOfAllNames = (char**) calloc (nameCount, sizeof (char*));
	int i = 0;
	int j = 0;
	for (i = 0; i < nameCount; i++)
	{
		listOfAllNames[i] = (char*) calloc (maxNameLength, sizeof (char));
	}
	i = -1;
	fileWithNames = fopen (filename, "r");
	while ( (buffer = fgetc (fileWithNames)) != EOF )
	{
		if (buffer == '"')
		{
			if (insideName == false)
			{
				insideName = true;
				i++;
				j = 0;
			} else {
				insideName = false;
			}
		}
		if ( (insideName == true) && (buffer != '"') )
		{
			listOfAllNames[i][j] = buffer;
			j++;
		}
	}
	/*for (i = 0; i < nameCount; ++i)
	{
		for (j = 0; j < maxNameLength; j++)
		{
			printf ("%c", listOfAllNames[i][j]);
		}
		printf ("\n");
	}*/
	fclose (fileWithNames);
	// -------------------------------------------------------------------------

	// sort out the names alphabetically ---------------------------------------
	char temp[maxNameLength];
	int k = 0;
	for (i = 0; i < nameCount; i++)
	{
		for (j = i; j < nameCount; j++)
		{
			if (compare (listOfAllNames[i], listOfAllNames[j], maxNameLength)
				 == 0)
			{
				for (k = 0; k < maxNameLength; k++)
				{
					temp[k] = listOfAllNames[j][k];
					listOfAllNames[j][k] = listOfAllNames[i][k];
					listOfAllNames[i][k] = temp[k];
				}
			}
		}
	}
	for (i = 0; i < nameCount; ++i)
	{
		for (j = 0; j < maxNameLength; j++)
		{
			printf ("%c", listOfAllNames[i][j]);
		}
		printf ("\n");
	}
	int* valueArray = (int*) calloc (nameCount, sizeof (int));
	for (i = 0; i < nameCount; i++)
	{
		for (j = 0; j < maxNameLength; j++)
		{
			if ((listOfAllNames[i][j] <= 'Z') && (listOfAllNames[i][j] >= 'A'))
			{
				valueArray[i] += listOfAllNames[i][j] - 'A' + 1;
				//printf ("%c ", listOfAllNames[i][j]);
			}
		}
		//printf ("%d\n", valueArray[i]);
	}
	/*for (i = 0; i < nameCount; i++)
	{
		printf("%d\n", valueArray[i]);
	}*/
	// -------------------------------------------------------------------------

	// calculate answer --------------------------------------------------------
	long answer = 0;
	for (i = 0; i < nameCount; i++)
	{
		answer += (i + 1) * valueArray[i];
	}
	printf("%d\n", answer);
	// -------------------------------------------------------------------------
	return 0;
}

int compare (char* a, char* b, int length)
{
	int i = 0;
	
	/*printf ("Compairing ");
	for (i = 0; i < length; ++i)
	{
		printf ("%c", a[i]);
	}
	printf(" and ");
	for (i = 0; i < length; ++i)
	{
		printf ("%c", b[i]);
	}
	printf("\n");*/

	for (i = 0; i < length; i++)
	{
		if (a[i] < b[i])
		{
			//printf("b is bigger\n");
			return 1;
		}
	}
	//printf("a is bigger\n");
	return 0;
}