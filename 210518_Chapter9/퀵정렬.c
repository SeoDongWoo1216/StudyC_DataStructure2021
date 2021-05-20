/*
������ : ��ǥ���� ���� ���� �˰���(�ð� ���⵵�� ���� ����)
���ĵǾ������� �������� ����ϸ� ����Ʈ�� ������ ���� �� ����.
���ĵ������� ���������� �� ����

1. ���ҵ� �߿��� pivot(����)�� ����.
2. �� pivot�� �������� �տ��� ���� ��, �ڿ��� ū ������ ��ġ��Ų��.(����)
3. ���ҵ� ���� ����Ʈ���� ��������� ������ ��Ų��.(����)
4. ���ĵ� ���� ����Ʈ���� �����Ѵ�.(����)

�Ǻ��� �������� ���ʿ��� ������, �����ʿ��� ū������ ��ġ�� �ٲٸ鼭 �����.
������� ������ ���⶧���� ���������� �ʿ�.
*/

#include <stdio.h>

void quickSort(int*, int, int);

int main()
{
	int ary[] = { 3, 5, 2, 4, 7, 6, 1, 8 };
	int size = sizeof(ary) / sizeof(ary[0]);
	printf("ary[] : 3, 5, 2, 4, 7, 6, 1, 8 \n\n");

	quickSort(ary, 0, size - 1);


	/*for (int i = 0; i < size; i++)
	{
		printf("%d  ", ary[i]);
	}
	printf("\n");*/

	return 0;
}


/// <summary>
/// ������ �Լ�
/// </summary>
void quickSort(int* pary, int left, int right)
{
	int lidx = left;     // lidx = left = 0
	int ridx = right;    // ridx = right = size - 1   ( lidx, ridx �� index�� ��Ÿ��.)
	int temp;
	int pivot = (left + right) / 2;  //  (n/2)�� �Ǻ� ����

	printf("pivot - index : %d, value : %d\n", pivot, pary[pivot]);

	while (lidx <= ridx)                   // lidx�� ridx�� �����Ǳ� ������ ����
	{
		while (pary[lidx] < pary[pivot])   // �Ǻ��� ���� ����Ʈ �� ���� ���� ���
		{
			lidx++;
		}
		while (pary[ridx] > pary[pivot])   // �Ǻ��� ������ ����Ʈ �� ū ���� ���
		{
			ridx--;
		}
		if (lidx <= ridx)                  // ������ ������ �Ǹ�(lidx == ridx�̸� �Ǻ����̴�)
		{
			temp = pary[ridx];             // ���� �˰���
			pary[ridx] = pary[lidx];
			pary[lidx] = temp;
			printf("%d : %d\n", temp, pary[ridx]);
			lidx++;
			ridx--;
		}
	}
	for (int i = 0; i <= right; i++) 
	{
		printf("%3d", pary[i]);
	}
	printf("\n");

	if (left < ridx) 
	{
		quickSort(pary, left, ridx);       // �Ǻ����� ���ʰ� ����
	}

	if (lidx < right) 
	{
		quickSort(pary, lidx, right);      // �Ǻ����� �����ʰ� ����
	}
}





/*
// �����ð��� �ߴ���
if (left >= right)
	{
		return;
	}
	int i, temp;
	int pivot = left;
	int lleft = pivot + 1;   // 0�� �ε����� ���Ҹ� �������� ���������� ���鼭 ã��.
	int lright = right;      // �ǳ��������� ���� ���� ã�� ģ��

	while (lleft <= lright)  // ��ü�� �ȵɶ����� ����(��ü �ȵǸ� while�� ��������)
	{

		while (pary[lleft] <= pary[pivot])   // ���ʰ��� �Ǻ����� �۴� => ������ �Ǿ���. => lleft�� �̵�
		{
			lleft++;   // ���ʿ��� �������̵��̴� ++�� ����
		}
		while (pary[lright] >= pary[pivot] && lright > left)
		// �����ʰ��� �Ǻ����� ũ�� => ������ �Ǿ���. => lright�� �̵�
	   // && lright ������ �ε��� ������ �������� �̵��Ҷ� �迭 ũ�⸦ ����� �ʰ����ִ� ����(lright�� ������ �����ʵ��� ����)

		{
			lright--;  // �����ʿ��� �����̵��̴� --�� ����
		}

		if (lleft > lright)   // �����ʰ� ���ʾְ� ��ü������
		{
			temp = pary[lright];           // �������� �Ǻ��� ��ü����
			pary[lright] = pary[pivot];
			pary[pivot] = temp;
		}
		else                  // ��ü�� ��������
		{
			temp = pary[lright];
			pary[lright] = pary[lleft];
			pary[lleft] = temp;
		}
		// �ܰ躰�� ���ĵǴ��� Ȯ���Ϸ��� ��¹�
		for (i = 0; i <= right; i++)
		{
			printf("%d  ", pary[i]);
		}
		printf("\n");
	}


	quickSort(pary, left, lright - 1);   // while���� �������� �Ŀ� ������ �����ϴ� ����(Ű�� ����)

	quickSort(pary, lright + 1, right);   // �Ǻ��� �������� �������� ����(Ű�� ������)

*/

/*
���ʿ��� ���������ΰ����� �ε����� �� ū �� ã��
�����ʿ��� �������� ������ �ε����� �� ���� ���� ã��


'3'  5  2  4  7  6  1

3�� �Ǻ����� ����
3�� lleft�� 3������� ,1�� lright�� ���� ���¿��� ���� ������

'3' 1  2  4  7  6  5

3���� ���������� ��� �̵��ϸ鼭 �� => 3���� ���� 2�� ã�� �ڸ��� �ٲ���

2  1 '3' 4  7  6  5

�Ǻ� 3�� �������� ����, �������� ���ȣ�������� ���Ľ�Ŵ


*/