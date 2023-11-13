#include "LinkedQueue.h"

// LQ 생성
void LQ_CreateQueue(LinkedQueue** Queue)
{
	// 큐를 자유저장소에 할당
	(*Queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));

	// 큐 Front, Rear, Count 초기화
	(*Queue)->Front = NULL;
	(*Queue)->Rear = NULL;
	(*Queue)->Count = 0;
}

// LQ 소멸
void LQ_DestroyQueue(LinkedQueue* Queue)
{
	// 큐의 노드를 자유 저장소에서 해제
	while (!LQ_IsEmpty(Queue))
	{
		Node* Popped = LQ_Dequeue(Queue);
		LQ_DestroyNode(Popped);
	}

	free(Queue);
}

// LQ 노드 생성
Node* LQ_CreateNode(char* NewData)
{
	// 노드를 자유 저장소에 할당
	Node* NewNode = (Node*)malloc(sizeof(Node));
	
	// 노드 초기화
	NewNode->Data = NewData;
	NewNode->NextNode = NULL;

	// 생성한 노드의 주소값 반환
	return NewNode;
}

// LQ 노드 소멸
void LQ_DestroyNode(Node* _Node)
{
	free(_Node);
}

// LQ 데이터 삽입
void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode)
{
	// 노드가 없을 경우(큐가 빈 경우)
	if (Queue->Front == NULL)
	{
		Queue->Front = NewNode;
		Queue->Rear = NewNode;
		Queue->Count++;
	}
	// Rear 노드의 다음 노드로 삽입
	else
	{
		Queue->Rear->NextNode = NewNode;
		Queue->Rear = NewNode;
		Queue->Count++;
	}
}

// LQ 데이터 제거
Node* LQ_Dequeue(LinkedQueue* Queue)
{
	Node* Front = Queue->Front;

	// 노드가 한 개인 경우
	if (Queue->Front->NextNode == NULL)
	{
		Queue->Front = NULL;
		Queue->Rear = NULL;
	}
	// 큐의 Front를 다음 노드로 변경
	else
	{
		Queue->Front = Queue->Front->NextNode;
	}

	Queue->Count--;

	return Front;
}

// LQ가 비어있는지 확인
int LQ_IsEmpty(LinkedQueue* Queue)
{
	return (Queue->Front == NULL);
}