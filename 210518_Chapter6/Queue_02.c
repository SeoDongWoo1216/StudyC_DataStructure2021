// 연결리스트로 원형 큐 구현

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define SIZE 6

typedef struct          // 큐 변수타입 구조체 선언
{
	int data;
	int rear, front;
	// struct Node* next;
}QNode;

//typedef struct cQ {     // 원형 큐 front, rear 구조체 선언 
//	QNode* front;
//	QNode* rear;
//}Queue;


// front랑 rear를 포인터로 할때
// Queue* createQueue();
//int isEmpty(Queue*);
//int isFull(Queue*);
//void enQueue(int);    // q에 데이터 삽입
//int deQueue();        // q에 데이터 제거


// front랑 rear를 정수했을때
void initQueue(QNode*);
// void createQueue(QNode*);
int isEmpty(QNode*);
int isFull(QNode*);
void enQueue(QNode*,int);    // q에 데이터 삽입
int deQueue(QNode*);        // q에 데이터 제거

int queue[SIZE];

int main() 
{
	// Queue* Qhead = createQueue();
	QNode* pq;
	initQueue(&pq);
	enQueue(&pq, 10);
	enQueue(&pq, 20);
	enQueue(&pq, 30);

	
	//printf("%d\n", deQueue(&pq));
	printf("%d\n", queue[0]);
	printf("%d\n", queue[1]);
	printf("%d\n", queue[2]);

	return 0;
}


/// <summary>
/// 큐 생성(front, rear가 포인터일때)
/// </summary>
//Queue* createQueue() 
//{
//	Queue* h = (Queue*)malloc(sizeof(Queue));
//	if (h != NULL) 
//	{
//		h->front = NULL;
//		h->rear = NULL;
//	}
//
//	return h;
//}


/// <summary>
/// 큐 생성(front, rear가 정수일때)
/// </summary>
void initQueue(QNode* pq)  
{
	// 구조체 멤버 변수를 초기화 시켜줌.
	 pq->data = 0;
	 pq->front = 0;
	 pq->rear = 0;
}


/// <summary>
/// 큐가 비었는지 확인하는 함수
/// </summary>
/// <returns></returns>
int isEmpty(QNode* pq)
{
	if (pq->front == pq->rear) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}


/// <summary>
/// 큐가 꽉찼는지 확인하는 함수
/// </summary>
int isFull(QNode* pq)
{
	if (pq->front == ((pq->rear + 1) % SIZE))
	{
		return true;
	}
	else 
	{
		return false;
	}
}


/// <summary>
/// 큐에 데이터 삽입 함수
/// </summary>
void enQueue(QNode* pq, int data) 
{
	if (isFull(pq)) 
	{
		printf("Queue overflow!!\n");
		return;
	}
	else
	{
		queue[(pq->rear++) % SIZE] = data;
		printf("%d값 추가", pq->data);
	}
}



/// <summary>
/// 큐에 데이터 삭제 함수
/// </summary>
int deQueue(QNode* pq) 
{
	if (isEmpty(pq)) 
	{
		printf("Queue underflow!\n");
		exit(1);
	}
	else 
	{
		return queue[pq->front++ % SIZE];
	}

}
