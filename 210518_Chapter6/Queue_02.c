// ���Ḯ��Ʈ�� ���� ť ����

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define SIZE 6

typedef struct          // ť ����Ÿ�� ����ü ����
{
	int data;
	int rear, front;
	// struct Node* next;
}QNode;

//typedef struct cQ {     // ���� ť front, rear ����ü ���� 
//	QNode* front;
//	QNode* rear;
//}Queue;


// front�� rear�� �����ͷ� �Ҷ�
// Queue* createQueue();
//int isEmpty(Queue*);
//int isFull(Queue*);
//void enQueue(int);    // q�� ������ ����
//int deQueue();        // q�� ������ ����


// front�� rear�� ����������
void initQueue(QNode*);
// void createQueue(QNode*);
int isEmpty(QNode*);
int isFull(QNode*);
void enQueue(QNode*,int);    // q�� ������ ����
int deQueue(QNode*);        // q�� ������ ����

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
/// ť ����(front, rear�� �������϶�)
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
/// ť ����(front, rear�� �����϶�)
/// </summary>
void initQueue(QNode* pq)  
{
	// ����ü ��� ������ �ʱ�ȭ ������.
	 pq->data = 0;
	 pq->front = 0;
	 pq->rear = 0;
}


/// <summary>
/// ť�� ������� Ȯ���ϴ� �Լ�
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
/// ť�� ��á���� Ȯ���ϴ� �Լ�
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
/// ť�� ������ ���� �Լ�
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
		printf("%d�� �߰�", pq->data);
	}
}



/// <summary>
/// ť�� ������ ���� �Լ�
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
