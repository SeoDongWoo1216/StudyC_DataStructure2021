/*
행렬의 선형리스트 표현
행렬은 행과 열로 구성된 자료구조이다.

행렬의 행과 열을 서로 바꿔 구성한 행렬을 전치행렬이라고 한다.

m * n 행렬은 2차원 배열[m][n]로 구현하기는 쉽지만, 원소가 0이 있는 희소행렬에서는 실제로 사용하지않는 공간이 많아서
활용도가 떨어질 것이다.

따라서 0이 아닌 원소들을 <행번호, 열번호, 데이터값>의 쌍을구해 2차원 배열에 저장할 것이다.
이때 0번방은 전체 열의 개수, 전체 행의 개수, 위치를 가지고있는 데이터의 개수  => 2차원 배열 정보를 저장한다.
*/

#include <stdio.h>

typedef struct   // 행렬 원소를 저장하기 위한 구조체 term 정의
{
	int row;
	int col;
	int value;
}term;

void smTranpose(term a[], term b[])   // term 타입의 a 배열을 받고있으므로 main에 term 타입의 배열 선언한거 넣어줌
{
	int m, n, v, i, j, p;
	m = a[0].row;            // 희소 행렬 a의 행 수
	n = a[0].col;            // 희소 행렬 a의 열 수
	v = a[0].value;          // 희소 행렬 a에서 0이아닌 원소의 개수

	b[0].row = n;            // 전치 행렬 b의 행 수
	b[0].col = m;            // 전치 행렬 b의 열 수
	b[0].value = v;          // 전치 행렬 b의 원소 수

	if (v > 0)               // 0이 아닌 원소가 있는 경우에만 전치 연산 수행
	{
		printf("%d %d %d\n", b[0].row, b[0].col, b[0].value);
		p = 1;
		for (i = 0; i < n; i++)        // 희소행렬 a의 열별로 전치 반복 수행
		{
			for (j = 1; j <= v; j++)   // 0이 아닌 원소 수에 대해서만 반복 수행
			{
				if (a[j].col == i)     // 현재의 열에 속하는 원소가 있으면 b[]에 삽입
				{
					b[p].row = a[j].col;
					b[p].col = a[j].row;
					b[p].value = a[j].value;
					printf("%d %d %d\n", b[p].row, b[p].col, b[p].value);
					p++;
				}
			}
		}
	}

}

void main()
{
	term x[] = { {2,4,3},{0,1,5} };
	term y[] = { {0,0,0},{0,0,0} };
	smTranpose(x, y);

	getchar();
	//return 0;
}