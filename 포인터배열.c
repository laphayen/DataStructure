//==================================================
//  포인터 배열 : 배열의 원소로 포인터를 갖는 배열 !! 
//================================================== 
// 1) 정적배열 :  크기 고정 !! 
// 2) 동적배열 : 할당과 재할당시에 속도저하 ( 퍼포먼스 )  
// 3) 포인터 배열 :  정적 +  동적 의 장점만을 취하는 배열 !! 
//==================================================
//		[	][	][	][	][	] 
//		  |	
//		[   ]
//		[   ]
//==================================================
//   C언어의 포인터 배열 == JAVA언어의 객체 배열 
//==================================================
// Person[]  people = new Person[5]; 
//==================================================
//==============================================================
/*
#include <stdio.h> 
void main()
{
	double PI = 3.14;
	double * pArr[5]; 
	printf("%d\n", sizeof(pArr)); //?? 

	pArr[0] = &PI;
	pArr[1] = (double*)calloc(1, sizeof(double)); 
	pArr[2] = (double*)calloc(1, sizeof(double));
	pArr[3] = (double*)calloc(1, sizeof(double));
	pArr[4] = (double*)calloc(1, sizeof(double));

}
*///==============================================================
// 포인터 배열과 구조체의 사용 !! 
//==============================================================
#include <stdio.h> 
#include <malloc.h>

#pragma warning(disable : 4996)
//==============================================================
typedef struct Student
{
	int sno;		  // 학번 
	char name[20];// 이름 
}STUDENT;
//==============================================================
typedef struct lib
{
	STUDENT * Seat[3][3]; // 2차원 배열 
	int  stuCount; 
}LIB;
//==============================================================
//  도서관 자리 예약 시스템 !! 
//==============================================================
void showLib( LIB GguLib )
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for ( j = 0; j < 3; j++)
		{
			if (GguLib.Seat[i][j] == NULL)
				printf("[ 빈자리 ]");
			else
				printf("[ %d ]", GguLib.Seat[i][j]->sno);
		}
		puts("");
	}
} 
// 도서관 초기화 
void initLib(LIB GguLib)
{
	int i, j;
	for ( i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			GguLib.Seat[i][j] = NULL;
		}
	}
}
void inputSeat(LIB * GguLib) // 좌석 확보 !!
{
	showLib(*GguLib);
	int x, y; 
	printf("좌석 선택 ( 가로, 세로) :"); 
	scanf("%d %d", &x, &y);
	
	GguLib->Seat[x][y] = (LIB*)malloc(sizeof(LIB));

	printf("학번 : ");
	scanf("%d", &GguLib->Seat[x][y]->sno);
	getchar();
	//fflush(stdin);
	printf("이름 :"); 
	gets(GguLib->Seat[x][y]->name); 

}


void main()
{
	LIB GguLib;

	memset(&GguLib, 0, sizeof(LIB));

	initLib(GguLib);
	showLib( GguLib );
	inputSeat(&GguLib);
	showLib(GguLib);
	
}

