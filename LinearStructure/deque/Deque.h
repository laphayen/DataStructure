#ifndef DEQUE.H
#define DEQUE_H

#include <stdio.h>
#include <stdlib.h>

// 덱의 데이터 타입 정의
typedef int ElementType;

// 덱의 노드 구조체
typedef struct Node
{
    ElementType Data;
    struct Node* PrevNode;
    struct Node* NextNode;
} Node;

// 덱 구조체
typedef struct LinkedListDeque
{
    Node* Front;    // 덱의 전단 노드
    Node* Rear;     // 덱의 후단 노드
    int Count;      // 덱의 노드 개수
} LinkedListDeque;

void DQ_CreateDeque(LinkedListDeque** Deque);
void DQ_DestroyDeque(LinkedListDeque* Deque);

Node* DQ_CreateNode(ElementType NewData);
void DQ_DestroyNode(Node* Node);

void DQ_PushFront(LinkedListDeque* Deque, Node* NewNode);
void DQ_PushRear(LinkedListDeque* Deque, Node* NewNode);
void DQ_PopFront(LinkedListDeque* Deque);
void DQ_PopRear(LinkedListDeque* Deque);
int DQ_GetSize(LinkedListDeque* Deque);
int DQ_IsEmpty(LinkedListDeque* Deque);

#endif // DEQUE_H