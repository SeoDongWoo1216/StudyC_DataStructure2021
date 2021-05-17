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

// �������Ḯ��Ʈ
#include <stdio.h>
#include <stdlib.h>

typedef struct listnode     // ��� ����ü ����
{
	int data;
	struct listnode* link;
}ListNode;


typedef struct             // ��� ��� ����ü ����
{
	ListNode* head;
}HeadNode;


HeadNode* createHead();                         // ��� ���� �Լ�
ListNode* createNode(HeadNode* , int );         // ��� ���� �Լ�(�� ���ÿ� �ʱ�ȭ���� ����) 
void insertFirstNode(HeadNode* , ListNode* );   // ���� ��� ����
void insertLastNode(HeadNode*, ListNode*);      // ���� ��� ����
void print_Node(HeadNode* );                    // ��� ��� �Լ�


int main()
{
	// ��� ��� ����
	HeadNode* h = createHead();

	// ��� ����
	ListNode* node1 = createNode(h, 10);
	ListNode* node2 = createNode(h, 20);
	ListNode* node3 = createNode(h, 30);
	ListNode* node4 = createNode(h, 40);

	// ���� ����
	insertFirstNode(h, node1);
	insertFirstNode(h, node2);
	insertFirstNode(h, node3);
	//insertFirstNode(h, node4);

	// ���� ����
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
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));  // HeadNode��ŭ�� �޸� �뷮�� ���� �Ҵ�
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

	if (newNode == NULL)   // �޸𸮿� �뷮�� �����ϸ� NULL ��ȯ�ؼ� ���������� ���� ����
	{
		printf("��带 ������ �޸𸮰� �����մϴ�.(����) => �����մϴ�.\n");
		exit(1);
	}
	else                  // �޸𸮿� �Ҵ� �� �޾����״� �ʱ�ȭ(data�� ����, link ����)
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
//	   /*
//	   �� �Լ��� ������ ��尡 �߰��ɶ����� while�������� head�� ��� �ٲ��ִ� ���� �Լ��̴�.
//	   */
//	}
//}



/// <summary>
/// ��带 ù��° ��忡 �߰�(By ����Թ���)
/// </summary>
void insertFirstNode(HeadNode* phead, ListNode* newNode)
{
	if (phead->head == NULL)      // ���� ����Ʈ�϶�
	{
		phead->head = newNode;    // head�� newNode
		newNode->link = newNode;  // NewNode�� �ּҴ� �ڱ��ڽ�
	}
	else                          // ���� ����Ʈ�� �ƴҶ�
	{ 
		newNode->link = phead->head->link;  // ���ο� ����� ��ũ�� ��尡 ����Ű�� ���� ��ũ�� �ٲ���
		phead->head->link = newNode;        // ��尡 ����Ű�� ���� ��ũ�� ������ �ٲ���.
	}
	/*
	h�� ����������, head�� ����Ű�� ���� ��带 ��� �߰��ϴ� ���. 
	
	          2 -> 1 <- phead ���� 1 -> 2 �� �߰�

	�̶� 3�� �߰��ϸ�
	     3 -> 2 -> 1 <- phead ���� 1 -> 3 �� �߰��ȴ�.

	�̶� 4�� �߰��ϸ�
	4 -> 3 -> 2 -> 1 <- phead ���� 1 -> 4 �߰�
	*/
}


/// <summary>
/// ��带 ������ ��忡 �߰�(���� ����)
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
		phead->head->link = newNode;         // ���ٰ� ������ 2���� �������� ����

		phead->head = newNode;               // ��带 ������ �ٲ�.(���� ��� ������ Ư¡����, ���ο� ��尡 ��� ���� ���� �ٲ��.)
	}
	/*
	����� ���� ���� ��� ���԰� ������, ��尡 �߰��ɶ����� head�� ����Ű�� ���� ���Ѵٴ� �������� �ִ�.

	              1 <- phead

	2�� �߰�
	          1 -> 2 <- phead ���� 2 -> 1 �߰�

	�̶� 3�� �߰��ϸ�
	     1 -> 2 -> 3 <- phead ���� 3 -> 1 �߰�

	�̶� 4�� �߰��ϸ�
	1 -> 2 -> 3 -> 4 <- phead ���� 4 -> 1�� �߰��Ǵ� ���.
	*/
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


