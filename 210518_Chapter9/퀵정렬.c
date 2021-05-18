/*
퀵정렬 : 대표적인 분할 정복 알고리즘(시간 복잡도가 제일 빠름)
정렬되어있을때 퀵정렬을 사용하면 퀵정렬의 성능을 얻을 수 없다.
정렬되있으면 삽입정렬이 더 빠름

1. 원소들 중에서 pivot(기준)을 고른다.
2. 이 pivot을 기준으로 앞에는 작은 값, 뒤에는 큰 값들을 위치시킨다.(분할)
3. 분할된 작은 리스트들을 재귀적으로 동작을 시킨다.(정복)
4. 정렬된 작은 리스트들을 결합한다.(결합)

피봇을 기준으로 왼쪽에는 작은값, 오른쪽에는 큰값으로 위치를 바꾸면서 사용함.
재귀적인 조건을 쓰기때문에 기저조건이 필요.
*/

#include <stdio.h>

void quickSort(int*, int, int);

int main() 
{
	int ary[] = {3, 5, 2, 4, 7, 6, 1};
	int size = sizeof(ary) / sizeof(ary[0]);
	quickSort(ary, 0, size - 1);

	for (int i = 0; i < size; i++)
	{
		printf("%d  ", ary[i]);
	}
	printf("\n");

	return 0;
}

/// <summary>
/// 퀵정렬 함수
/// </summary>
void quickSort(int* pary, int left, int right) 
{
	if (left >= right)
	{
		return;
	}
	int i, temp;
	int pivot = left;
	int lleft = pivot + 1;   // 0번 인덱스의 원소를 기준으로 오른쪽으로 가면서 찾음.
	int lright = right;      // 맨끝에서부터 작은 값을 찾는 친구

	while (lleft <= lright)  // 교체가 안될때까지 실행(교체 안되면 while문 빠져나감)
	{

		while (pary[lleft] <= pary[pivot])   // 왼쪽값이 피봇보다 작다 => 정렬이 되었다. => lleft를 이동
		{
			lleft++;   // 왼족에서 오른쪽이동이니 ++을 해줌
		}
		while (pary[lright] >= pary[pivot] && lright > left)  
		// 오른쪽값이 피봇보다 크다 => 정렬이 되었다. => lright를 이동
        // && lright 오른쪽 인덱스 끝에서 왼쪽으로 이동할때 배열 크기를 벗어나지 않게해주는 조건(lright가 음수가 되지않도록 해줌)

		{
			lright--;  // 오른쪽에서 왼쪽이동이니 --를 해줌
		}

		if (lleft > lright)   // 오른쪽과 왼쪽애가 교체됬을때 => 
		{
			temp = pary[lright];           // 작은값과 피봇을 교체해줌
			pary[lright] = pary[pivot];    
			pary[pivot] = temp;
		}
		else                  // 교체를 안했을때  
		{
			temp = pary[lright];
			pary[lright] = pary[lleft];
			pary[lleft] = temp;
		}
		// 단계별로 정렬되는지 확인하려는 출력문
		for (i = 0; i < right + 1; i++)
		{
			printf("%d  ", pary[i]);
		}
		printf("\n");
	}

	
	
	quickSort(pary, left, lright - 1);   // while문을 빠져나온 후에 왼쪽을 정렬하는 형태(키의 왼쪽)
	
	quickSort(pary, lright + 1, right);   // 피봇을 기준으로 오른쪽을 정렬(키의 오른쪽)
}



/*
왼쪽에서 오른쪽으로갈때는 인덱스가 더 큰 걸 찾음
오른쪽에서 왼쪽으로 갈때는 인덱스가 더 작은 것을 찾음


'3'  5  2  4  7  6  1

3을 피봇으로 잡음
3을 lleft을 3으로잡고 ,1을 lright로 잡은 상태에서 둘을 비교해줌

'3' 1  2  4  7  6  5

3에서 오른쪽으로 계속 이동하면서 비교 => 3보다 작은 2를 찾고 자리를 바꿔줌

2  1 '3' 4  7  6  5

피봇 3을 기준으로 왼쪽, 오른쪽을 재귀호출을통해 정렬시킴


*/