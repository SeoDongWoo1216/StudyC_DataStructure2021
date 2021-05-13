/*
순차 자료구조
구현할 자료들을 논리적 순서로 메모리에 연속 저장하는 구현 방식
논리적인 순서와 물리적인 순서가 항상 일치해야함.
C에서 순차 자료구조의 구현 방식을 제공하는 프로그램 기법은 배열이다.

자료의 특징(추상 자료형)과 주로 사용할 연산(알고리즘)에 따라 최적의 형태로 자료를 구조화해야한다.
자료를 구조화하는 가장 기본적인 방법은 나열하는것이다. 이때 나열한 목록을 리스트(list)라고한다.
또 이때 원소들을 순서대로 나열한 리스트를 선형리스트 또는 순서리스트 라고 한다.

선형 리스트
검색은 편한데 삽입과 삭제가 불편하다.

선형 리스트는 메모리에 저장하는 구현 방식에 따라 
순차 방식으로 구현하는 선형 순차 리스트(선형리스트)
연결 방식으로 구현하는 선형 연결 리스트(연결리스트)로 나뉜다.

선형리스트는 원소들이 나열된 논리적인 순서와 메모리에 저장되는 물리적 순서가 일치하는 순차 자료구조방식으로 구현한다.
순차 자료구조는 원소를 논리적인 순서대로 메모리에 연속하여 저장한다.

순차 자료구조는 원소들이 순서대로 연속하여 저장하기때문에 시작위치와 원소크기를 알면 특정 원소의 
위치를 쉽게 알 수 있다. 
시작위치가 a, 원소크기가 l인 선형리스트에서
두번째 원소의 위치는 a + l이고, 세번째는 a + 2l이고, i번째 원소위치는 a + (i - 1) * l이 된다.

선형리스트에서 원소 삽입 : 삽입해주기전에 공간을 만들어놓고 삽입해야한다.(뒤에 애들을 한칸 땡겨줘야한다)

삽입할 자리를 만들기 위한 자리 이동 횟수
(n+1) 개의 원소로 이루어진 선형 리스트에서 k번 자리에 원소를 삽입하는 경우
k번 원소부터 마지막 인덱스 n번 원소까지 (n-k+1)개의 원소를 이동
=> 이동횟수 : n - k + 1 = 마지막 원소의 인덱스 - 삽입할 자리의 인덱스 + 1


선형리스트에서 원소 삭제 : 삭제하고나서 뒤에 애들을 한칸씩 땡겨줘야한다.

삭제 후 빈자리를 채우기 위한 자리이동 횟수
(n+1)개 원소로 이루어진 선형 리스트에서 k번 자리의 원소를 삭제한 경우
: (k+1)번 원소부터 마지막 n번 원소까지 (n-(k+1) + 1)개의 원소를 이동
=> 이동 횟수 : n - (k + 1) + 1 = n - k = 마지막 원소의 인덱스 - 삭제한 자리의 인덱스
*/


/*
선형 리스트는 배열을 사용하여 순차 자료구조 방식을 구현한다.
배열은 <인덱스, 원소> 쌍으로 구성되어 메모리에 연속적으로 할당되는데, 이때 인덱스는 배열 원소의 순서를 나타낸다.
배열은 순서를 가진 배열 원소들을 메모리에 연속이면서 순차적으로 구성하므로 선형 리스트를 쉽게 구현할 수 있다.

1차원 배열은 인덱스를 하나만 사용하는데, 원소 순서를 한 개의 값으로 구별할 수 있는 간단한 선형리스트를 구현할 수 있다.
*/

// 원소의 논리적, 물리적 순서 확인하기
#include <stdio.h>

int main() 
{
	int i, sale[4] = { 157, 209, 251, 312 };

	for (i = 0; i < 4; i++) 
	{
		printf("\n address : %u sale[%d]=%d", &sale[i], i, sale[i]);  // %u는 양수만뽑을때(주소값)
	}

	getchar();
}