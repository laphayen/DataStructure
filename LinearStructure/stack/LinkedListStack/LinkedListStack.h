#ifndef LINKEDLIST_STACK_H
#define LINKEDLIST_STACK_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tagNode
{
    char* Data;
    struct tageNode* NextNode;
} Node;

typedef struct tagLinkedListStack
{
    Node* List;
    Node* Top;
} LinkedListStack;

void LLS_CreateStack(LinkedListStack** stack);
void LLS_DestroyStack(LinkedListStack* Stack);

Node* LLS_CreateStack(char* Data);
void LLS_DestroyNode(Node* _Node);

void LLS_Push(LinkedListStack* Stack);
Node* LLS_Pop(LinkedListStack* Stack);

Node* LLS_Top(LinkedListStack* Stack);
int LLS_GetSize(LinkedListStack* Stack);
int LLS_IsEmpty(LinkedListStack* Stack);

#endif
