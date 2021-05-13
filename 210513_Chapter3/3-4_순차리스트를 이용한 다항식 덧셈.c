/*
���׽��� ��������Ʈ ǥ��
���׽��� ������ ���� �׺��� ���� �� ������ ���� �����ϸ� ���� ū ������ ���׽��� ������ �ȴ�.


1���� �迭 : ������ŭ�� �迭�� �� ������ �����, �� ����� �� �濡 �־��ش�. -> �޸� ���� �Ͼ �� ����
4x^3 + 3x^2 + 2��
0 1 2 3 (��)
4 3 0 2 (������)  �� �ȴ�.
�ٵ� ����� 0�� ģ���� ���� ���������ϹǷ� �޸��� ���� �Ͼ �� �ִ�.

2���� �迭 : ���� ������ŭ �迭�� �� ������ �����, �� ������ ����� ���� �濡 �־��ش�.
1000�� ���׽������� ���� ������ 3���ۿ������� 1001���� �濡 �����Ͱ� 3���ۿ������Ƿ� �޸𸮰� ��ȿ�����̴�.
���� (����+1) ũ���� �迭�������ٴ� ���� ���������� �迭 ũ�⸦ �����ϴ� ���� �޸� ���鿡�� ȿ�����̴�.
*/

// degree : ����
// coef�� ���

#include <stdio.h>
#define MAX(a,b) ((a>b)?a:b)
#define MAX_DEGREE 50

typedef struct               // ����ü ����
{             
	int degree;              // ���׽��� ������ ������ ����
	float coef[MAX_DEGREE];  // ���׽��� �� ���� ����� ������ 1���� �迭
}polynomial;

polynomial addPoly(polynomial, polynomial);  // ����ü ���� 2���� ����
void printPoly(polynomial);

void main() 
{
	polynomial A = { 3, {4,3,5,0} };   // ���׽� A�� �ʱ�ȭ
	polynomial B = { 4, {3,1,0,2,1} }; // ���׽� B�� �ʱ�ȭ

	polynomial C;
	C = addPoly(A, B);  // ���׽� A,B�� ���� ������ �����ϱ� ���� addPoly �Լ� ȣ��

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