//================================================
// 배열( Array) 
//================================================
//	-> 연속된 공간에 같은 타입의 데이타들의 집합 !! 
//================================================
//   - 일반 정적 배열 : C언어 차원에서 제공해주는 배열 !! 
//  ex)  int Lotto[6]; // [ ][ ][ ][ ][ ][ ] 
//   --> int 변수 6개가 연속된 메모리 공간에 할당 !! 
//   -  가장 많이 사용하는 배열 ( 70-80%) !! 
//	 장점 : 할당이 된후에 사용된다.. 재할당이 필요없다.. -->  성능이 가장 좋다 !!
//   단점 : 크기 고정 (변화에 유연하게 대처할수 없다.)
//================================================
/*
#include <stdio.h>

// -->  static 메모리에 int 6개의 공간(24) 할당되고 시작위치의 주소 !! 이름 
int Lotto[6];

void main()
{
// -->  stack메모리에 int 6개의 공간(24) 할당되고 시작위치의 주소 !! 이름 
	int Lotto[6]; 
}
*/
//================================================
//  동적 배열 :  실행시간에 heap메모리에 배열을 동적으로 할당하여 사용 !!  
//  -->  컴파일타임(코딩할때) 크기를 예측이 불가능한 경우 !! 
//  -->  실행중에 크기의 변경이 예상될때... 
//================================================
#include <stdio.h> 
#include <malloc.h>  // malloc !! 
void main()
{ 
	int i;
	
	// -- malloc을 이용한 기본 할당 해제 코드 !! 
	int * Lotto = (int*)malloc( sizeof(int) * 6 ); //heap메모리에 24바이트를 할당 !!

	printf("%d byte \n",  _msize(Lotto) ); // Lotto의 메모리의 크기 
	for (i = 0; i < _msize(Lotto) / sizeof(int); i++)
		printf("[ %d ]", Lotto[i]);
	puts("");

	free(Lotto);  // 메모리 해제 !! 
	



	// -- calloc을 이용한 할당  + 초기화 !! 
	int * Lotto = (int*)calloc(6, sizeof(int)); // [0][0][0][0][0][0]

	printf("%d byte \n", _msize(Lotto)); // Lotto의 메모리의 크기 
	for (i = 0; i < _msize(Lotto) / sizeof(int); i++)
		printf("[ %d ]", Lotto[i]);
	puts("");

	free(Lotto);  // 메모리 해제 !! 
	


	// realloc 재할당 :  기존의 할당된 메모리를 늘리거나 줄이는것 !! 
	int * Lotto = (int*)calloc(3, sizeof(int)); // [0][0][0][0][0][0]

	printf("%d byte \n", _msize(Lotto)); // Lotto의 메모리의 크기 
	for (i = 0; i < _msize(Lotto) / sizeof(int); i++)
		printf("[ %d ]", Lotto[i]);
	puts("");


	// 현재 크기의 2배로 증가 !! 
	Lotto = (int*)realloc(Lotto, _msize(Lotto) * 2);

	for (i = 0; i < _msize(Lotto) / sizeof(int); i++)
		printf("[ %d ]", Lotto[i]);
	puts("");


	free(Lotto);  // 메모리 해제 !! 
 

}
