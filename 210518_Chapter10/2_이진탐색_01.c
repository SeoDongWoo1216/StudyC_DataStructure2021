/*
이진탐색 : 시간복잡도 n/2
10개 배열에서 검색한다고 가정하면, 순차탐색은 0번방부터 9번방까지 훑었었다.

이진 탐색은 배열이 정렬된 상태에서 사용할 수 있다.

이진탐색은 반으로 나눠서 5개에서 찾고, 5개에서 찾는다.
없으면 또 반으로나눠서 2개에서 찾고 3개에서 찾고 2개에서 찾고 3개에서 찾는다.

일단은 반씩 쪼개서 검사하는것이 이진탐색임.
순차탐색보다 조금 빠름.
*/ 
#include <stdio.h>

int BSearch(int*, int, int);

int main() 
{
	int index;                                  // 찾은 값이 몇번째인지 저장하는 변수
	//int ary[] = { 3, 5, 8, 2, 7, 6, 1 };      
	int ary[] = { 1, 2, 3, 4, 5, 6, 7, 8 };     // 정렬된 배열에서 사용하는 것이 이진 탐색.

	int size = sizeof(ary) / sizeof(ary[0]);    // 배열의 요소 개수

	// BSearch는 바이너리(이진) 서치의 약자
	index = BSearch(ary, size, 3);  
	if (index == -1) 
	{
		printf("탐색 실패\n");
	}
	else 
	{
		printf("찾는 값은 %d번째에 있습니다.", index);
	}

	return 0;
}

/// <summary>
/// 바이너리 서치 함수
/// </summary>
int BSearch(int* pary, int sz, int tg) 
{
	int first = 0;
	int last = sz - 1;  // 배열 시작이 0부터 시작하기때문에 9번방까지 있으므로 -1을 해줌.
	int mid;            // 반으로 쪼개야하니까 중간값 선언

	while (first<=last) 
	{
		mid = (first + last) / 2;   // ★★★★★중간값 초기화★★★★★ => 제일 중요한 코드
		if (tg == pary[mid])        // 반으로 쪼갰을때 그 반으로 쪼갰을때의 숫자 위치가 찾는 값일때(완전 재수)
		{
			return mid; 
		}
		else 
		{
			if (tg > pary[mid])  // 찾으려는 값이 pary[mid]보다 클때 => 중간을 기준으로 오른쪽(큰 값)을 검사
			{
				first = mid + 1; 
			} 
			else                 // 찾으려는 값이 pary[mid]보다 작을때 => 중간을 기준으로 왼쪽(작은 값)을 검사
			{
				last = mid - 1;
			}
		}
	}
	return -1;  // 못찾았을때 -1 반환
}