/*
다항식의 선형리스트 표현
다항식은 지수가 높은 항부터 낮은 항 순서로 항을 나열하며 가장 큰 지수가 다항식의 차수가 된다.


1차원 배열 : 차수만큼의 배열의 방 개수를 만들고, 각 계수를 각 방에 넣어준다. -> 메모리 낭비 일어날 수 있음
4x^3 + 3x^2 + 2는
0 1 2 3 (방)
4 3 0 2 (데이터)  가 된다.
근데 계수가 0인 친구도 방을 만들어줘야하므로 메모리의 낭비가 일어날 수 있다.

2차원 배열 : 항의 개수만큼 배열의 방 개수를 만들고, 각 차수와 계수를 각각 방에 넣어준다.
1000차 다항식이지만 항의 개수가 3개밖에없으면 1001개의 방에 데이터가 3개밖에없으므로 메모리가 비효율적이다.
따라서 (지수+1) 크기의 배열생성보다는 항의 개수에따라 배열 크기를 결정하는 것이 메모리 사용면에서 효율적이다.
*/

// degree : 차수
// coef는 계수

#include <stdio.h>
#define MAX(a,b) ((a>b)?a:b)
#define MAX_DEGREE 50

typedef struct               // 구조체 정의
{             
	int degree;              // 다항식의 차수를 저장할 변수
	float coef[MAX_DEGREE];  // 다항식의 각 항의 계수를 저장할 1차원 배열
}polynomial;

polynomial addPoly(polynomial, polynomial);  // 구조체 변수 2개를 전달
void printPoly(polynomial);

void main() 
{
	polynomial A = { 3, {4,3,5,0} };   // 다항식 A의 초기화
	polynomial B = { 4, {3,1,0,2,1} }; // 다항식 B의 초기화

	polynomial C;
	C = addPoly(A, B);  // 다항식 A,B에 대한 덧셈을 수행하기 위해 addPoly 함수 호출

	printf("\n A(x) ="); printPoly(A);
	printf("\n B(x) ="); printPoly(B);
	printf("\n C(x) ="); printPoly(C);

	getchar();
}


polynomial addPoly(polynomial A, polynomial B) 
{
	polynomial C;
	int A_index = 0;
	int B_index = 0;
	int C_index = 0;

	int A_degree = A.degree;
	int B_degree = B.degree;
	C.degree = MAX(A.degree, B.degree);

	while (A_index <= A.degree && B_index <= B.degree) 
	{
		if (A_degree > B_degree) 
		{
			C.coef[C_index++] = A.coef[A_index];
			A_degree--;
		}
		else if (A_degree == B_degree) 
		{
			C.coef[C_index++] = A.coef[A_index++] + B.coef[B_index++];
			A_degree;
			B_degree;
		}
		else 
		{
			C.coef[C_index++] = B.coef[B_index++];
			B_degree--;
		}
	}
	return C;
}

void printPoly(polynomial P)
{
	int i;
	int degree;
	degree = P.degree;

	for (i = 0; i <= P.degree; i++)
	{
		printf("%3.0fx^%d", P.coef[i], degree--);
		if (i < P.degree) printf(" +");
	}
	printf("\n");
}