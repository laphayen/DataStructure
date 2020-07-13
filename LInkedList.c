#ifndef LINKEDLISH_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int Element Type;

typedef struct tagNode
{
	ElementType Data;
	struct tagNode* NextNode;

};
