#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long int fact(int);

void main() 
{
	int n, result;
	printf("\n ������ �Է��ϼ��� : ");
	scanf("%d", &n);
	result = fact(n);
	printf("\n\n %d�� ���丮�� ���� %ld�Դϴ�.\n", n, result);

	return 0;
}

long int fact(int n) 
{
	int value;
	if (n <= 1) // ��������
	{
		printf("\n fact(1) �Լ� ȣ��!");
		printf("\n fact(1) �� 1 ��ȯ!");
		return 1;  // ��ȯ�� fact(2)�� ������. 
	}
	else
	{
		printf("\n fact(%d) �Լ� ȣ��!", n);
		value = (n * fact(n - 1));
		printf("\n fact(%d) �� %ld ��ȯ!!", n, value);
		return value;
	}
}

/*
1. �Լ��� ȣ���ϴ� printf�� 54321�� ��µȴ�.
2. fact(1)�϶� ��ȯ�� fact(2)�� ���������ν� ���� ��ȯ�ϴ� printf�� �����.
3. �׷��� ��°��� 54321 �Լ�ȣ��, 12345 �� ��ȯ���� ����.
*/