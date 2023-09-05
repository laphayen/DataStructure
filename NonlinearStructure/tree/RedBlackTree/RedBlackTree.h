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

// rb tree ����
void RBT_DestroyTree(RBTNode* Tree);


// ��� ����
RBTNode* RBT_CreateNode( ElementType NewData );

// ��� ����
void RBT_DestroyNode( RBTNode* Node );

// ��� ��ġ
RBTNode* RBT_SearchNode( RBTNode* Tree, ElementType Target );

// ��� �ּҰ� ��ġ
RBTNode* RBT_SearchMinNode( RBTNode* Tree );

// ��� �߰�
void RBT_InsertNode( RBTNode** Tree, RBTNode *NewNode );

// ���� Ž�� Ʈ���� ��� ������ ����
void RBT_InsertNodeHelper( RBTNode** Tree, RBTNode *NewNode );

// ��� ����
RBTNode* RBT_RemoveNode( RBTNode** Root, ElementType Target );

// ��� �߰� ���� �� ������ ���� �� Ʈ���� ��Ģ�� ����
void RBT_RebuildAfterInsert( RBTNode** Tree, RBTNode* NewNode );
void RBT_RebuildAfterRemove( RBTNode** Root, RBTNode* X );

// RB Ʈ�� �߰�
void RBT_PrintTree( RBTNode* Node, int Depth, int BlackCount );

// ��ȸ��
void RBT_RotateLeft( RBTNode** Root, RBTNode* Parent );

// ��ȸ��
void RBT_RotateRight( RBTNode** Root, RBTNode* Parent );

#endif
