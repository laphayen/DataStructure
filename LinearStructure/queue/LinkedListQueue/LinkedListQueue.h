#ifndef LINKED_LIST_QUEUE_H
#define LINKED_LIST_QUEUE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 큐 데이터 타입 정의
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
	Node* Front;	// 큐의 전단 노드
	Node* Rear;		// 큐의 후단 노드
	int Count;		// 큐의 노드 개수
} LinkedListQueue;

void LLQ_CreateQueue(LinkedListQueue** Queue);
void LLQ_DestroyQueue(LinkedListQueue* Queue);

Node* LLQ_CreateNode(char* NewData);
void LLQ_DestroyNode(Node* Node);

void LLQ_Enqueue(LinkedListQueue* Queue, Node* NewNode);
Node* LLQ_Dequeue(LinkedListQueue* Queue);
int LLQ_IsEmpty(LinkedListQueue* Queue);

#endif // LINKED_LIST_QUEUE_H