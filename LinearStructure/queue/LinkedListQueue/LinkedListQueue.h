#ifndef LINKED_LIST_QUEUE_H
#define LINKED_LIST_QUEUE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int ElementType;

// 연결 리스트 큐 노드 구조체
typedef struct Node
{
	ElementType Data;
	struct Node* NextNode;
} Node;

// 연결 리스트 큐 구조체
typedef struct LinkedListQueue
{
	Node* Front;
	Node* Rear;
	int Count;
} LinkedListQueue;

void LLQ_CreateQueue(LinkedListQueue** Queue);
void LLQ_DestroyQueue(LinkedListQueue* Queue);

Node* LLQ_CreateNode(char* NewData);
void LLQ_DestroyNode(Node* Node);

void LLQ_Enqueue(LinkedListQueue* Queue, Node* NewNode);
Node* LLQ_Dequeue(LinkedListQueue* Queue);
int LLQ_IsEmpty(LinkedListQueue* Queue);

#endif // LINKED_LIST_QUEUE_H