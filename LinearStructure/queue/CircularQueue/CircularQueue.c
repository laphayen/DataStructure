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

    // 큐가 가득찬 경우
    if (CQ_IsFull(Queue))
    {
        printf("Queue is Full\n");
        return;
    }
    
    // Rear가 Capacity에 도달하면 배열의 인덱스 처음으로 변경
    if (Queue->Rear == Queue->Capacity)
    {
        Position = Queue->Rear;
        Queue->Rear = 0;
    }
    // Rear가 Capacity에 도달하지 않았다면 Rear를 증가
    else
    {
        Position = Queue->Rear++;
    }
    
    // Rear에 데이터 삽입
    Queue->Nodes[Position].Data = Data;
}

// CQ 데이터 삭제
ElementType CQ_Dequeue(CircularQueue* Queue)
{
    int Position = Queue->Front;

    // 큐가 비어있는 경우
    if (CQ_IsEmpty(Queue))
    {
        printf("Queue is Empty\n");
        return 0;
    }

    // Front가 Capacity에 도달하면 배열의 인덱스 처음으로 변경
    if (Queue->Front == Queue->Capacity)
    {
        Queue->Front = 0;
    }
    // Front가 Capacity에 도달하지 않았다면 Front를 증가
    else
    {
        Queue->Front++;
    }

    // Front에 있는 데이터 반환
    return Queue->Nodes[Position].Data;
}

// CQ 크기 반환
int CQ_GetSize(CircularQueue* Queue)
{
    if(Queue->Front <= Queue->Rear)
    {
        return Queue->Rear - Queue->Front;
    }
    // 배열에서 Rear가 Front보다 앞에 있는 경우
    else
    {
        return Queue->Capacity - (Queue->Front - Queue->Rear) + 1;
    }
}

// CQ 비여있는지 확인
int CQ_IsEmpty(CircularQueue* Queue)
{
    return (Queue->Front == Queue->Rear);
}

// CQ 가득차있는지 확인
int CQ_IsFull(CircularQueue* Queue)
{
    // 배열에서 Rear가 Front보다 뒤에 있는 경우
    if (Queue->Front < Queue->Rear)
    {
        return (Queue->Rear - Queue->Front) == Queue->Capacity;
    }
    // 배열에서 Rear가 Front보다 앞에 있는 경우
    else
    {
        return (Queue->Rear + 1) == Queue->Front;
    }
}