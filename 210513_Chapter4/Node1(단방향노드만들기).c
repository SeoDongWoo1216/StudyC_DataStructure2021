/*

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;          // data 멤버
	struct node* link; // 다음 노드의 주소를 저장할 멤버
	                   // 같은 구조의 다음 노드를 가리키는 포인터여야하므로 node*로 선언
}Node;

int main() 
{
	int i = 1;
	Node* head =  (Node*)malloc(sizeof(Node));
	Node* node1 = (Node*)malloc(sizeof(Node));   // 노드 생성
	Node* node2 = (Node*)malloc(sizeof(Node));   // Node 크기만큼 메모리 동적 할당(할당된 메모리 주소값을 반환해줌)
	Node* node3 = (Node*)malloc(sizeof(Node));
	Node* node4 = (Node*)malloc(sizeof(Node));
	Node* node5 = (Node*)malloc(sizeof(Node));
	
	/*
	단순연결리스트에서 노드를 삽입하는 방법
	1. 삽입할 새 노드를 준비한다.
	2. 새 노드의 데이터필드에 값을 저장한다.
	3. 새 노드의 링크값을 지정한다.
	4. 리스트의 앞 노드에 새 노드를 연결한다.
	*/

	/*
	삭제하는 방법
	1. 삭제할 노드의 앞 노드를 찾는다.
	2. 앞 노드에 삭제할 노드의 링크 필드값을 저장
	3. 삭제한 노드의 앞 노드와 삭제한 노드의 다음 노드를 연결.
	*/

	head->link = node1;                          // 헤드노드에 첫번째 노드를 가리킴

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
	node5->link = NULL;                           // 마지막 값에 NULL
	
	Node* curr = head->link;                      // 출력하기위해 첫번째 노드의 주소값 임시로 저장
	while (curr != NULL) 
	{
		printf("%d번째 노드 데이터 : %d\n", i, curr->data);
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
