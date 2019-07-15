//==============================================================
// 콘솔 워드 프로그램
//==============================================================
#include <stdio.h>
#include <malloc.h>
#include <string.h>

//==============================================================
typedef struct node
{
	char word[20];	// 문자열 !! 
	struct node * next; 
	struct node * prev; 
}NODE;

NODE * head, *tail;

void insertList(NODE * Where, NODE * newNode)
{
	newNode->next = Where->next;
	newNode->prev = Where;
	Where->next->prev = newNode;
	Where->next = newNode;
}
//==============================================================
void show()
{
	NODE *p;
	printf("[Result] ");
	for (p = head->next; p != tail; p = p->next)
	{
		printf("%s ", p->word);
	}
	puts("");
}

//==============================================================
void  insertWord(char * word)  //insert명령시 단어 추가 !! 
{
	NODE * newNode = (NODE*)malloc(sizeof(NODE)); 
	strcpy(newNode->word, word); // 문자열 복사 !! 
	insertList(tail->prev, newNode);

}

//  리스트 초기화  head->tail  
void init()
{
	head = (NODE*)calloc(1, sizeof(NODE));
	tail = (NODE*)calloc(1, sizeof(NODE));
	head->next = tail;
	head->prev = head;
	tail->prev = head;
	tail->next = tail;
	//  head      tail
	//	[    ] --> [    ]
	//  [    ] <-- [    ]
}
void main()
{
	char cmd[32] = {0}; // 명령어 
	init();
	while (1)
	{ 
		gets_s(cmd); 
		if (strncmp("insert", cmd, 6) == 0)
		{ 
			insertWord(cmd + 7); 
			show();
		}
		else if( )
	}
}