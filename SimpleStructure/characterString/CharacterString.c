
#include <stdio.h>

void main()
{
	// char배열을 이용해 문자열 입력
	int i;
	char name[32];
	char id[12] = "11618nathan";

	printf("이  름: ");

	// 배열 &필요X
	scanf("%s", name);

	// null문자 삽입(\0) - 특수문자(escape sequence) 자동 삽입
	printf("이  름: %s \n", name);

	// 배열 크기
	printf("id 배열의 크기: %d \n", sizeof(id));

	// 널  문자 문자형
	printf("정수형: %c \n", id[12]);

	// 널  문자 정수형
	printf("정수형: %d \n", id[12]);
}
