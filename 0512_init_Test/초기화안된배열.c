#include <stdio.h>

int main() 
{
	// 배열 크기는 5개의 방이있지만, 초기화는 3개만했을때 나머지는 0으로 채워지는것을 확인하는 예제
	int iarr[5] = {1, 2, 3};
	for (int i = 0; i < sizeof(iarr) / sizeof(iarr[0]); i++) // sizeof(배열) / sizeof(배열첫번째요소) = 배열 요소 개수
	{
		printf("'%d'\n", iarr[i]);
	}
	printf("\n");


	// char형 배열에도 똑같이 적용되는지 확인해보자.
	char carr[5] = { 'a', 'b', 'c' };
	for (int i = 0; i < sizeof(carr) / sizeof(carr[0]); i++)   // 문자로 출력
	{
		printf("'%c'\n", carr[i]);  // 'a', 'b', 'c', ' ', ' ' 출력 ' '는 NULL문자이다.
	}
	printf("\n");
	
	
	// char형 배열에 10진수로 출력해보자.
	for (int i = 0; i < sizeof(carr) / sizeof(carr[0]); i++)   // 10진수로 출력
	{
		printf("'%d'\n", carr[i]);  // 97, 98, 99, 0, 0 출력
	}

	return 0;
}

// 자료형에따라 초기화가 다르게 된다는 것을 상기
// int형은 비어있으면 기본값으로 0으로 채우는데, char형은 NULL문자로 자동으로 초기화된다.