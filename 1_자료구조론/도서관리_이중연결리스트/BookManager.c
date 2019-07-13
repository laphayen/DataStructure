#include <stdio.h>
#include <malloc.h> 
//===================================================
// 구조체 선언 
//===================================================
typedef struct book
{
	char title[256];		// 제목 
	char writer[20];	    // 저자 
}BOOK;
//===================================================
typedef struct node
{
	BOOK bookinfo; 
	struct node * next; 
	struct node * prev;
}NODE;
//===================================================
// 전역 변수 선언 !! 
NODE * head, *tail;
//===================================================
// 함수 선언부 !! 
//===================================================
void init();	//  리스트 초기화  head->tail   
void BookInput(); // 도서 입력 !! 
void BookShow();	// 도서 출력 
//===================================================
void main()
{
	int input = 0; 
	init(); // head,  tail 초기화 !! 
	while (1)
	{
		puts(" 도서관리 프로그램  v 1.0 ");
		puts("1. 도서 입력");
		puts("2. 도서 출력"); 
		puts("0. 종료"); 
		scanf("%d", &input);

		switch (input)
		{
		case 1:  BookInput();      break;
		case 2:  BookShow();   	break;
		case 3:  exit(0);             break;
		}
	}

}

// 도서 입력 함수 
void BookInput( )
{
	NODE * newNode = (NODE*)malloc(sizeof(NODE)); 
	// 도서 정보 입력 !! 
	getchar();
	printf("도서 이름 :");
	gets(newNode->bookinfo.title); 
	printf("저자 : ");
	gets(newNode->bookinfo.writer); 
	// 맨앞에 삽입하게 구현...  
	newNode->next = head->next;
	newNode->prev = head;
	head->next->prev = newNode;
	head->next = newNode; 
	// 맨뒤에 삽입 !! 
/*	newNode->prev = tail->prev;
	newNode->next = tail;
	tail->prev->next = newNode;
	tail->prev = newNode; 
*/
}
// 도서 전체 출력 함수 !! 
void BookShow()
{
	NODE * p = head->next; 
	while (p != tail)
	{
		printf("제목 : %s  저자 : %s\n", p->bookinfo.title, 
											p->bookinfo.writer);
		p = p->next;
	}
}
//  리스트 초기화  head->tail  
void init()
{
	head = (NODE*)calloc(1, sizeof(NODE)); 
	tail  = (NODE*)calloc(1, sizeof(NODE));
	head->next = tail;
	head->prev = head; 
	tail->prev = head;
	tail->next = tail;	
	//  head      tail
	//	[    ] --> [    ]
	//  [    ] <-- [    ]
}