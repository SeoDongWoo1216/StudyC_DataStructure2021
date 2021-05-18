/*
�����ڷᱸ���� ����
����°�� �ι�°, �ι�°�� ù��°�� ����Ű�� ���� => �������� �Ʒ��� ����Ű�� ���°� �Ǿ����.
(���� �ݴ��� ������ ���� ����Ű�� ���°� �ǹǷ� ��������)

ž�� �׻� �� �� �����Ͱ� �Ǿ���Ѵ�.
*/

// ���Ḯ��Ʈ�� ������ �����غ���
#include <stdio.h>
#include <stdbool.h>   // ���� ������ �������� �������
#include <stdlib.h>

typedef struct stacknode  // ���� ��� ����ü ����
{
	int data;
	struct stacknode* link;
}SNode;

typedef struct            // ��� ����ü ����
{
	SNode* topstk;   // topstack
}TStack;


/// <summary>
/// ��� ��� ����
/// </summary>
TStack* createHead() 
{
	TStack* t = (TStack*)malloc(sizeof(TStack));  // ��带 �޸𸮿� �����Ҵ�

	if (t != NULL)                          // �޸𸮰� �����ؼ� �Ҵ�ȉ�����
	{ 
		t->topstk = NULL; 
	}
	return t;
}


/// <summary>
/// ������ ������� �˻��ϴ� �Լ�
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
/// ���ÿ� ������ �Է� 
/// </summary>
void push(TStack* ptstack, int data)
{
	SNode* newNode = (SNode*)malloc(sizeof(SNode));
	if (newNode == NULL)              // �޸𸮰� �����ؼ� �����Ҵ� �ȉ�����
	{
		return;
	}
	newNode->data = data;
	newNode->link = ptstack->topstk;  // ��� �ʵ忡 ������ ������� ��ũ�� ����
	ptstack->topstk = newNode;        // ��尡 ���ο� ��带 ����Ŵ.
}

/// <summary>
/// ���ÿ� ������ ���(����)
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
/// ���� ������ ���� Ȯ���ϴ� �Լ�
/// </summary>
int peek(TStack* ptstack) 
{
	if (isEmpty(ptstack))   // ������ ������� Ȯ��
	{
		printf("STACK EMPTY!!\n");
	}
	else 
	{
		return ptstack->topstk->data;
	}
}

/// <summary>
/// ���� ������ ������ ��� �Լ�
/// </summary>
void printStack(TStack* ptstack) 
{
	SNode* curr = ptstack->topstk;   // �ӽ� curr�� ���� ����
	while (curr)           
	{
		printf("%d  ", curr->data);  // ������ ���
		curr = curr->link;           // ������
	}
	printf("\n");
}


int main() 
{
	// ��� ����
	TStack* h = createHead();

	// ������ �Է�
	push(h, 10);
	push(h, 20);
	push(h, 30);
	push(h, 40);

	printStack(h);

	pop(h);    // ������ ����(�� �������� ����������)

	printStack(h);


	return 0;
}