/*
������ ��带 �����ϴ� ����

����� �����͸� ��� : ����尡 ù��° ��带 �����Ѽ� �ϳ��� ��ȸ���Ѽ� �������.

������ : NULL�� h�� ����Ű�� ��� (�ݴ�� ����Ű�°�)

���Ͽ��Ḯ��Ʈ(�ܹ���)

��带 ���ΰ���Ű�°� ���� ����⿬�Ḯ��Ʈ

�ǳ����ִ°� �Ǿ��� ����Ű�� �������Ḯ��Ʈ
*/

// ��带 �˻�, ��带 ����, ��带 �����ϴ� �Լ��� �̿��Ͽ� �ܹ��� ���Ḯ��Ʈ�� ������.
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* next;  // �ڱ� ���� ����ü
}Node;

typedef struct          // ���� ù��° ��带 ����Ű�� ����(����尡 ����Ű�°� ������ ù��° ����̴١�)
{
	Node* head;         // ��带 ����ų �� �ִ� �ڷ����� �;���. 
}HeadNode;


HeadNode* createHead(void);                 // ��� ���� �Լ�
void preInsertNode(HeadNode* h, int data);  // ��� ���� ���� �Լ�
void rearInsertNode(HeadNode* h, int data); // ��� ���� ���� �Լ�
void print_Node(HeadNode* h);               // ��� ��� �Լ�
void delAllNode(HeadNode* h);               // ��� ��� ���� �Լ�
Node* searchNode(HeadNode* h, int data);    // Ư�� ��� �˻� �Լ�
Node* delNode(HeadNode* h, Node* temp);     // Ư�� ��� ���� �Լ�(searchNode���� �˻��� ��带 ����)


int main()
{
	HeadNode* h = createHead();

	// ����
	preInsertNode(h, 10);
	//preInsertNode(h, 20);
	//preInsertNode(h, 30);

	//// ����
	//rearInsertNode(h, 40);
	//rearInsertNode(h, 50);
	//rearInsertNode(h, 60);

	// print_Node(h);  // ��� ������ �߉���� Ȯ���� ��¹�

	Node* temp = searchNode(h, 10);  // �˻��� ��带 temp�� ����
	 
	delNode(h, temp);   // �˻��� ��带 ����

	// delAllNode(h);   // ��� ��ü ����

	print_Node(h);      // �����Ŀ� ����� ���°� ��� �ٽ� Ȯ���ϱ����� ��¹�

	return 0;
}




/// <summary>
/// ��带 �����ϴ� �Լ�
/// </summary>
/// <returns></returns>
HeadNode* createHead(void)          // ��带 ����°Ŵϱ� ���� �μ��� �Ű������� ���� �ʿ�� ����. 
{
	// �Լ��� ��� �������� ���Ǹ� �ۼ�(�ϴ� �̸��ۼ��ϰ� ����� �ۼ�, �Ű������� ��ȯ�� ���߿� ����)

	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));   // Head�� ���鲨�ϱ� HeadNode�� ũ�⸸ŭ �����Ҵ�
														 // ������� ����� ������ ����

	if (h != NULL) h->head = NULL;  // h�� ����ü�����ϱ� ����ü���� �ȿ� �־������.

	return h;    // �ٸ� �Լ������� head������ϴϱ� ��������� ����� �ִ� ���°� ����
				 // ��� ��带 �����Ҷ��� head�� �������� �����ؾ���.
}


/// <summary>
/// ������� ���� �Լ� : ���ο� ��尡 �� ó������ ���� ����
/// </summary>
void preInsertNode(HeadNode* h, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL)
	{
		newNode->data = data;      // �����ʹ� �״�� �������
		newNode->next = h->head;   // newnode�� �ؽ�Ʈ���� h�� head�� ����
		h->head = newNode;         // h�� head�� newNode �ּҰ� ����
	}
}


/// <summary>
/// ���� ���� �Լ� : ���ο� ��尡 �� ���������� ���� ����
/// </summary>
void rearInsertNode(HeadNode* h, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL)
	{
		newNode->data = data;          // �����ʹ� �ٷ� ����.
		newNode->next = NULL;          // ������ ��尡 �ɲ��ϱ� NULL�� ������.

		if (h->head == NULL)           // newNode�� ���� ó�� ������ ����϶�(��->���϶�)
		{
			h->head = newNode;         // head�� newnode �ּ� ����
		}
		else                           // newNode�� �ι�°���� ������ ����϶�
		{
			Node* curr = h->head;
			while (curr->next != NULL) // next�� NULL���� ã������ ��ȸ => ������ ��带 ã��
			{
				curr = curr->next;
			}
			// NULL�� ��带 ã���� while���� ����

			curr->next = newNode;      // NULL�� ��忡 newNode �ּҰ��� ����
		}
	}
}

/// <summary>
/// ��� ��� �Լ�
/// </summary>
void print_Node(HeadNode* h)
{
	if (h->head == NULL)
	{
		printf("\n���� ��尡 NULL�Դϴ�.\n");
		return;
	}
	Node* curr = h->head;
	int i = 1;
	while (curr != NULL)
	{
		printf("%d��° ��� ������ %d\n", i++, curr->data);
		curr = curr->next;
	}
}

/// <summary>
/// ��ü ��� ���� �Լ�
/// </summary>
void delAllNode(HeadNode* h)
{
	if (h->head == NULL) 
	{
		printf("������ ��尡 ����ֽ��ϴ�\n");
	}
	else 
	{
		Node* curr = h->head;    // ������ ��带 ������ curr
		Node* temp;              // ������带 ��Ƶ� ����
		while (curr != NULL)
		{
			temp = curr->next;   // temp�� ������ ��带 �־���
			free(curr);          // ������ ��� ����
			curr = temp;         // ������ ��忡 temp �־��� => ���� ��带 �����ϱ�����
		}
		h->head = NULL;          // h(���)�� free���� ����.
		printf("���� �Ϸ�\n");
	}
	
}


/// <summary>
/// ��� �˻� �Լ�
/// </summary>
Node* searchNode(HeadNode* h, int data)
{
	Node* s = h->head;          // �˻��� ��� s ����
	int i = 1;
	while (s != NULL) 
	{
		if (s->data == data) 
		{
			printf("ã�� �� : %d��° %d\n", i, s->data);
			return s;
		}
		else 
		{
			s = s->next;
			i++;
		}
	}
	printf("ã�� ���� �����ϴ�.\n");
	return s;
}

/// <summary>
/// Ư�� ��� ���� �Լ�(main���� �˻��ߴ� ��带 �����ϴ� �Լ�)
/// </summary>
Node* delNode(HeadNode* h, Node* temp)
{
	Node* curr;
	if (h == NULL)
	{
		printf("��尡 NULL�Դϴ�.\n");
		return;
	}
	if (temp == NULL)
	{
		printf("�˻��� ��尡 NULL�Դϴ�.\n");
		return;
	}
	else if (h->head->next == NULL)  // ��尡 �Ѱ�������(�Ѱ� �ִ� ��� ������ NULL�̹Ƿ� ����� next���� NULL�� ���ð���)
	{
		h->head = h->head->next;
		free(temp);
		return;
	}
	else
	{
		curr = h->head;
		if (curr == temp)
		{
			h->head = temp->next;
			free(temp);
			temp = NULL;
			return;
		}

		while (curr->next != temp)
		{
			curr = curr->next;
		}
		curr->next = temp->next;
		free(temp);
	}
}

