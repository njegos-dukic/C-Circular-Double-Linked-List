#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include "CircularDoublyLinkedList.h"
#include "MainSupportingFunctions.h"

int main(int argc, char* argv[])
{
	srand(time(0));

	int numberOfProcesses = ReadNumberOfProcesses();
	int ourLimit;

	for (int i = 1; i <= numberOfProcesses; i++)
		AddNodeAtTheEnd(GenerateNode(i));

	printf("Critical time is: %d.\n\n", atoi(argv[1]));

	int directionOfExecution = GetDirectionOfExecution();

	if (directionOfExecution == 1)
	{
		ExecuteForwards();
		ExecuteOddWithLimitForwards(atoi(argv[1]));
	}
	else if (directionOfExecution == 2)
	{
		ExecuteBackwards();
		ExecuteOddWithLimitBackwards(atoi(argv[1]));
	}

	system("PAUSE");

	return 0;
}
