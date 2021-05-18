/*
연결자료구조와 스택
세번째가 두번째, 두번째가 첫번째를 가리키는 형태 => 위에꺼가 아래를 가리키는 형태가 되어야함.
(만약 반대라면 없어진 값을 가리키는 형태가 되므로 좋지않음)

탑은 항상 맨 위 데이터가 되어야한다.
*/

// 연결리스트와 스택을 결합해보자
#include <stdio.h>
#include <stdbool.h>   // 참과 거짓을 쓰기위한 헤더파일
#include <stdlib.h>

typedef struct stacknode  // 스택 노드 구조체 선언
{
	int data;
	struct stacknode* link;
}SNode;

typedef struct            // 헤드 구조체 선언
{
	SNode* topstk;   // topstack
}TStack;


/// <summary>
/// 헤드 노드 생성
/// </summary>
TStack* createHead() 
{
	TStack* t = (TStack*)malloc(sizeof(TStack));  // 헤드를 메모리에 동적할당

	if (t != NULL)                          // 메모리가 부족해서 할당안됬을때
	{ 
		t->topstk = NULL; 
	}
	return t;
}


/// <summary>
/// 스택이 비었는지 검사하는 함수
/// </summary>
int isEmpty(TStack* ptstack) 
{
	if (ptstack->topstk == NULL) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}


/// <summary>
/// 스택에 데이터 입력 
/// </summary>
void push(TStack* ptstack, int data)
{
	SNode* newNode = (SNode*)malloc(sizeof(SNode));
	if (newNode == NULL)              // 메모리가 부족해서 동적할당 안됬을때
	{
		return;
	}
	newNode->data = data;
	newNode->link = ptstack->topstk;  // 헤드 필드에 들어간놈을 새노드의 링크에 저장
	ptstack->topstk = newNode;        // 헤드가 새로운 노드를 가리킴.
}

/// <summary>
/// 스택에 데이터 출력(삭제)
/// </summary>
int pop(TStack* ptstack) 
{
	int data;
	SNode* temp;
	if (isEmpty(ptstack)) 
	{
		printf("STACK is EMPTY!!\n");
		return;
	}
	else 
	{
		data = ptstack->topstk->data;
		temp = ptstack->topstk;
		ptstack->topstk = ptstack->topstk->link;
		free(temp);
		return data;
	}
}

/// <summary>
/// 스택 맨위의 값을 확인하는 함수
/// </summary>
int peek(TStack* ptstack) 
{
	if (isEmpty(ptstack))   // 스택이 비었는지 확인
	{
		printf("STACK EMPTY!!\n");
	}
	else 
	{
		return ptstack->topstk->data;
	}
}

/// <summary>
/// 현재 스택의 데이터 출력 함수
/// </summary>
void printStack(TStack* ptstack) 
{
	SNode* curr = ptstack->topstk;   // 임시 curr를 헤드로 선언
	while (curr)           
	{
		printf("%d  ", curr->data);  // 데이터 출력
		curr = curr->link;           // 증감식
	}
	printf("\n");
}


int main() 
{
	// 헤드 생성
	TStack* h = createHead();

	// 데이터 입력
	push(h, 10);
	push(h, 20);
	push(h, 30);
	push(h, 40);

	printStack(h);

	pop(h);    // 데이터 삭제(맨 위에꺼가 없어질꺼임)

	printStack(h);


	return 0;
}