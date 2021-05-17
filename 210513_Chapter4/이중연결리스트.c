// ���߿��Ḯ��Ʈ
/*
����尡 1 -> 2 -> 3 ���� ���־, 3�� ã������ head���� 1, 2�� �� ���ľ��Ѵ�.
�׷��� ������ ��忡 ������ �����ϱ����� 1 <-> 2 <-> 3 ���� ������ִ°���.

���� ��忡�� data, next(�����ּ�), pre(�� �ּ�) �� �������������̴�.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct dlistnode   // ���߿��Ḯ��Ʈ ����ü
{
	int data;
	struct dlistnode* next;  // �ڿ��� ������
	struct dlistnode* prev;  // �տ��� ������
}DListnode;


typedef struct // ��� ����� ����ü
{
	DListnode* head;   // ��� ����� ����ü ����
}HeadNode;


HeadNode* createHeadNode();   // ��� ���� �Լ�
DListnode* createNode(int data);  // ��� ���� �Լ�(�����͸��ְ� ����Ű�� ���� �ʱ�ȭ)
void linkNode(HeadNode* phead, DListnode* preNode, DListnode* newNode); // ��� ���� �Լ�
void printfNode(HeadNode*);
void allDelNode(HeadNode* phead);
DListnode* findNode(HeadNode*, int data);
DListnode DelNode(HeadNode* phead, DListnode* temp);

int main()
{
	// ��� ����
	HeadNode* phead = createHeadNode();

	// ��� ����
	DListnode* node1 = createNode(10);
	DListnode* node2 = createNode(20);
	DListnode* node3 = createNode(30);
	DListnode* node4 = createNode(40);
	DListnode* node5 = createNode(50);

	//printf("%d\n", node1->data);
	//printf("%d\n", node2->data);
	//printf("%d\n", node3->data);

	// ��� ����
	linkNode(phead, NULL, node1);
	linkNode(phead, node1, node2);
	linkNode(phead, node2, node3);
	// linkNode(phead, node1, node4);  //���1 ������ ���4 ����
	linkNode(phead, node3, node4);
	linkNode(phead, node4, node5);
	printf("\n");


	printfNode(phead);
	printf("\n");

	// allDelNode(phead);  // ��ü ���� �Լ�
	// printf("\n");

	// printfNode(phead);
	
	DListnode* temp =  findNode(phead, 10);  // 30 �����͸� ���� ��带 �˻��ϴ� �Լ�

	printf("\n");

	DelNode(phead, temp);  // �˻��� ��带 �����ϴ� �Լ�

	printfNode(phead);     // ������ �� ����� �ٽ� ��带 ���

	return 0;
}

/// <summary>
/// ��� ��� ���� �Լ�
/// </summary>
HeadNode* createHeadNode()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL)
	{
		h->head = NULL;
	}
	return h;
}


/// <summary>
/// ��� ���� �Լ�
/// </summary>
DListnode* createNode(int data)
{
	DListnode* newNode = (DListnode*)malloc(sizeof(DListnode));
	if (newNode == NULL)
	{
		printf("��� ������ �޸� �Ҵ� ����! -> �����մϴ�. \n");
		exit(1);
	}
	else
	{
		// newNode �ʱ�ȭ
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;
		printf("��� ����, ������ : %d, ������ ��� �ּ� : %p\n", newNode->data, newNode);

		return newNode;
	}
}


/// <summary>
/// ��� ��������ִ� �Լ�
/// </summary>
void linkNode(HeadNode* phead, DListnode* preNode, DListnode* newNode)
{
	// ���, �����, ������带 �μ��� �޾ƿ�

	if (phead->head == NULL)        // ���鸮��Ʈ(���X)�� ��� => �׳� ���ڿ� ����
	{
		// newNode->next = NULL;    // ������ NULL�ε� �����Ҷ� NULL�� �ʱ�ȭ�ؼ� �ߺ��ڵ��̹Ƿ� �ʿ���� �ڵ���
		phead->head = newNode;
		newNode->prev = phead->head;
	}
	else                            // ��尡 ������ ��� 
	{
		if (preNode == NULL)        // ��尡 preNode �Ѱ����϶�(ù��° ���� ����?)
		{
			newNode->next = phead->head;
			phead->head->prev = newNode;
			phead->head = newNode;
		}
		else                        // �߰� �Ǵ� ������ ���� ����
		{
			// ���� ����(preNode->next�� NULL�϶� ==> preNode�� ������ ����϶�)
			newNode->prev = preNode;              // newNode�� preNode ����
			newNode->next = preNode->next;        // preNode->next�� NULL ��

			// �߰� ����(preNode������ newNode�� �����Ҷ�)
			if (preNode->next != NULL)            // preNode�� �������� NULL�� �ƴҶ� => preNode �������� ������)
			{
				preNode->next->prev = newNode;    // �߰������̹Ƿ� newNode �������� prev�� newNode�� ����
			}
			preNode->next = newNode;
		}

		
	}
}

/// <summary>
/// ��� ��� �Լ�
/// </summary>
void printfNode(HeadNode* phead)
{
	if (phead->head == NULL)
	{
		printf("\n���� ��尡 NULL�Դϴ�.\n");
		return;
	}

	DListnode* curr = phead->head;
	int i = 1;
	while (curr != NULL)
	{
		printf("%d��° ��� ������ : %d\n", i++, curr->data);
		curr = curr->next;
	}
}


/// <summary>
/// ��� ��ü ���� �Լ�
/// </summary>
void allDelNode(HeadNode* phead)
{
	if (phead->head == NULL)
	{
		printf("������ ��尡 �������� �ʽ��ϴ�.\n");
	}
	else
	{
		DListnode* curr = phead->head;
		DListnode* temp;
		while (curr != NULL)
		{
			temp = curr->next;   // temp�� ������ ��带 �־���
			free(curr);          // ������ ��� ����
			curr = temp;         // ������ ��忡 temp �־��� => ���� ��带 �����ϱ�����
		}
		phead->head = NULL;
		printf("�����Ϸ�\n");
	}
}


/// <summary>
/// ��� �˻� �Լ�
/// </summary>
DListnode* findNode(HeadNode* phead, int data)
{
	DListnode* curr = phead->head;
	int i = 1;
	
	while (curr != NULL)
	{
		if (curr->data == data)
		{
			printf("%d��°�� ã�� ������ : %d\n", i, curr->data);
			return curr;
		}
		else
		{
			curr = curr->next;
			i++;
		}
	}
	printf("ã�� ��尡 �����ϴ�.\n");
	return curr;
}

/// <summary>
/// Ư�� ��� ���� �Լ�(�˻��Ѱ� ������ ����)
/// </summary>
DListnode DelNode(HeadNode* phead, DListnode* temp) 
{
	DListnode* curr = phead->head;
	if (curr == NULL) 
	{
		printf("������ ��尡 �����ϴ�.\n");
		return;
	}

	if (temp == NULL) 
	{
		printf("�˻��� ��尡 ��� ������ ��尡 �����ϴ�.\n");
	}

	else                                  // ��尡 2�� �̻��϶�
	{
		curr = phead->head;
		if (curr == temp)                 // ������ ��尡 head ���� ����϶�
		{
			phead->head = temp->next;     // head�� �˻��� ����� ���� ��带 ����Ű�� free
			free(temp);
			// temp = NULL;
			return;
		}

		else 
		{
			if (temp->next == NULL)               // �����Ϸ��� ��尡 �� ������ ����϶�
			{
				temp->prev->next = NULL;
				free(temp);
				return;
			}
			else
			{
				while (curr->next != temp)        // ��尡 2�� �̻��϶� �� �� ��带 ã����
				{
					curr = curr->next;
				}
				curr->next = temp->next;          // 
				temp->next->prev = temp->prev;
				free(temp);
			}

			
		}

		
	}
}
