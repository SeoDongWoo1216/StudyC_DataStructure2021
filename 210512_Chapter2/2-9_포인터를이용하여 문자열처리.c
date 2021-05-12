
#include<stdio.h>

int main() 
{
	int i;
	char string1[20] = "Dreams come true!";
	char string2[20];
	char* ptr1, * ptr2;

	ptr1 = string1;
	printf("\n string1의 주소 : %u \t ptr1 = %u", string1, ptr1); // string1 주소와 ptr1의 주소 출력
	printf("\n string1 = %s \n ptr1 = %s", string1, ptr1);  // string1의 값들과 ptr1이 가리키는 문자열 출력
	printf("\n\n %s", ptr1 + 7);  // 배열 7번째 방부터 출력
	
	ptr2 = &string1[7];
	printf("\n %s \n\n", ptr2);

	for (i = 16; i >= 0; i--)  // 문자열 맨 끝에서부터 맨처음까지 하나씩 출력(거꾸로출력)
	{
		putchar(*(ptr1 + i));
	}

	for (i = 0; i < 20; i++)   // string2에 stinrg1의 배열요소를 하나씩 저장
	{
		string2[i] = *(ptr1 + i);
	}

	printf("\n\n string1 = %s", string1);  // string1 출력
	printf("\n string2 = %s", string2);    // stirng2 출력


	*ptr1 = 'P';
	*(ptr1 + 1) = 'e';
	*(ptr1 + 2) = 'a';
	*(ptr1 + 3) = 'c';
	*(ptr1 + 4) = 'e';
	printf("\n\n string1 = %s\n", string1);

	return 0;
}