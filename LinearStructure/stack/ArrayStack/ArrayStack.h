#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

// AS 노드
typedef struct tagNode
{
	ElementType Data;
} Node;

// AS 구조체는 Stack의 용량, 현재 위치, 노드들을 가리키는 포인터를 가진다.
typedef struct tagArrayStack
{
	int Capacity;
	int Top;
	Node* Nodes;
} ArrayStack;

void        AS_CreateStack(ArrayStack** Stack, int Capacity);
void        AS_DestroyStack(ArrayStack* Stack);
void        AS_Push(ArrayStack* Stack, ElementType Data);
ElementType AS_Pop(ArrayStack* Stack);
ElementType AS_Top(ArrayStack* Stack);
int         AS_GetSize(ArrayStack* Stack);
int         AS_IsEmpty(ArrayStack* Stack);

#endif