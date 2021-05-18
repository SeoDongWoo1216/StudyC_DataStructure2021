/*
삽입정렬 : 두번째 자료부터 앞 자료를 비교하여 정렬한다.

보통 for문 한번으로 01, 12, 23, 34, 45 ... 등 한번씩만 비교했었는데,
for문을 한번 더 사용해서 단계가 증가할때마다 그 전의 데이터를 훑어서 정렬을 수행한다.

4 2 7 5 9 1 8 3 6
를 예시로

4와 2를 비교해서 
4 '2'   7 5 9 1 8 3 6
2 4     7 5 9 1 8 3 6

7과 2 4를 비교해서
2 4 '7'   5 9 1 8 3 6
2 4 7     5 9 1 8 3 6

5와 2 4 7를 비교해서
2 4 7 '5'   9 1 8 3 6
2 4 5 7     9 1 8 3 6

9와 2 4 5 7를 비교해서
2 4 7 5 '9'  1 8 3 6
2 4 7 5 9    1 8 3 6

1과 2 4 7 5 9를 비교해서
2 4 7 5 9 '1'  8 3 6
1 2 4 7 5 9    8 3 6

.
.
.

최종적으로
1 2 3 4 5 6 7 8 9 를  출력하는 것이 목적.

*/



#include <stdio.h>

void insertSort(int*, int);  // 삽입 정렬 함수
void printArr(int*, int);    // 배열 출력 함수

int main() 
{
	int ary[] = { 4, 2, 7, 5, 9, 1, 8, 3, 6 };
	int size = sizeof(ary) / sizeof(ary[0]);
	//printf("---------------------------정렬 전---------------------------\n");
	//printArr(ary, size);

	insertSort(ary, size);

	//printf("---------------------------정렬 후---------------------------\n");
	//printArr(ary, size);
	return 0;
}


/// <summary>
/// 삽입 정렬 함수(j가 들어간 for문을 주목)
/// </summary>
void insertSort(int* pary, int sz) 
{
	int temp;
	int i, j, k;

	for (i = 1; i < sz; i++)        // 두번째 원소를 기준으로 앞의 원소랑 비교하니까 1부터 시작
		                            // 첫 for문은 배열의 개수만큼만 실행(01, 12, 23, 34 씩 한번만 실행)
	{
		for (j = i; j > 0; j--)     // 두번째 for문은 현재 값에서 그 전의 값'들'을 비교함
			                        // 만약 j=4이면 j가 3, 2, 1, 0 인 값들을 비교해서 정렬함.
		{
			if (pary[j] < pary[j - 1])  // 앞에값이 지금 값보다 클때
			{
				temp = pary[j];         // 정렬 알고리즘 사용
				pary[j] = pary[j - 1];
				pary[j - 1] = temp;
			}
		}

		printf("%d단계 : ", i);
		for (k = 0; k < sz; k++)        // 정렬이 어떻게 되고있나 확인하는 출력문
		{
			printf("%d  ", pary[k]);
		}
		printf("\n");
	}
}


/// <summary>
/// 배열 출력 함수
/// </summary>
void printArr(int* pary, int sz) 
{
	int i;
	for (i = 0; i < sz; i++) 
	{
		printf("arr[%d] = %d\n", i, pary[i]);
	}
}