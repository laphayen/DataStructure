#include "CircularQueue.h"

// CQ 생성
void CQ_CreateQueue(CircularQueue** Queue, int Capacity)
{
    // 원형 큐를 자유 저장소에 할당
    (*Queue) = (CircularQueue*)malloc(sizeof(CircularQueue));
     
    // 노드 배열을 자유 저장소에 할당 - 더미 노드 추가
    (*Queue)->Nodes = (Node*)malloc(sizeof(Node)* (Capacity+1));

    // 원형 큐 초기화
    (*Queue)->Capacity = Capacity;
    (*Queue)->Front = 0;
    (*Queue)->Rear = 0;
}

// CQ 소멸
void CQ_DestroyQueue(CircularQueue* Queue)
{
    // 노드 배열을 자유 저장소에서 해제
    free(Queue->Nodes);
    free(Queue);
}

// CQ 데이터 삽입
void CQ_Enqueue(CircularQueue* Queue, ElementType Data)
{
    int Position = 0;

    // Rear가 Capacity에 도달하면 배열의 인덱스 처음
    if (Queue->Rear == Queue->Capacity)
    {
        Position = Queue->Rear;
        Queue->Rear = 0;
    }
    // Rear가 Capacity에 도달하지 않았다면 Rear를 증가
    else
        Position = Queue->Rear++;
    
    Queue->Nodes[Position].Data = Data;
}

ElementType CQ_Dequeue(CircularQueue* Queue)
{
    int Position = Queue->Front;

    if (Queue->Front == Queue->Capacity)
        Queue->Front = 0;
    else
        Queue->Front++;

    return Queue->Nodes[Position].Data;
}

int CQ_GetSize(CircularQueue* Queue)
{
    if(Queue->Front <= Queue->Rear)
        return Queue->Rear - Queue->Front;
    // 리어가 앞으로 오면 처리하는 방법
    else
        return Queue->Front + (Queue->Capacity - Queue->Front) + 1;
}

int CQ_IsEmpty(CircularQueue* Queue)
{
    return (Queue->Front == Queue->Rear);
}

int CQ_IsFull(CircularQueue* Queue)
{
    if (Queue->Front < Queue->Rear)
        return (Queue->Rear - Queue->Front) == Queue->Capacity;
    else
        return (Queue->Rear + 1) == Queue->Front;
}
