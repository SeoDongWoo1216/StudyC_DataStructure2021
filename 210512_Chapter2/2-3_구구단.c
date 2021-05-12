// 입력받은 정수의 구구단을 출력하는 프로그램(무한으로)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() 
{
	while (1) 
	{
		int input = 0;
		printf("구구단을 출력할 정수 입력(1~9까지) : $");
		scanf("%d", &input);

		if (input <= 9 && input >= 1) 
		{
			for (int i = 1; i < 10; i++)
			{
				printf("%d * %d = %d\n", input, i, input * i);
			}
		}
		else 
		{
			printf("\n1~9까지의 정수를 입력해주세요. 종료합니다.\n");
			break;
		}
		printf("\n");
	}
	
	return 0;
}