#pragma once

#include <stdlib.h>

typedef struct Node
{
	int processID;
	int processDuration;
	struct Node* next;
	struct Node* previous;
} node;

extern node* head;
extern int totalDuration;
extern int currentDuration;

node* GenerateNode(int ID);
void AddNodeAtTheBeginning(node* newNode);
void AddNodeAtTheEnd(node* newNode);
// void RepresentSingleNode(node* currentNode);
void DeleteNode(node* targetNode);
void DeleteNodeIfProcessLongerThan(int duration);
// void Format();
// const char* ConvertFgetsInputToLowercase(char inputString[]);
// void ExecuteCommand();
void ExecuteForwards();
void ExecuteBackwards();
void ExecuteOddWithLimitForwards(int limit);
void ExecuteOddWithLimitBackwards(int limit);
