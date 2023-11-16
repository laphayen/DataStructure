#include "Deque.h"

// DQ 생성
void DQ_CreateDeque(LinkedListDeque** Deque)
{
    // 덱을 자유 저장소에 할당
    (*Deque) = (LinkedListDeque*)malloc(sizeof(LinkedListDeque));

    // 덱 초기화
    (*Deque)->Front = NULL;
    (*Deque)->Rear = NULL;
    (*Deque)->Count = 0;
}

// DQ 소멸
void DQ_DestroyDeque(LinkedListDeque* Deque)
{
    Node* Current = Deque->Front;
    Node* Next = NULL;

    // 덱의 노드를 자유 저장소에서 해제
    while (Current != NULL)
    {
        Next = Current->NextNode;
        DQ_DestroyNode(Current);
        Current = Next;
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
void DQ_PushFront(LinkedListDeque* Deque, Node* NewNode)
{
    // 노드가 없을 경우(덱이 빈 경우)
    if (Deque->Front == NULL)
    {
        Deque->Front = NewNode;
        Deque->Rear = NewNode;
    }
    // Front 노드의 이전 노드로 삽입
    else
    {
        NewNode->NextNode = Deque->Front;
        Deque->Front->PrevNode = NewNode;
        Deque->Front = NewNode;
    }

    // 덱의 노드 개수 증가
    Deque->Count++;
}

// DQ 데이터 Rear 삽입
void DQ_PushRear(LinkedListDeque* Deque, Node* NewNode)
{
    // 노드가 없을 경우(덱이 빈 경우)
    if (Deque->Rear == NULL)
    {
        Deque->Front = NewNode;
        Deque->Rear = NewNode;
    }
    // Rear 노드의 다음 노드로 삽입
    else
    {
        NewNode->PrevNode = Deque->Rear;
        Deque->Rear->NextNode = NewNode;
        Deque->Rear = NewNode;
    }

    // 덱의 노드 개수 증가
    Deque->Count++;
}

// DQ 데이터 Front 제거
void DQ_PopFront(LinkedListDeque* Deque)
{
    Node* Front = Deque->Front;

    // 노드가 한 개인 경우
    if (Deque->Front->NextNode == NULL)
    {
        Deque->Front = NULL;
        Deque->Rear = NULL;
    }
    // 덱의 Front를 다음 노드로 변경
    else
    {
        Deque->Front = Deque->Front->NextNode;
        Deque->Front->PrevNode = NULL;
    }

    // 덱의 노드 개수 감소
    Deque->Count--;

    // 제거한 노드의 주소값 반환
    return Front;
}

// DQ 데이터 Rear 제거
void DQ_PopRear(LinkedListDeque* Deque)
{
    Node* Rear = Deque->Rear;

    // 노드가 한 개인 경우
    if (Deque->Rear->PrevNode == NULL)
    {
        Deque->Front = NULL;
        Deque->Rear = NULL;
    }
    // 덱의 Rear를 이전 노드로 변경
    else
    {
        Deque->Rear = Deque->Rear->PrevNode;
        Deque->Rear->NextNode = NULL;
    }

    // 덱의 노드 개수 감소
    Deque->Count--;

    // 제거한 노드의 주소값 반환
    return Rear;
}

// DQ 크기 반환
int DQ_GetSize(LinkedListDeque* Deque)
{
    return Deque->Count;
}

// DQ 비어있는지 확인
int DQ_IsEmpty(LinkedListDeque* Deque)
{
    return (Deque->Front == NULL);
}