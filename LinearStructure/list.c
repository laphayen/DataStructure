
#include <stdio.h>

#include <malloc.h>

typedef struct node
{
	int data;
	struct node * next;
}NODE;

NODE * head;
NODE * tail;

void initList()
{
	head = (NODE*)malloc(sizeof(NODE));
	tail = (NODE*)malloc(sizeof(NODE));

	head->next = tail;
	tail->next = NULL;
}

NODE * find(int key)
{
	NODE * p = head->next;

	while (p != tail)
	{
		if (p->data == key)
			return p;
		else
			p = p->next;
	}
	return NULL;
}

void insert(NODE * where, int value)
{
	NODE * newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = value;

}
