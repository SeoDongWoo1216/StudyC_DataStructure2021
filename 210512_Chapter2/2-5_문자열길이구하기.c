// ���ڿ��� �Է¹ް� ���ڿ� ���, ���ڿ� ���� ���

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() 
{
	char input[50];
	int cnt = 0;
	printf("���ڿ��� �Է��ϼ��� : $");
	// scanf("%s", input);       // �����ϸ� �ű������ ����
	gets(input);                 // ������� ���� ���� 

	printf("�Է��� ���ڿ� : ");

	/*
	for (int i = 0; i < strlen(input); i++)
	{
		printf("%c", input[i]);
		cnt++;
	}
	*/

	// ���ǽĿ� input[i]
	// NULL => �ƽ�Ű�ڵ� ���� 0  -> ���ǽ��� ����
	// ���� �Է��� ���ڿ��� �������� NULL�� ä��ϱ� �������� �Ǻ���.
	for (int i = 0; i < input[i]; i++)
	{
		printf("%c", input[i]);
		cnt++;
	}
	printf("\n���ڿ��� ���� : %d\n", cnt);
	return 0;
}