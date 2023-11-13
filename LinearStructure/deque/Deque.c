#include "Deque.h"

// DQ 생성
void DQ_CreateDeque(LinkedDeque** Deque)
{
    // 덱을 자유 저장소에 할당
    (*Deque) = (LinkedDeque*)malloc(sizeof(LinkedDeque));

    // 덱 초기화
    (*Deque)->Front = NULL;
    (*Deque)->Rear = NULL;
    (*Deque)->Count = 0;

}

// DQ 소멸
void DQ_DestroyDeque(LinkedDeque* Deque)
{
    Node* Current = Deque->Front;
    Node* Next = NULL;

    while (Current != NULL)
    {
        Next = Current->NextNode;
        DQ_DestroyNode(Current);
        Current = Next;
    }

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
void DQ_PushFront(LinkedDeque* Deque, Node* NewNode)
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
void DQ_PushRear(LinkedDeque* Deque, Node* NewNode)
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
void DQ_PopFront(LinkedDeque* Deque)
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
void DQ_PopRear(LinkedDeque* Deque)
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