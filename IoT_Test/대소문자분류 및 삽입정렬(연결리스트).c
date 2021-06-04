/*
	*���Ḯ��Ʈ
	1. ���ĺ��� �Է¹ް� ��� ����(�̶� ��带 �� �̾��ݴϴ�)
	2. ���������� ����Ͽ� ���ĺ��� ����.
	3. ���ĵ� ���ĺ����� ��ҹ��ڸ� �����ؼ� ���


	����(�����Բ� �����ؼ� �ۼ��߽��ϴ�)
	1. ����� �����Ҵ��Ͽ� ����
	2. ���ĺ��� �Է¹ް� ������������ ���ο� ��� ����
	3. ���ĺ��� �ƽ�Ű�ڵ� ������ ����
	4. �빮�����, �ҹ������


	����
	1. ���ĺ��߿� ���ڸ� �Է������� ���� �޼��� ����Ŀ� ����
	2. �ߺ����������� �ߺ����� �ִ±״�� ���� �Ŀ� ���(a a b b c  �̷��� ��µ�)
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node      // ���Ḯ��Ʈ ��� ����ü ����
{	
	char alpha;
	struct node* next;
}Node;

typedef struct          // ��� ����ü ����
{		
	Node* Head;
}HeadNode;


void insertionSort(HeadNode* head);  // ���� ���� �Լ�
void inputNode(HeadNode* head);      // ��� �Է� �Լ�
void printNode(HeadNode* head);      // ��� ��� �Լ�


int main()
{
	HeadNode* head = malloc(sizeof(HeadNode));  // ����� ����
	if (head != NULL) head->Head = NULL;        // ��尡 ������ ��� ����

	inputNode(head);

	insertionSort(head);	 // �ƽ�Ű �ڵ� �� ������ ����

	printNode(head);         // ���� �� ��� ���

	return 0;
}

/// <summary>
/// ��� �Է� �� �߰� �Լ�
/// </summary>
void inputNode(HeadNode* head)
{
	printf("���ĺ� �Է� 10�� �Է� : ");
	
		for (int i = 0; i < 10; i++)                // ���ĺ� �Է¹ް� ���ο� ��� ����(��������)
		{

			Node* newNode = malloc(sizeof(Node));	// ���ο� ��忡 �޸� ���� �Ҵ�
			if (newNode != NULL)
			{
				char temp;
				scanf(" %c", &temp);
				if ((temp >= 'A' && temp <= 'Z') || (temp >= 'a' && temp <= 'z'))
				{
					newNode->alpha = temp;           // �� ��� �����Ϳ� �Է¹��� ���ĺ� ����
					newNode->next = head->Head;      // �� ��带 ���� ���� ����
					head->Head = newNode;	         // ��尡 ����Ű�� ���� �� ���� ���� 

					// ��� -> ���� ���(NULL)�� ������  (NULL�̸� ���� ��尡 ���� ���)
					// ��� 1-> ����� 2-> ���� ��尡 �Ǵ� ����
					 
					// 1-> : head->Head = newNode;
					// 2-> : newNode->next = head->Head;
				}

				else                                 // 10�� �����߿� �ٸ� ���ڰ� �Էµ������� �����޼��� ����ϰ� ����
				{
					printf("10�� �����߿� ���ĺ��� �Է����� �ʾҽ��ϴ�. �����մϴ�.");
					exit(1);
				}
			}
		}	
}



/// <summary>
/// ���� ����(���) �Լ�
/// </summary>
void insertionSort(HeadNode* head)
{
	Node* curr, * tmp;
	curr = head->Head;   // ���������� �ӽ� ��� curr ����

	while (curr->next != NULL)
	{
		if (curr->alpha > curr->next->alpha)
		{
			tmp = curr->next;               // �ű� ��带 �ӽ� ����
			curr->next = curr->next->next;  // �ű� ��� ���� ���� 
			tmp->next = head->Head;         // tmp ���� ù ��� ����
			head->Head = curr = tmp;        // ��� ���=���� ���=tmp
			continue;
		}
		curr = curr->next;
	}
}


/// <summary>
/// ��� ��� �Լ�
/// </summary>
void printNode(HeadNode* head)
{
	printf("\n");
	Node* curr = head->Head;        // �ӽ� ��� ����

	if ('Z' >= curr->alpha)         // ù ���ڰ� �빮�ڰ� ������ 
	{
		printf("�빮�� : ");
		while ('Z' >= curr->alpha)      // �빮�� ���
		{
			printf("%c ", curr->alpha);
			curr = curr->next;

			if (curr->next == NULL)     // curr->next�� NULL�̸� ���� ������ �迭�̶�¶� => �ҹ��ڰ� ����
			{
				printf("\n�ҹ��� �迭�� �����ϴ�.\n");
				return;
			}
		}
	}

	else
	{
		printf("�빮�� �迭�� �����ϴ�.\n");
	}



	printf("\n�ҹ��� : ");
	while (curr != NULL)            // �ҹ��� ���
	{
		
		printf("%c ", curr->alpha);
		curr = curr->next;
	}
	printf("\n");
}