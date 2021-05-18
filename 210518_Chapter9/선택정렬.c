/*
선택정렬 : 0번방을 최소값이라고 가정.
0번방과 다음방들을 비교한 다음에, 최소값을 찾으면 그 값을 0번방에 넣어줌.

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
/// 선택 정렬 함수
/// </summary>
void selectSort(int* pary, int size) 
{
	int min;            // 최소값 변수
	int i, j, k, temp;

	for (i = 0; i < size - 1; i++)     
	{
		min = i;                      // min은 0부터 시작
		for (j = i+1; j < size; j++)  // 제일 낮은 값을 찾았으니 맨 앞과 바꿈
		{
			if (pary[min] > pary[j])  // 맨 첫번째 값이 더 클 경우
			{
				min = j;
			}
		}

		printf("%d단계 : ", i);   // 정렬 과정을 출력
		for (k = 0; k < size; k++)
		{
			printf("%d ", pary[k]);
		}
		printf("\n");

		temp = pary[min];             // 정렬 알고리즘
		pary[min] = pary[i];          // 가장 낮은 최소값이 i번째에 저장됨
		pary[i] = temp;


		
		
	}

}