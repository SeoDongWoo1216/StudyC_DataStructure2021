/*
포인터배열 : 여러개의 포인터를 하나의 배열로 구성한 것
배열과 포인터의 특징을 모두 활용할 수 있다.

각 배열 요소는 포인터가되고, 2차원 문자배열을 1차원 포인터배열로 표현할 수 있다.
이때 2차원 배열의 행의 개수는 포인터배열의 크기가되고, 
포인터배열의 각 배열 요소는 각 문자열에 대한 시작 주소를 가진 포인터가 된다.
*/

#include <stdio.h>

void main() 
{
	int i;
	char* ptrArray[4] = { {"Korea"},{"Seoul"},{"Mapo"}, {"152번지 2 / 3"} };
	for (i = 0; i < 4; i++) 
	{
		printf("\n %s", ptrArray[i]);
	}

	ptrArray[2] = "Jongno";       // 포인터 변수니까 가능한 구문
	printf("\n\n");
	for (i = 0; i < 4; i++) 
	{
		printf("\n %s", ptrArray[i]);
	}

	getchar();


	return 0;
}