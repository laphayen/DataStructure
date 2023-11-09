#include "CircularDoublyLinkedList.h"

Node* CDLL_CreateNode(int Data)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = Data;
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;

    return NewNode;
}

void CDLL_DestroyNode(Node* Node)
{
    free(Node);
}

void CDLL_AppendNode(Node** Head, Node* NewNode)
{
    if ((*Head) == NULL)
    {
        *Head = NewNode;
        (*Head)->NextNode = *Head;
        (*Head)->PrevNode = *Head;
    }
    else
    {
        Node* Tail = (*Head)->PrevNode;

        Tail->NextNode->PrevNode = NewNode;
        Tail->NextNode = NewNode;

        NewNode->NextNode = (*Head);
        NewNode->PrevNode = Tail;
    }
}

void CDLL_InsertNode(Node* Current, Node* NewNode)
{
    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode - Current;

    if (Current->NextNode != NULL)
    {
        Current->NextNode->PrevNode = NewNode;
        Current->NextNode = NewNode;
    }
}

void CDLL_Remove(Node** Head, Node* Remove)
{
    if (*Head == Remove)
    {
        (*Head)->PrevNode->NextNode = (*Head)->NextNode;
        (*Head)->NextNode->PrevNode = (*Head)->PrevNode;

        *Head = Remove->NextNode;

        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
    else
    {
        Node* Temp = Remove;

        Remove->PrevNode->NextNode = Temp->NextNode;
        Remove->NextNode->PrevNode = Temp->PrevNode;

        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
}

Node* CDLL_GetNode(Node* Head, int Location)
{
    Node* Current = Head;
    
    while (Current!=NULL && (--Location) >= 0)
    {
        Current = Current->NextNode;
    }
    return Current;
}

int CDLL_CountNode(Node* Head)
{
    unsigned int Count = 0;
    Node* Current = Head;

    while (Current != NULL)
    {
        Current = Current->NextNode;
        Count++;
    }

    return Count;
}