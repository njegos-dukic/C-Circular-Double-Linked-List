#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h> // "unistd.h" cannot be found: For UNIX based systems.
#include "CircularDoubleLinkedList.h"

node* head = NULL;
int totalDuration = 0;
int currentDuration = 0;

node* GenerateNode(int ID)
{
	node* returnNode = (node*)calloc(sizeof(node), 1);

	returnNode->processID = ID;
	returnNode->processDuration = rand() % 15 + 1;
	returnNode->next = NULL;
	returnNode->previous = NULL;

	totalDuration += returnNode->processDuration;

	return returnNode;
}

void AddNodeAtTheBeginning(node* newNode)
{
	node* tempNode;

	if (head == NULL)
	{
		head = newNode;
		newNode->next = head->next = newNode;
		newNode->previous = head->previous = newNode;
	}

	else
	{
		tempNode = head;
		head = newNode;
		newNode->previous = head->previous = tempNode->previous;
		newNode->next = head->next = tempNode;
		tempNode->previous->next = newNode;
		tempNode->previous = newNode;
	}
}

void AddNodeAtTheEnd(node* newNode)
{
	node* tempNode;

	if (head == NULL)
	{
		head = newNode;
		newNode->next = head->next = newNode;
		newNode->previous = head->previous = newNode;
	}

	else
	{
		tempNode = head->previous;
		head->previous = newNode;
		newNode->next = head;
		newNode->previous = tempNode;
		tempNode->next = newNode;
	}
}

void RepresentSingleNode(node* currentNode)
{
	printf("   Process #%d\n   Duration: %d", currentNode->processID, currentNode->processDuration);
	// printf("Proces #%d\nVrijeme trajanja: %d\nNext node: %d\nPrevious node: %d\n", currentNode->processID, currentNode->processDuration, currentNode->next->processID, currentNode->previous->processID);
	Sleep(currentNode->processDuration * 1);
}

void DeleteNode(node* targetNode)
{
	if (head == NULL)
		return;

	else if (targetNode == head && head->next != head)
	{
		head = targetNode->next;
		targetNode->previous->next = head;
		head->previous = targetNode->previous;
	}

	else if (targetNode == head && head->next == head)
		head = NULL;

	else
	{
		targetNode->next->previous = targetNode->previous;
		targetNode->previous->next = targetNode->next;
	}

	totalDuration = totalDuration - targetNode->processDuration;
	free(targetNode);
	return;
}

void DeleteNodeIfProcessLongerThan(int duration)
{
	node* currentNode = head;
	node* lastNodeToVisit = head->previous;
	node* tempNode;

	do
	{
		tempNode = currentNode->next;

		if (currentNode->processDuration > duration)
			DeleteNode(currentNode);

		currentNode = tempNode;

	} while (currentNode != lastNodeToVisit);

	currentNode = lastNodeToVisit;

	if (currentNode->processDuration > duration)
		DeleteNode(currentNode);
}

void Format()
{
	printf("\n   ***************\n   *             *\n   *  EXECUTION  *\n   *             *\n   ***************\n");
}

const char* ConvertFgetsInputToLowercase(char inputString[])
{
	char* returnString = (char*)calloc(sizeof(char), 256);
	for (int i = 0; inputString[i] && inputString[i] != '\n'; i++)
		returnString[i] = tolower(inputString[i]);

	return returnString;
}

void ExecuteCommand()
{
	char command[256] = {};
	do
	{
		printf("\nEnter \"START\" for execution: ");
		fgets(command, 256, stdin);
	} while (strcmp(ConvertFgetsInputToLowercase(command), "start")); // strcmp() returns 0 if strings are identical.

	return;
}

void ExecuteForwards()
{
	ExecuteCommand();

	Format();

	node* currentNode = head;

	printf("\n");
	if (head == NULL)
		printf("   Empty list.\n\n");
	else
		do
		{
			RepresentSingleNode(currentNode);
			currentNode = currentNode->next;
			printf("\n\n");
		} while (currentNode != head);

		printf("\nTotal time needed for all processes: %d seconds.\n\n", totalDuration);
}

void ExecuteBackwards()
{
	ExecuteCommand();

	Format();

	node* currentNode = head->previous;

	printf("\n");
	if (head == NULL)
		printf("   Empty list.\n\n");
	else
		do
		{
			RepresentSingleNode(currentNode);
			currentNode = currentNode->previous;
			printf("\n\n");
		} while (currentNode->next != head);

	printf("\nTotal time needed for all processes: %d seconds.\n\n", totalDuration);
}

void ExecuteOddWithLimitForwards(int limit)
{
	ExecuteCommand();

	Format();

	node* currentNode = head;

	printf("\n");
	if (head == NULL)
		printf("   Empty list.\n\n");
	else
		do
		{
			if (currentNode->processDuration % 2 != 0)
			{
				RepresentSingleNode(currentNode);
				currentDuration += currentNode->processDuration;
				printf("\n\n");
			}
			currentNode = currentNode->next;
		} while (currentDuration <= limit);

		printf("\nTotal time needed for all processes: %d seconds.\n\n", currentDuration);
}

void ExecuteOddWithLimitBackwards(int limit)
{
	ExecuteCommand();

	Format();

	node* currentNode = head->previous;

	printf("\n");
	if (head == NULL)
		printf("   Empty list.\n\n");
	else
		do
		{
			if (currentNode->processDuration % 2 != 0)
			{
				RepresentSingleNode(currentNode);
				currentDuration += currentNode->processDuration;
				printf("\n\n");
			}
			currentNode = currentNode->previous;
		} while (currentDuration <= limit);

		printf("\nTotal time needed for all processes: %d seconds.\n\n", currentDuration);
}
