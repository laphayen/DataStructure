#include "BinarySearchTree.h"

// 트리 노드 생성
BSTNode* BST_CreateNode(ElementType NewData)
{
    // 노드를 자유저장소에 할당
    BSTNode* NewNode = (BSTNode*)malloc(sizeof(BSTNode));

    // 노드의 멤버를 초기화
    NewNode->Left = NULL;
    NewNode->Right = NULL;
    NewNode->Data = NewData;

    // 생성된 노드의 주소값을 반환
    return NewNode;
}

// 트리 노드 소멸
void BST_DestroyNode(BSTNode* Node)
{
    free(Node);
}

// 트리 소멸
void BST_DestroyTree(BSTNode* Tree)
{
    // 현재 노드의 오른쪽 자식 노드를 소멸
    if (Tree->Right != NULL)
    {
        BST_DestroyTree(Tree->Right);
    }
    // 현재 노드의 왼쪽 자식 노드를 소멸
    if (Tree->Left != NULL)
    {
        BST_DestroyTree(Tree->Left);
    }

    // 현재 노드를 소멸
    Tree->Left = NULL;
    Tree->Right = NULL;

    // 루트 노드를 소멸
    BST_DestroyNode(Tree);
}

// 트리의 노드 탐색
BSTNode* BST_SearchNode(BSTNode* Tree, ElementType Target)
{
    // 트리가 NULL인 경우
    if (Tree == NULL)
    {
        return Tree;
    }
    
    // 트리의 데이터가 찾는 데이터와 같은 경우
    if (Tree->Data == Target)
    {
        return Tree;
    }
    // 현재 트리의 데이터가 찾는 데이터보다 큰 경우
    else if (Tree->Data > Target)
    {
        return BST_SearchNode(Tree->Left, Target);
    }
    // 현재 트리의 데이터가 찾는 데이터보다 작은 경우
    else
    {
        return BST_SearchNode(Tree->Right, Target);
    }
}

// 트리의 최소 노드 탐색
BSTNode* BST_SearcMinNode(BSTNode* Tree)
{
    // 트리가 NULL인 경우
    if (Tree == NULL)
        return NULL;

    // 트리의 왼쪽 자식 노드가 없는 경우
    if (Tree->Left == NULL)
        return Tree;
    // 트리의 왼쪽 자식 노드가 있는 경우
    else
        return BST_SearchMinNode(Tree->Left);
}

// 트리의 최대 노드 탐색
BSTNode* BST_SearchMaxNode(BSTNode* Tree)
{
    // 트리가 NULL인 경우
    if (Tree == NULL)
        return NULL;

    // 트리의 오른쪽 자식 노드가 없는 경우
    if (Tree->Right == NULL)
        return Tree;
    // 트리의 오른쪽 자식 노드가 있는 경우
    else
        return BST_SearchMaxNode(Tree->Right);
}

// 트리의 노드 삽입
void BST_InsertNode(BSTNode* Tree, BSTNode *Child)
{
    // 트리의 데이터가 자식 노드의 데이터보다 큰 경우
    if (Tree->Data < Child->Data)
    {
        if (Tree->Right == NULL)
        {
            Tree->Right = Child;
        }
        else
        {
            BST_InserNode(Tree->Right, Child);
        }
    }
    // 트리의 데이터가 자식 노드의 데이터보다 작은 경우
    else if (Tree->Data > Child->Data)
    {
        if (Tree->Left == NULL)
        {
            Tree->Left = Child;
        }
        else
        {
            BST_InsertNode(Tree->Left, Child);
        }
    }
}

// 트리의 노드 삭제
BSTNode* BST_RemoveNode(BSTNode* Tree, BSTNode* Parent, ElementType Target)
{
    BSTNode* Removed = NULL;

    // 트리가 NULL인 경우
    if (Tree == NULL)
    {
        return NULL;
    }

    // 트리의 데이터가 찾는 데이터보다 큰 경우
    if (Tree->Data > Target)
    {
        Removed = BST_RemoveNode(Tree->Left, Tree, Target);
    }
    // 트리의 데이터가 찾는 데이터보다 작은 경우
    else if (Tree->Data < Target)
    {
        Removed = BST_RemoveNode(Tree->Right, Tree, Target);   
    }
    // 트리의 데이터가 찾는 데이터와 같은 경우
    else
    {
        Removed = Tree;

        // 트리의 왼쪽 자식 노드와 오른쪽 자식 노드가 모두 없는 경우
        if (Tree->Left == NULL && Tree->Right == NULL)
        {
            if (Parent->Left == Tree)
            {
                Parent->Left = NULL;   
            }
            else
            {
                Parent->Right = NULL;   
            }
        }
        else
        {
            // 트리의 왼쪽 자식 노드가 없는 경우
            if (Tree->Left != NULL && Tree->Right != NULL)
            {
                BSTNode* MinNode = BST_SearchMinNode(Tree->Right);
                MinNode = BST_RemoveNode(Tree, NULL, MinNode->Data);
                Tree->Data = MinNode->Data;
            }
            // 트리의 왼쪽 자식 노드가 있는 경우
            else
            {
                BSTNode* Temp = NULL;

                // 트리의 왼쪽 자식 노드가 있는 경우
                if (Tree->Left != NULL)
                {
                    Temp = Tree->Left;
                }
                else
                {
                    Temp = Tree->Right;
                }
                
                // 트리의 부모 노드가 있는 경우
                if (Parent->Left == Tree)
                {
                    Parent->Left = Temp;
                }
                else
                {
                    Parent->Right = Temp;
                }
            }
            
        }
    }
    
    return Removed;
}

// 트리의 노드 출력
void BST_InorderPrintTree(BSTNode* Node)
{
    if (Node == NULL)
    {
        return;
    }
    
    BST_InorderPrintTree(Node->Left);

    printf("%d ", Node->Data);

    BST_InorderPrintTree(Node->Right);
}