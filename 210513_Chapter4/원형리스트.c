/*
��������Ʈ
head -> node1 -> node2 -> node3 ���� node3 -> node1 �� �߰��� ���̴�.

���� ��� ������ ��带���� ����

���� ��� ������ node4->link = node3->link; ,  node3->link = node4;
				 �̶� ������ ���� head�� ����� ����Ű���ִ� ��ũ�� ���ٴ°��� ���� ã�´�.
�ٵ� �� ������ �ʹ� ��ȿ�����̶� head�� node1�� �ƴ϶� ������ ��带 ����Ű�� ����� �ִ�.

head�� ������ ��带 ����ų��
- ������ ��带 �߰��Ҷ��� ��������� ������ ù��° ����̹Ƿ� �� ��尡 ����Ű�� ����
node1���� ���ְ�, node3�� link�� �� ���� ���ָ�ȴ�.

- ù��° ��带 �߰��Ҷ��� ��尡 ����Ű�� ��带 �߰��� ���� ���ָ�ȴ�.
=> ������ ��带 ����ų���� �� ȿ�����̰� ����.
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct listnode
{
	int data;
	struct listnode* link;
}ListNode;


typedef struct
{
	ListNode* head;
}HeadNode;


HeadNode* createHead();
ListNode* createNode(HeadNode* phead, int data);
void insertFirstNode(HeadNode* phead, ListNode* newNode);
void print_Node(HeadNode* phead);
void insertLastNode(HeadNode* phead, ListNode* newNode);

int main()
{
	// ��� ��� ����
	HeadNode* h = createHead();

	// ��� ����
	ListNode* node1 = createNode(h, 10);
	ListNode* node2 = createNode(h, 20);
	ListNode* node3 = createNode(h, 30);
	ListNode* node4 = createNode(h, 40);

	insertFirstNode(h, node1);
	insertFirstNode(h, node2);
	insertFirstNode(h, node3);
	//insertFirstNode(h, node4);

	//insertLastNode(h, node1);
	//insertLastNode(h, node2);
	//insertLastNode(h, node3);
	//insertLastNode(h, node4);

	print_Node(h);

	return 0;
}


/// <summary>
/// ��� ��� ���� 
/// </summary>
HeadNode* createHead()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL)
	{
		h->head = NULL;
	}
	return h;
}


/// <summary>
/// ��� ����(�� ���ÿ� �ʱ�ȭ)
/// </summary>
ListNode* createNode(HeadNode* phead, int data)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));  
	// Heap ������ Listnode ��ŭ�� �뷮��ŭ �Ҵ��ؼ� �����ּҸ� ��������

	if (newNode == NULL)
	{
		printf("��带 ������ �޸𸮰� �����մϴ�.(����) => �����մϴ�.\n");
		exit(1);
	}
	else
	{
		newNode->data = data;
		newNode->link = NULL;
		return newNode;  // ���������ִ� �����ּҸ� ����
	}
}


///// <summary>
///// ��带 ù��° ��忡 �߰� (by ����)
///// </summary>
//void insertFirstNode(HeadNode* phead, ListNode* newNode)
//{
//	ListNode* curr = phead->head;
//	if (phead->head == NULL)      // ���� ����Ʈ�϶�
//	{
//		phead->head = newNode;    // head�� newNode
//		newNode->link = newNode;  // NewNode�� �ּҴ� �ڱ��ڽ�
//	}
//	else                          // ���鸮��Ʈ�� �ƴҶ� 
//	{
//		while (curr->link != phead->head)  // ù��° ��带 ã�Ƽ�
//		{
//			curr = curr->link;
//		}
//		curr->link = newNode;          // ã�� ����� link�� ���ο� ��带 �־���
//		newNode->link = phead->head;   // 
//		phead->head = newNode;            
//
//	}
//}

/// <summary>
/// ��带 ù��° ��忡 �߰�
/// </summary>
void insertFirstNode(HeadNode* phead, ListNode* newNode)
{
	if (phead->head == NULL)
	{
		phead->head = newNode;    // head�� newNode
		newNode->link = newNode;  // NewNode�� �ּҴ� �ڱ��ڽ�
	}
	else
	{
		newNode->link = phead->head->link;
		phead->head->link = newNode;
	}
}


/// <summary>
/// ��带 ������ ��忡 �߰�
/// </summary>
void insertLastNode(HeadNode* phead, ListNode* newNode)
{
	if (phead->head == NULL)
	{
		phead->head = newNode;    // head�� newNode
		newNode->link = newNode;  // NewNode�� �ּҴ� �ڱ��ڽ�
	}
	else
	{
		newNode->link = phead->head->link;
		phead->head->link = newNode;
		phead->head = newNode;
	}
}




/// <summary>
/// ��� ��� �Լ�
/// </summary>
void print_Node(HeadNode* h)
{
	int i = 1;
	if (h->head == NULL)
	{
		printf("\n���� ��尡 NULL�Դϴ�.\n");
		return;
	}
	ListNode* curr = h->head;

	do
	{
		printf("��� ������ : %d\n", curr->data);  // head�� �� ���
		curr = curr->link;                         // ������(�� ���� ��带 ����Ŵ)
	} 
	while (curr != h->head);                       // �� ������ head�� �� ������ ��µ�.
	{
		printf("\n");
	}

	/*
	1 -> 2 -> 3 -> 4  <- h   �̰�, 4 -> 1�϶�
	4�� ���� ����ϰ�, 1, 2, 3�� ����ϰ� 4�϶� �ݺ����� ������ ����

	
	*/



}


