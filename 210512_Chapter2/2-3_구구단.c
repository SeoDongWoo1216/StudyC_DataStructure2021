// �Է¹��� ������ �������� ����ϴ� ���α׷�(��������)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() 
{
	while (1) 
	{
		int input = 0;
		printf("�������� ����� ���� �Է�(1~9����) : $");
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
			printf("\n1~9������ ������ �Է����ּ���. �����մϴ�.\n");
			break;
		}
		printf("\n");
	}
	
	return 0;
}