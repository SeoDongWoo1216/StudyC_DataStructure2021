// 배열을 이용한 스택 구현
#include <stdio.h>
#include <stdbool.h>    // bool 형을 구현할 수 있는 헤더 파일

#define STACK_sz 3

// #include <stdbool.h> 로 인해 이 매크로 함수는 안써도됨.
//#define TRUE  1
//#define FALSE 2


// 함수부
int isEmpty();      // 공백체크
int isFull();       // 포화체크
void push(int);     // 스택에   넣을때(입력)
int pop();          // 스택에서 꺼낼때(출력)
int peek();         // 맨위의 스택확인(최고 상태 확인)
void printStack();


// 전역 변수
int stack[STACK_sz]; // 스택 선언(크기는 매크로함수에서 선언)
int top = -1;        // 현재 스택 위치 확인 변수(스택 입력할때마다 ++), 항상 스택의 맨 위를 가리킴.


int main() 
{
	// 스택에 데이터 입력
	push(10);
	push(20);
	push(30);
	// push(40);

	printStack();   // 출력
	printf("\n");

	pop();    // 데이터 출력

	printStack();

	return 0;
}

/// <summary>
/// 비었는지 확인하는 함수
/// </summary>
int isEmpty() 
{
	if (top <= -1) return true;
	else return false;
}


/// <summary>
/// 가득찼는지 확인하는 함수
/// </summary>
int isFull() 
{
	if (top >= STACK_sz - 1) return true;  
	else return false;
}


/// <summary>
/// 스택에 데이터 입력
/// </summary>
void push(int data) 
{
	if (isFull())  // 포화상태인지 아닌지부터 따지고 시작
	{
		printf("STACK overflow!!\n");
		return;
	}
	else 
	{
		stack[++top] = data;  // top이 -1인데 ++시키고 배열에 넣어줌. => 처음에는 stack[0]에 들어감
	}
}


/// <summary>
/// 스택에 데이터 출력(삭제)
/// </summary>
int pop() 
{
	if (isEmpty())  // 삭제할껀데 비었는지 확인하고 시작
	{
		printf("STACK underflow!!\n");
		return;
	}
	else 
	{
		return stack[top--]; // 현재 해당하는 배열 요소를 리턴하고 top을 -- 시켜줌
	}
}

/// <summary>
/// 스택의 top 원소를 검색하는 함수
/// </summary>
int peek() 
{
	if (isEmpty())   // 비었는지 확인
	{
		printf("STACK underflow!!\n");
		return;
	}
	else
	{
		return stack[top];    // 현재의 배열 요소값을 반환
	}
}

void printStack()
{
	if (!isEmpty())    // 스택이 안비었으면 출력
	{
		for (int i = 0; i <= top; i++) 
		{
			printf("%d  ", stack[i]);
		}
	}
}