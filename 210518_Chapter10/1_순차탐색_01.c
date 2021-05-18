/*
����Ž��

�����ϱ� ������, �ð����⵵�� �����ʴ�.
�˻��� �����Ͱ� ������ �����϶��� ���� ȿ���������� �ʴ�.
*/

#include <stdio.h>

int LSearch(int*, int, int);

int main() 
{
	int index;                                  // ã�� ���� ���°���� �����ϴ� ����
	int ary[] = { 3, 5, 8, 2, 7, 6, 1 };        // 
	int size = sizeof(ary) / sizeof(ary[0]);    // �迭�� ��� ����

	//LSearch(�迭, �迭�� ũ��, ã�����ϴ� ������); // LSearch�� ���Ͼġ�� ������

	index = LSearch(&ary, size, 2);             // �ð� ���⵵�� n
	
	if (index == -1)                            // �˻��Լ����� -1�� ��ȯ������
	{
		printf("ã�� ����!\n");
	}
	else 
	{
		printf("ã�� ���� %d��°�� �ֽ��ϴ�.\n", index);
	}

	return 0;
}

/// <summary>
/// ���Ͼ� ��ġ(���� Ž�� => �ð� ���⵵ n)
/// </summary>
int LSearch(int* pary, int sz, int tg) 
{
	for (int i = 0; i < sz; i++)  // �迭�� ũ�⸸ŭ for�� ����
	{
		if (tg == pary[i])        // �迭�� ��ҿ� ã�� ���� ������ => �迭�� ��Ұ� ���� �˻��Ϸ��� ���϶�
		{
			return i;             // �˻������� �̰� ���°������ ��ȯ
		}
	}
	return -1;                    // �˻� ���������� -1 ��ȯ
}