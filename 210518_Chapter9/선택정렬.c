/*
�������� : 0������ �ּҰ��̶�� ����.
0����� ��������� ���� ������, �ּҰ��� ã���� �� ���� 0���濡 �־���.

*/

#include <stdio.h>

void selectSort(int*, int);

int main() 
{
	int ary[] = { 4, 3, 7, 5, 9, 1, 8, 2, 6 };

	// int ary[] = { 7, 2, 9, 5, 1, 4, 8, 3, 6 };
	int size = sizeof(ary) / sizeof(ary[0]);
	selectSort(ary, size);

	return 0;
}

/// <summary>
/// ���� ���� �Լ�
/// </summary>
void selectSort(int* pary, int size) 
{
	int min;            // �ּҰ� ����
	int i, j, k, temp;

	for (i = 0; i < size - 1; i++)     
	{
		min = i;                      // min�� 0���� ����
		for (j = i+1; j < size; j++)  // ���� ���� ���� ã������ �� �հ� �ٲ�
		{
			if (pary[min] > pary[j])  // �� ù��° ���� �� Ŭ ���
			{
				min = j;
			}
		}

		printf("%d�ܰ� : ", i);   // ���� ������ ���
		for (k = 0; k < size; k++)
		{
			printf("%d ", pary[k]);
		}
		printf("\n");

		temp = pary[min];             // ���� �˰���
		pary[min] = pary[i];          // ���� ���� �ּҰ��� i��°�� �����
		pary[i] = temp;


		
		
	}

}