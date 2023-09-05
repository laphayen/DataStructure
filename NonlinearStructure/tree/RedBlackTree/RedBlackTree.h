#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagRBTNode
{
    struct tagRBTNode* Parent;
    struct tagRBTNode* Left;
    struct tagRBTNode* Right;

    enum { RED, BLACK } Color;    

    ElementType Data;

} RBTNode;

// rb tree 제거
void RBT_DestroyTree(RBTNode* Tree);


// 노드 생성
RBTNode* RBT_CreateNode( ElementType NewData );

// 노드 삭제
void RBT_DestroyNode( RBTNode* Node );

// 노드 서치
RBTNode* RBT_SearchNode( RBTNode* Tree, ElementType Target );

// 노드 최소값 서치
RBTNode* RBT_SearchMinNode( RBTNode* Tree );

// 노드 추가
void RBT_InsertNode( RBTNode** Tree, RBTNode *NewNode );

// 이진 탐색 트리의 노드 삽입을 수행
void RBT_InsertNodeHelper( RBTNode** Tree, RBTNode *NewNode );

// 노드 제거
RBTNode* RBT_RemoveNode( RBTNode** Root, ElementType Target );

// 노드 추가 삭제 후 무너진 레드 블랙 트리의 규칙을 복원
void RBT_RebuildAfterInsert( RBTNode** Tree, RBTNode* NewNode );
void RBT_RebuildAfterRemove( RBTNode** Root, RBTNode* X );

// RB 트리 추가
void RBT_PrintTree( RBTNode* Node, int Depth, int BlackCount );

// 좌회전
void RBT_RotateLeft( RBTNode** Root, RBTNode* Parent );

// 우회전
void RBT_RotateRight( RBTNode** Root, RBTNode* Parent );

#endif
