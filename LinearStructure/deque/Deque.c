#include "Deque.h"

// DQ 생성
void DQ_CreateDeque(Deque** Deque)
{
    // 덱을 자유 저장소에 할당
    (*Deque) = (Deque*)malloc(sizeof(Deque));

    // 덱 초기화
    (*Deque)->Front = NULL;
    (*Deque)->Rear = NULL;
    (*Deque)->Count = 0;
}

// DQ 소멸
void DQ_DestroyDeque(Deque* Deque)
{
    // 덱에 쌓여있는 노드를 모두 제거
    while (!DQ_IsEmpty(Deque))
    {
        Node* Popped = DQ_PopFront(Deque);
        DQ_DestroyNode(Popped);
    }

    // 덱을 자유 저장소에서 해제
    free(Deque);
}

// DQ 노드 생성
Node* DQ_CreateNode(ElementType NewData)
{
    // 노드를 자유 저장소에 할당
    Node* NewNode = (Node*)malloc(sizeof(Node));

    // 노드 초기화
    NewNode->Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;

    // 생성한 노드의 주소값 반환
    return NewNode;
}

// DQ 노드 소멸
void DQ_DestroyNode(Node* Node)
{
    free(Node);
}

// DQ 데이터 Front 삽입
void DQ_PushFront(Deque* Deque, Node* NewNode)
{
    if (Deque->Front == NULL)
    {
        Deque->Front = NewNode;
        Deque->Rear = NewNode;
    }
    else
    {
        NewNode->NextNode = Deque->Front;
        Deque->Front->PrevNode = NewNode;
        Deque->Front = NewNode;
    }

    Deque->Count++;
}

// DQ 데이터 Rear 삽입
void DQ_PushRear(Deque* Deque, Node* NewNode)
{
    if (Deque->Rear == NULL)
    {
        Deque->Front = NewNode;
        Deque->Rear = NewNode;
    }
    else
    {
        NewNode->PrevNode = Deque->Rear;
        Deque->Rear->NextNode = NewNode;
        Deque->Rear = NewNode;
    }

    Deque->Count++;
}

// DQ 데이터 Front 제거
void DQ_PopFront(Deque* Deque)
{
    Node* Front = Deque->Front;

    if (Deque->Front->NextNode == NULL)
    {
        Deque->Front = NULL;
        Deque->Rear = NULL;
    }
    else
    {
        Deque->Front = Deque->Front->NextNode;
        Deque->Front->PrevNode = NULL;
    }

    Deque->Count--;

    return Front;
}

// DQ 데이터 Rear 제거
void DQ_PopRear(Deque* Deque)
{
    Node* Rear = Deque->Rear;

    if (Deque->Rear->PrevNode == NULL)
    {
        Deque->Front = NULL;
        Deque->Rear = NULL;
    }
    else
    {
        Deque->Rear = Deque->Rear->PrevNode;
        Deque->Rear->NextNode = NULL;
    }

    Deque->Count--;

    return Rear;
}