/*
순차탐색

구현하기 쉽지만, 시간복잡도가 좋지않다.
검색할 데이터가 마지막 원소일때는 별로 효율적이지는 않다.
*/

#include <stdio.h>

int LSearch(int*, int, int);

int main() 
{
	int index;                                  // 찾은 값이 몇번째인지 저장하는 변수
	int ary[] = { 3, 5, 8, 2, 7, 6, 1 };        // 
	int size = sizeof(ary) / sizeof(ary[0]);    // 배열의 요소 개수

	//LSearch(배열, 배열의 크기, 찾고자하는 데이터); // LSearch는 리니어서치의 약자임

	index = LSearch(&ary, size, 2);             // 시간 복잡도는 n
	
	if (index == -1)                            // 검색함수에서 -1을 반환했을때
	{
		printf("찾기 실패!\n");
	}
	else 
	{
		printf("찾던 값은 %d번째에 있습니다.\n", index);
	}

	return 0;
}

/// <summary>
/// 리니어 서치(순차 탐색 => 시간 복잡도 n)
/// </summary>
int LSearch(int* pary, int sz, int tg) 
{
	for (int i = 0; i < sz; i++)  // 배열의 크기만큼 for문 돌림
	{
		if (tg == pary[i])        // 배열의 요소와 찾는 값이 같을때 => 배열의 요소가 내가 검색하려는 값일때
		{
			return i;             // 검색됬을때 이게 몇번째였는지 반환
		}
	}
	return -1;                    // 검색 못했을때는 -1 반환
}