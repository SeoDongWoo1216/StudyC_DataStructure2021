/*
포인터는 주소이다.
&는 주소연산자로, 변수의 주소를 얻는데 사용한다.
*는 참조연산자로, 저장된 주소에있는 값(변수에 저장된 값)을 액세스하는 연산자이다. 

int a;
int* pa = &a;  // 변수명이 pa이며 자료형이 int*임.
pa가 주소값을 가지고있다 => 포인터가 a를 가리키고있다. 로 표현
*는 '나는포인터입니다' 의 표시이다.
*/


#include <stdio.h>

int main() 
{
	int i = 10, j = 20;
	int* ptr;

	printf("\n i의 값 : %d \n j의 값 : %d", i, j);
	printf("\n i의 메모리 주소(&i) : %u", &i);
	printf("\n j의 메모리 주소(&j) : %u", &j);

	ptr = &i;
	printf("\n\n << ptr = &i 실행 >>");
	printf("\n ptr의 메모리 주소(&ptr) = %u", &ptr);
	printf("\n ptr의 값(ptr) = %u", ptr);
	printf("\n ptr의 참조값(*ptr) = %d", *ptr);

	ptr = &j;
	printf("\n\n << ptr = &j 실행 >>");
	printf("\n ptr의 메모리 주소(&ptr) = %u", &ptr);
	printf("\n ptr의 값(ptr) = %u", ptr);
	printf("\n ptr의 참조값(*ptr) = %d", *ptr);

	i = *ptr;
	printf("\n\n << i = *ptr 실행 >>");
	printf("\n i의 값 = %d\n", i);

	return 0;
}

