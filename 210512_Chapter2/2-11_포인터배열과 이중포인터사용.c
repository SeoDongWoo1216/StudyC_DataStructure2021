/*
이중포인터
포인터가 포인터를 가리고있는 포인터, 일반 변수의 주소가 아니라 
포인터의 주소를 가지고 있는 포인터를 의미한다.

포인터배열을 함수의 인수로줄때 받는 함수는 이중포인터로 받아야한다.
int * ary[3];
func(ary);

void func(int **p){}  로 받아야함

// 변수 포인터
int a;
int *p = &a; 

// 1차원 배열을 가리키는 포인터
int ary[3];
int *p = ary;

// 2차원 배열을 가리키는 포인터
int *ary[3][4];
int (*pary) [4];
*/

#include <stdio.h>

int main() 
{
	char* ptrArray[2];  // 포인터배열
	char** ptrptr;      // 이중포인터
	int i;

	ptrArray[0] = "Korea";
	ptrArray[1] = "Seoul";

	ptrptr = ptrArray;
	printf("\n ptrArray[0]의 주소   (&ptrArray[0]  = %u", &ptrArray[0]);
	printf("\n ptrArray[0]의 값     (ptrArray[0])  = %u", ptrArray[0]);
	printf("\n ptrArray[0]의 참조값 (*ptrArray[0]) = %c", *ptrArray[0]);
	printf("\n ptrArray[0]의 참조 문자열 (*ptrArray[0]) = %s \n", *ptrArray);

	printf("\n ptrArray[1]의 주소   (&ptrArray[1]  = %u", &ptrArray[1]);
	printf("\n ptrArray[1]의 값     (ptrArray[1])  = %u", ptrArray[1]);
	printf("\n ptrArray[1]의 참조값 (*ptrArray[1]) = %c", *ptrArray[1]);
	printf("\n ptrArray[1]의 참조 문자열 (*ptrArray[1]) = %s\n", *(ptrArray + 1));

	printf("\n ptrptr의 주소 (&ptrptr) = %u", &ptrptr);
	printf("\n ptrptr의 값   (ptrptr)  = %u", ptrptr);
	printf("\n ptrptr의 1차 참조값 (*ptrptr)  = %u", *ptrptr);
	printf("\n ptrptr의 2차 참조값 (**ptrptr) = %c", **ptrptr);
	printf("\n ptrptr의 2차 참조 문자열 (**ptrptr) = %s", *ptrptr);
	
	printf("\n\n *ptrArray[0] : ");
	for (i = 0; i < 5; i++) 
	{
		printf("%c", *(ptrArray[0] + i));
	}
	printf("\n **ptrptr : ");
	for (i = 0; i < 5; i++) 
	{
		printf("%c", *(*ptrptr + i));
	}
	printf("\n\n *ptrArray[1] : ");
	for (i = 0; i < 5; i++) 
	{
		printf("%c", *(ptrArray[1] + i));
	}
	printf("\n **(ptrptr+1) : ");
	for (i = 0; i < 5; i++) 
	{
		printf("%c", *(*(ptrptr + 1) + i));
	}

	getchar();


	return 0;
}