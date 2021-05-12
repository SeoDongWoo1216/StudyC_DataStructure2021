// 문자열을 입력받고 문자열 출력, 문자열 길이 출력

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() 
{
	char input[50];
	int cnt = 0;
	printf("문자열을 입력하세요 : $");
	// scanf("%s", input);       // 띄어쓰기하면 거기까지만 저장
	gets(input);                 // 띄어쓰기까지 전부 저장 

	printf("입력한 문자열 : ");

	/*
	for (int i = 0; i < strlen(input); i++)
	{
		printf("%c", input[i]);
		cnt++;
	}
	*/

	// 조건식에 input[i]
	// NULL => 아스키코드 값이 0  -> 조건식이 거짓
	// 따라서 입력한 문자열이 끝났을때 NULL로 채우니까 거짓으로 판별함.
	for (int i = 0; i < input[i]; i++)
	{
		printf("%c", input[i]);
		cnt++;
	}
	printf("\n문자열의 길이 : %d\n", cnt);
	return 0;
}