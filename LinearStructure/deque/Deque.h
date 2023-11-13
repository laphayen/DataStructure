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
typedef struct Deque
{
    Node* Front;
    Node* Rear;
    int Count;
} Deque;

void DQ_CreateDeque(Deque** Deque);
void DQ_DestroyDeque(Deque* Deque);

Node* DQ_CreateNode(ElementType NewData);
void DQ_DestroyNode(Node* Node);

void DQ_PushFront(Deque* Deque, Node* NewNode);
void DQ_PushRear(Deque* Deque, Node* NewNode);
void DQ_PopFront(Deque* Deque);
void DQ_PopRear(Deque* Deque);

#endif // DEQUE_H