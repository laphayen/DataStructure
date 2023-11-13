#include "LinkedListStack.h"

// LLS 생성
void LLS_CreateStack(LinkedListStack** Stack)
{
    // 스택을 자유 저장소에 할당
    (*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));

    // 스택 초기화
    (*Stack)->List = NULL;
    (*Stack)->Top = NULL;
}

// LLS 소멸
void LLS_DestroyStack(LinkedListStack* Stack)
{
    // 스택에 쌓여있는 노드를 모두 제거
    while (!LLS_IsEmpty(Stack)) // Stack->Top != NULL
    {
        Node* Popped = LLS_Pop(Stack);
        LLS_DestroyNode(Popped);
    }

    // 스택을 자유 저장소에서 해제
    free(Stack);
}

// LLS 노드 생성
Node* LLS_CreateNode(ElementType NewData)
{
    // 노드를 자유 저장소에 할당
    Node* NewNode = (Node*)malloc(sizeof(Node));

    // 노드 초기화
    NewNode->Data = NewData;
    NewNode->Next = NULL;

    // 생성한 노드의 주소값 반환
    return NewNode;
}

// LLS 노드 소멸
void LLS_DestroyNode(Node* Node)
{
    free(Node);
}

// LLS 데이터 삽입
void LLS_Push(LinkedListStack* Stack, Node* NewNode)
{
    if (Stack->List == NULL)
    {
        Stack->List = NewNode;
    }
    else
    {
        Node* OldTop = Stack->List;

        while (OldTop->Next != NULL)
        {
            OldTop = OldTop->Next;
        }

        OldTop->Next = NewNode;
    }

    Stack->Top = NewNode;
}

// LLS 데이터 제거
Node* LLS_Pop(LinkedListStack* Stack)
{
    Node* TopNode = Stack->Top;

    if (Stack->List == Stack->Top)
    {
        Stack->List = NULL;
        Stack->Top = NULL;
    }
    else
    {
        Node* CurrTop = Stack->List;

        while (CurrTop != NULL && CurrTop->Next != Stack->Top)
        {
            CurrTop = CurrTop->Next;
        }

        Stack->Top = CurrTop;
        CurrTop->Next = NULL;
    }

    return TopNode;
}

// LLS 맨 위 노드 반환
Node* LLS_Top(LinkedListStack* Stack)
{
    return Stack->Top;
}

// LLS 크기 반환
int LLS_GetSize(LinkedListStack* Stack)
{
    int Count = 0;
    Node* Current = Stack->List;

    while(Current != NULL)
    {
        Current = Current->Next;
        Count++;
    }

    return Count;
}

// LLS 비어있는지 여부
int LLS_IsEmpty(LinkedListStack* Stack)
{
    return (Stack->List == NULL);
}