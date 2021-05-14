/*

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;          // data ���
	struct node* link; // ���� ����� �ּҸ� ������ ���
	                   // ���� ������ ���� ��带 ����Ű�� �����Ϳ����ϹǷ� node*�� ����
}Node;

int main() 
{
	int i = 1;
	Node* head =  (Node*)malloc(sizeof(Node));
	Node* node1 = (Node*)malloc(sizeof(Node));   // ��� ����
	Node* node2 = (Node*)malloc(sizeof(Node));   // Node ũ�⸸ŭ �޸� ���� �Ҵ�(�Ҵ�� �޸� �ּҰ��� ��ȯ����)
	Node* node3 = (Node*)malloc(sizeof(Node));
	Node* node4 = (Node*)malloc(sizeof(Node));
	Node* node5 = (Node*)malloc(sizeof(Node));
	
	/*
	�ܼ����Ḯ��Ʈ���� ��带 �����ϴ� ���
	1. ������ �� ��带 �غ��Ѵ�.
	2. �� ����� �������ʵ忡 ���� �����Ѵ�.
	3. �� ����� ��ũ���� �����Ѵ�.
	4. ����Ʈ�� �� ��忡 �� ��带 �����Ѵ�.
	*/

	/*
	�����ϴ� ���
	1. ������ ����� �� ��带 ã�´�.
	2. �� ��忡 ������ ����� ��ũ �ʵ尪�� ����
	3. ������ ����� �� ���� ������ ����� ���� ��带 ����.
	*/

	head->link = node1;                          // ����忡 ù��° ��带 ����Ŵ

	if (node1 == NULL) return;
	node1->data = 10;                 
	node1->link = node2;                          

	if (node2 == NULL) return;
	node2->data = 20;
	node2->link = node3;

	if (node3 == NULL) return;
	node3->data = 30;
	node3->link = node4;

	if (node4 == NULL) return;
	node4->data = 40;
	node4->link = node5;

	if (node5 == NULL) return;
	node5->data = 50;
	node5->link = NULL;                           // ������ ���� NULL
	
	Node* curr = head->link;                      // ����ϱ����� ù��° ����� �ּҰ� �ӽ÷� ����
	while (curr != NULL) 
	{
		printf("%d��° ��� ������ : %d\n", i, curr->data);
		curr = curr->link;
		i++;
	}

	free(head);
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);

	return 0;
}
