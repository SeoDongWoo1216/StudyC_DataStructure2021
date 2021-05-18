/*

*/

// 배열을 통한 원형 큐 구현
#include <stdio.h>
#include <stdbool.h>
#define SIZE 6

// 함수부
int isEmpty();
int isFull();
void enQueue(int);    // q에 데이터 삽입
int deQueue();        // q에 데이터 제거


// 전역 변수
int rear = 0;         // 입구
int front = 0;        // 출구
int queue[SIZE];


int main() 
{
	// 큐에 데이터 삽입
	enQueue(10);
	enQueue(20);
	enQueue(30);


	// 삭제했을때의 데이터 출력
	printf("%d\n", deQueue());
	printf("%d\n", deQueue());
	printf("%d\n", deQueue());
	printf("%d\n", deQueue());

	return 0;
}


/// <summary>
/// 큐가 비었는지 확인하는 함수
/// </summary>
int isEmpty() 
{
	if (rear == front) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}


/// <summary>
/// 큐가 가득 찼는지 확인하는 함수
/// </summary>
int isFull() 
{
	if (front == (rear + 1) % SIZE )   // 나머지 연산을 통해 0~5의 결과만 나오게 구현
	{
		return true;          // 쨋든 가득찼으면 반환
	}
	else 
	{
		return false;
	}
}


/// <summary>
/// 큐에 데이터 삽입
/// </summary>
void enQueue(int data) 
{
	if (isFull())         // 큐가 가득찼을때
	{
		printf("Queue overflow\n");
		exit(1);
	}
	else 
	{
		rear = rear % SIZE;
		queue[rear] = data;
		rear++;
	}
}


/// <summary>
/// 큐에 데이터 삭제
/// </summary>
int deQueue() 
{
	if (isEmpty())       // 큐의 데이터가 없을때
	{
		printf("Queue underflow!!\n");   
		exit(1);
	}
	else 
	{
		return queue[front++ % SIZE];
	}
}