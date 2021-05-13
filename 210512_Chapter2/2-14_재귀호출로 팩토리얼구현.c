#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long int fact(int);

void main() 
{
	int n, result;
	printf("\n 정수를 입력하세요 : ");
	scanf("%d", &n);
	result = fact(n);
	printf("\n\n %d의 팩토리얼 값은 %ld입니다.\n", n, result);

	return 0;
}

long int fact(int n) 
{
	int value;
	if (n <= 1) // 기저조건
	{
		printf("\n fact(1) 함수 호출!");
		printf("\n fact(1) 값 1 반환!");
		return 1;  // 반환을 fact(2)에 던져줌. 
	}
	else
	{
		printf("\n fact(%d) 함수 호출!", n);
		value = (n * fact(n - 1));
		printf("\n fact(%d) 값 %ld 반환!!", n, value);
		return value;
	}
}

/*
1. 함수를 호출하는 printf를 54321이 출력된다.
2. fact(1)일때 반환을 fact(2)로 보내줌으로써 값을 반환하는 printf가 실행됨.
3. 그래서 출력값이 54321 함수호출, 12345 값 반환으로 나옴.
*/