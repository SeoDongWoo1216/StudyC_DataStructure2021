#include <stdio.h>

int main() 
{
	// �迭 ũ��� 5���� ����������, �ʱ�ȭ�� 3���������� �������� 0���� ä�����°��� Ȯ���ϴ� ����
	int iarr[5] = {1, 2, 3};
	for (int i = 0; i < sizeof(iarr) / sizeof(iarr[0]); i++) // sizeof(�迭) / sizeof(�迭ù��°���) = �迭 ��� ����
	{
		printf("'%d'\n", iarr[i]);
	}
	printf("\n");


	// char�� �迭���� �Ȱ��� ����Ǵ��� Ȯ���غ���.
	char carr[5] = { 'a', 'b', 'c' };
	for (int i = 0; i < sizeof(carr) / sizeof(carr[0]); i++)   // ���ڷ� ���
	{
		printf("'%c'\n", carr[i]);  // 'a', 'b', 'c', ' ', ' ' ��� ' '�� NULL�����̴�.
	}
	printf("\n");
	
	
	// char�� �迭�� 10������ ����غ���.
	for (int i = 0; i < sizeof(carr) / sizeof(carr[0]); i++)   // 10������ ���
	{
		printf("'%d'\n", carr[i]);  // 97, 98, 99, 0, 0 ���
	}

	return 0;
}

// �ڷ��������� �ʱ�ȭ�� �ٸ��� �ȴٴ� ���� ���
// int���� ��������� �⺻������ 0���� ä��µ�, char���� NULL���ڷ� �ڵ����� �ʱ�ȭ�ȴ�.