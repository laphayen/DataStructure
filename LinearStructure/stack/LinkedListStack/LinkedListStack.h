#ifndef LINKEDLIST_STACK_H
#define LINKEDLIST_STACK_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int ElementType;

// 스택의 노드 구조체
typedef struct Node
{
    ElementType Data;
    struct Node* Next;
} Node;

// 스택 구조체
typedef struct LinkedListStack
{
    Node* List;
    Node* Top;
} LinkedListStack;

void LLS_CreateStack(LinkedListStack** stack);
void LLS_DestroyStack(LinkedListStack* Stack);

Node* LLS_CreateNode(ElementType NewData);
void LLS_DestroyNode(Node* Node);

void LLS_Push(LinkedListStack* Stack, Node* NewNode);
Node* LLS_Pop(LinkedListStack* Stack);
Node* LLS_Top(LinkedListStack* Stack);
int LLS_GetSize(LinkedListStack* Stack);
int LLS_IsEmpty(LinkedListStack* Stack);

#endif