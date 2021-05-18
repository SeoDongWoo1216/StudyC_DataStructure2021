/*

*/

// �迭�� ���� ���� ť ����
#include <stdio.h>
#include <stdbool.h>
#define SIZE 6

// �Լ���
int isEmpty();
int isFull();
void enQueue(int);    // q�� ������ ����
int deQueue();        // q�� ������ ����


// ���� ����
int rear = 0;         // �Ա�
int front = 0;        // �ⱸ
int queue[SIZE];


int main() 
{
	// ť�� ������ ����
	enQueue(10);
	enQueue(20);
	enQueue(30);


	// ������������ ������ ���
	printf("%d\n", deQueue());
	printf("%d\n", deQueue());
	printf("%d\n", deQueue());
	printf("%d\n", deQueue());

	return 0;
}


/// <summary>
/// ť�� ������� Ȯ���ϴ� �Լ�
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
/// ť�� ���� á���� Ȯ���ϴ� �Լ�
/// </summary>
int isFull() 
{
	if (front == (rear + 1) % SIZE )   // ������ ������ ���� 0~5�� ����� ������ ����
	{
		return true;          // ¶�� ����á���� ��ȯ
	}
	else 
	{
		return false;
	}
}


/// <summary>
/// ť�� ������ ����
/// </summary>
void enQueue(int data) 
{
	if (isFull())         // ť�� ����á����
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
/// ť�� ������ ����
/// </summary>
int deQueue() 
{
	if (isEmpty())       // ť�� �����Ͱ� ������
	{
		printf("Queue underflow!!\n");   
		exit(1);
	}
	else 
	{
		return queue[front++ % SIZE];
	}
}