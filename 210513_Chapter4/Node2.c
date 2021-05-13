/* */
#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
	int data;
	struct Node* link;
}Node;

void addNode(Node* target, int data)   // head 다음 노드가 첫번째 노드를 가리키게 만드는 함수
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->link = target->link;  // 그 전이 가리키고있는 link를 받음
	target->link = newNode;
}

void printNode(Node* curr)
{
	Node* head = curr->link;
	while (head != NULL)
	{
		printf("노드 값 : %d\n", head->data);
		head = head->link;
	}
}

void freeNode(Node* curr) 
{
	Node* temp;
	for (curr; curr != NULL; curr->link)
	{
		temp = curr->link;
		free(curr);
		curr = temp;
	}
}

int main() 
{
	int i = 0;
	Node* head = (Node*)malloc(sizeof(Node));

	head->link = NULL;  // 초기화
	addNode(head, 10);
	addNode(head, 20);
	addNode(head, 30);
	addNode(head, 40);
	addNode(head, 50);

	printNode(head);

	freeNode(head);

	return 0;
}

