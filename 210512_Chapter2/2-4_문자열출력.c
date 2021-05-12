// 문자 배열에 문자열을 저장하고 출력하기
/*
char s1[] = "string";      // 널문자가 저절로 저장됨
char s2[] = {'s','t','r','i','n','g'}; // 널문자가 저장될 공간이 없음

초기화방법은 여러가지가있지만 s1처럼 초기화하는게 더 편하다.
*/

#include <stdio.h>

void main() 
{
	char str[20] = "Data Structure!";
	int i;
	int cnt = 0;
	printf("\n문자 배열 str[] : ");
	for (i = 0; str[i]; i++) 
	{
		cnt++;
		printf("%c", str[i]);
	}
	printf("\n\nfor문 돌려진 횟수 : %d", cnt);
	getchar();
}