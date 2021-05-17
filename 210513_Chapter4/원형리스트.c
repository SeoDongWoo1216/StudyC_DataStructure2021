/*
원형리스트
head -> node1 -> node2 -> node3 에서 node3 -> node1 를 추가한 것이다.

전위 노드 삽입은 헤드를통해 접근

후위 노드 삽입은 node4->link = node3->link; ,  node3->link = node4;
				 이때 마지막 노드는 head의 멤버가 가리키고있는 링크가 같다는것을 통해 찾는다.
근데 이 과정이 너무 비효율적이라 head가 node1이 아니라 마지막 노드를 가리키는 방법이 있다.

head가 마지막 노드를 가리킬때
- 마지막 노드를 추가할때는 마지막노드 다음은 첫번째 노드이므로 새 노드가 가리키는 값을
node1으로 해주고, node3의 link를 새 노드로 해주면된다.

- 첫번째 노드를 추가할때는 헤드가 가리키는 노드를 추가할 노드로 해주면된다.
=> 마지막 노드를 가리킬때가 더 효율적이고 쉬움.
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
	// 헤드 노드 생성
	HeadNode* h = createHead();

	// 노드 생성
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
/// 헤드 노드 생성 
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
/// 노드 생성(과 동시에 초기화)
/// </summary>
ListNode* createNode(HeadNode* phead, int data)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));  
	// Heap 영역에 Listnode 만큼의 용량만큼 할당해서 시작주소를 리턴해줌

	if (newNode == NULL)
	{
		printf("노드를 생성할 메모리가 부족합니다.(실패) => 종료합니다.\n");
		exit(1);
	}
	else
	{
		newNode->data = data;
		newNode->link = NULL;
		return newNode;  // 힙영역에있는 시작주소를 리턴
	}
}


///// <summary>
///// 노드를 첫번째 노드에 추가 (by 현수)
///// </summary>
//void insertFirstNode(HeadNode* phead, ListNode* newNode)
//{
//	ListNode* curr = phead->head;
//	if (phead->head == NULL)      // 공백 리스트일때
//	{
//		phead->head = newNode;    // head는 newNode
//		newNode->link = newNode;  // NewNode의 주소는 자기자신
//	}
//	else                          // 공백리스트가 아닐때 
//	{
//		while (curr->link != phead->head)  // 첫번째 노드를 찾아서
//		{
//			curr = curr->link;
//		}
//		curr->link = newNode;          // 찾은 노드의 link에 새로운 노드를 넣어줌
//		newNode->link = phead->head;   // 
//		phead->head = newNode;            
//
//	}
//}

/// <summary>
/// 노드를 첫번째 노드에 추가
/// </summary>
void insertFirstNode(HeadNode* phead, ListNode* newNode)
{
	if (phead->head == NULL)
	{
		phead->head = newNode;    // head는 newNode
		newNode->link = newNode;  // NewNode의 주소는 자기자신
	}
	else
	{
		newNode->link = phead->head->link;
		phead->head->link = newNode;
	}
}


/// <summary>
/// 노드를 마지막 노드에 추가
/// </summary>
void insertLastNode(HeadNode* phead, ListNode* newNode)
{
	if (phead->head == NULL)
	{
		phead->head = newNode;    // head는 newNode
		newNode->link = newNode;  // NewNode의 주소는 자기자신
	}
	else
	{
		newNode->link = phead->head->link;
		phead->head->link = newNode;
		phead->head = newNode;
	}
}




/// <summary>
/// 노드 출력 함수
/// </summary>
void print_Node(HeadNode* h)
{
	int i = 1;
	if (h->head == NULL)
	{
		printf("\n현재 노드가 NULL입니다.\n");
		return;
	}
	ListNode* curr = h->head;

	do
	{
		printf("노드 데이터 : %d\n", curr->data);  // head의 값 출력
		curr = curr->link;                         // 증감식(맨 끝의 노드를 가리킴)
	} 
	while (curr != h->head);                       // 맨 끝부터 head의 전 노드까지 출력됨.
	{
		printf("\n");
	}

	/*
	1 -> 2 -> 3 -> 4  <- h   이고, 4 -> 1일때
	4를 먼저 출력하고, 1, 2, 3을 출력하고 4일때 반복문이 끝나는 원리

	
	*/



}


