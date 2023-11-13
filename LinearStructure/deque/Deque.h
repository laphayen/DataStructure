#ifndef DEQUE.H
#define DEQUE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

// 덱의 노드 구조체
typedef struct Node
{
    ElementType Data;
    struct Node* PrevNode;
    struct Node* NextNode;
} Node;

// 덱 구조체
typedef struct LinkedDeque
{
    Node* Front;
    Node* Rear;
    int Count;
} LinkedDeque;

void DQ_CreateDeque(LinkedDeque** Deque);
void DQ_DestroyDeque(LinkedDeque* Deque);

Node* DQ_CreateNode(ElementType NewData);
void DQ_DestroyNode(Node* Node);

void DQ_PushFront(LinkedDeque* Deque, Node* NewNode);
void DQ_PushRear(LinkedDeque* Deque, Node* NewNode);
void DQ_PopFront(LinkedDeque* Deque);
void DQ_PopRear(LinkedDeque* Deque);

#endif // DEQUE_H