// �迭�� �̿��� ���� ����
#include <stdio.h>
#include <stdbool.h>    // bool ���� ������ �� �ִ� ��� ����

#define STACK_sz 3

// #include <stdbool.h> �� ���� �� ��ũ�� �Լ��� �Ƚᵵ��.
//#define TRUE  1
//#define FALSE 2


// �Լ���
int isEmpty();      // ����üũ
int isFull();       // ��ȭüũ
void push(int);     // ���ÿ�   ������(�Է�)
int pop();          // ���ÿ��� ������(���)
int peek();         // ������ ����Ȯ��(�ְ� ���� Ȯ��)
void printStack();


// ���� ����
int stack[STACK_sz]; // ���� ����(ũ��� ��ũ���Լ����� ����)
int top = -1;        // ���� ���� ��ġ Ȯ�� ����(���� �Է��Ҷ����� ++), �׻� ������ �� ���� ����Ŵ.


int main() 
{
	// ���ÿ� ������ �Է�
	push(10);
	push(20);
	push(30);
	// push(40);

	printStack();   // ���
	printf("\n");

	pop();    // ������ ���

	printStack();

	return 0;
}

/// <summary>
/// ������� Ȯ���ϴ� �Լ�
/// </summary>
int isEmpty() 
{
	if (top <= -1) return true;
	else return false;
}


/// <summary>
/// ����á���� Ȯ���ϴ� �Լ�
/// </summary>
int isFull() 
{
	if (top >= STACK_sz - 1) return true;  
	else return false;
}


/// <summary>
/// ���ÿ� ������ �Է�
/// </summary>
void push(int data) 
{
	if (isFull())  // ��ȭ�������� �ƴ������� ������ ����
	{
		printf("STACK overflow!!\n");
		return;
	}
	else 
	{
		stack[++top] = data;  // top�� -1�ε� ++��Ű�� �迭�� �־���. => ó������ stack[0]�� ��
	}
}


/// <summary>
/// ���ÿ� ������ ���(����)
/// </summary>
int pop() 
{
	if (isEmpty())  // �����Ҳ��� ������� Ȯ���ϰ� ����
	{
		printf("STACK underflow!!\n");
		return;
	}
	else 
	{
		return stack[top--]; // ���� �ش��ϴ� �迭 ��Ҹ� �����ϰ� top�� -- ������
	}
}

/// <summary>
/// ������ top ���Ҹ� �˻��ϴ� �Լ�
/// </summary>
int peek() 
{
	if (isEmpty())   // ������� Ȯ��
	{
		printf("STACK underflow!!\n");
		return;
	}
	else
	{
		return stack[top];    // ������ �迭 ��Ұ��� ��ȯ
	}
}

void printStack()
{
	if (!isEmpty())    // ������ �Ⱥ������ ���
	{
		for (int i = 0; i <= top; i++) 
		{
			printf("%d  ", stack[i]);
		}
	}
}