#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

// 노드 구조체
typedef struct Node
{
    ElementType Data;
} Node;

// 원형 큐 구조체
typedef struct CircularQueue
{
    int Capacity;   // 큐의 용량
    int Front;      // 큐의 전단 
    int Rear;       // 큐의 후단
    Node* Nodes;    // 노드 배열
} CircularQueue;

// 원형 큐 함수
void CQ_CreateQueue(CircularQueue** Queue, int Capacity);
void CQ_DestroyQueue(CircularQueue* Queue);
void CQ_Enqueue(CircularQueue* Queue, ElementType Data);
ElementType CQ_Dequeue(CircularQueue* Queue);
int CQ_GetSize(CircularQueue* Queue);
int CQ_IsEmpty(CircularQueue* Queue);
int CQ_IsFull(CircularQueue* Queue);

#endif // CIRCULAR_QUEUE_H