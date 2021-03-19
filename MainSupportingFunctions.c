#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "MainSupportingFunctions.h"

int ReadNumberOfProcesses()
{
	int returnValue;
	char numString[256] = {};
	do
	{
		printf("How many processes do you want to create: ");
		fgets(numString, 256, stdin);
		returnValue = (numString[0] == '0' && numString[1] == '\n') ? 0 : (atoi(numString) <= 0 ? -1 : atoi(numString));
		printf("\n");
	} while (returnValue < 0 || returnValue > INT_MAX);

	return returnValue;
}

int GetDirectionOfExecution()
{
	int returnValue = 0;
	char dirString[256] = {};
	do
	{
		printf("Which direction do you want to execute?\n\n1 - First to lasat.\n2 - Last to first.\n\nPlease specify: ");
		fgets(dirString, 256, stdin);
		returnValue = atoi(dirString) <= 0 ? -1 : atoi(dirString);
		printf("\n");
	} while (returnValue != 1 && returnValue != 2);

	return returnValue;
}
