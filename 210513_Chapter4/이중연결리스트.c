// 이중연결리스트
/*
헤드노드가 1 -> 2 -> 3 으로 되있어서, 3을 찾으려면 head부터 1, 2를 꼭 거쳐야한다.
그래서 마지막 노드에 빠르게 접근하기위해 1 <-> 2 <-> 3 으로 연결되있는것임.

따라서 노드에는 data, next(다음주소), pre(전 주소) 를 가지고있을것이다.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct dlistnode   // 이중연결리스트 구조체
{
	int data;
	struct dlistnode* next;  // 뒤에꺼 포인터
	struct dlistnode* prev;  // 앞에꺼 포인터
}DListnode;


typedef struct // 헤드 노드의 구조체
{
	DListnode* head;   // 헤드 노드의 구조체 선언
}HeadNode;


HeadNode* createHeadNode();   // 헤드 생성 함수
DListnode* createNode(int data);  // 노드 생성 함수(데이터만넣고 가리키는 값은 초기화)
void linkNode(HeadNode* phead, DListnode* preNode, DListnode* newNode); // 노드 삽입 함수
void printfNode(HeadNode*);
void allDelNode(HeadNode* phead);
DListnode* findNode(HeadNode*, int data);
DListnode DelNode(HeadNode* phead, DListnode* temp);

int main()
{
	// 헤드 생성
	HeadNode* phead = createHeadNode();

	// 노드 생성
	DListnode* node1 = createNode(10);
	DListnode* node2 = createNode(20);
	DListnode* node3 = createNode(30);
	DListnode* node4 = createNode(40);
	DListnode* node5 = createNode(50);

	//printf("%d\n", node1->data);
	//printf("%d\n", node2->data);
	//printf("%d\n", node3->data);

	// 노드 연결
	linkNode(phead, NULL, node1);
	linkNode(phead, node1, node2);
	linkNode(phead, node2, node3);
	// linkNode(phead, node1, node4);  //노드1 다음에 노드4 삽입
	linkNode(phead, node3, node4);
	linkNode(phead, node4, node5);
	printf("\n");


	printfNode(phead);
	printf("\n");

	// allDelNode(phead);  // 전체 삭제 함수
	// printf("\n");

	// printfNode(phead);
	
	DListnode* temp =  findNode(phead, 10);  // 30 데이터를 가진 노드를 검색하는 함수

	printf("\n");

	DelNode(phead, temp);  // 검색한 노드를 삭제하는 함수

	printfNode(phead);     // 삭제가 잘 됬는지 다시 노드를 출력

	return 0;
}

/// <summary>
/// 헤드 노드 생성 함수
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
/// 노드 생성 함수
/// </summary>
DListnode* createNode(int data)
{
	DListnode* newNode = (DListnode*)malloc(sizeof(DListnode));
	if (newNode == NULL)
	{
		printf("노드 생성때 메모리 할당 실패! -> 종료합니다. \n");
		exit(1);
	}
	else
	{
		// newNode 초기화
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;
		printf("노드 생성, 데이터 : %d, 생성된 노드 주소 : %p\n", newNode->data, newNode);

		return newNode;
	}
}


/// <summary>
/// 노드 연결시켜주는 함수
/// </summary>
void linkNode(HeadNode* phead, DListnode* preNode, DListnode* newNode)
{
	// 헤드, 전노드, 다음노드를 인수로 받아옴

	if (phead->head == NULL)        // 공백리스트(노드X)일 경우 => 그냥 헤드뒤에 삽입
	{
		// newNode->next = NULL;    // 원래는 NULL인데 생성할때 NULL로 초기화해서 중복코드이므로 필요없는 코드임
		phead->head = newNode;
		newNode->prev = phead->head;
	}
	else                            // 노드가 존재할 경우 
	{
		if (preNode == NULL)        // 노드가 preNode 한개뿐일때(첫번째 노드로 삽입?)
		{
			newNode->next = phead->head;
			phead->head->prev = newNode;
			phead->head = newNode;
		}
		else                        // 중간 또는 마지막 노드로 삽입
		{
			// 후위 삽입(preNode->next가 NULL일때 ==> preNode가 마지막 노드일때)
			newNode->prev = preNode;              // newNode와 preNode 연결
			newNode->next = preNode->next;        // preNode->next인 NULL 들어감

			// 중간 삽입(preNode다음에 newNode를 삽입할때)
			if (preNode->next != NULL)            // preNode의 다음값이 NULL이 아닐때 => preNode 다음값이 있을때)
			{
				preNode->next->prev = newNode;    // 중간삽입이므로 newNode 다음값의 prev를 newNode로 변경
			}
			preNode->next = newNode;
		}

		
	}
}

/// <summary>
/// 노드 출력 함수
/// </summary>
void printfNode(HeadNode* phead)
{
	if (phead->head == NULL)
	{
		printf("\n현재 노드가 NULL입니다.\n");
		return;
	}

	DListnode* curr = phead->head;
	int i = 1;
	while (curr != NULL)
	{
		printf("%d번째 노드 데이터 : %d\n", i++, curr->data);
		curr = curr->next;
	}
}


/// <summary>
/// 노드 전체 삭제 함수
/// </summary>
void allDelNode(HeadNode* phead)
{
	if (phead->head == NULL)
	{
		printf("삭제할 노드가 존재하지 않습니다.\n");
	}
	else
	{
		DListnode* curr = phead->head;
		DListnode* temp;
		while (curr != NULL)
		{
			temp = curr->next;   // temp에 기존의 노드를 넣어줌
			free(curr);          // 기존의 노드 삭제
			curr = temp;         // 삭제된 노드에 temp 넣어줌 => 다음 노드를 삭제하기위해
		}
		phead->head = NULL;
		printf("삭제완료\n");
	}
}


/// <summary>
/// 노드 검색 함수
/// </summary>
DListnode* findNode(HeadNode* phead, int data)
{
	DListnode* curr = phead->head;
	int i = 1;
	
	while (curr != NULL)
	{
		if (curr->data == data)
		{
			printf("%d번째로 찾은 데이터 : %d\n", i, curr->data);
			return curr;
		}
		else
		{
			curr = curr->next;
			i++;
		}
	}
	printf("찾는 노드가 없습니다.\n");
	return curr;
}

/// <summary>
/// 특정 노드 삭제 함수(검색한거 다음꺼 삭제)
/// </summary>
DListnode DelNode(HeadNode* phead, DListnode* temp) 
{
	DListnode* curr = phead->head;
	if (curr == NULL) 
	{
		printf("삭제할 노드가 없습니다.\n");
		return;
	}

	if (temp == NULL) 
	{
		printf("검색된 노드가 없어서 삭제할 노드가 없습니다.\n");
	}

	else                                  // 노드가 2개 이상일때
	{
		curr = phead->head;
		if (curr == temp)                 // 삭제할 노드가 head 다음 노드일때
		{
			phead->head = temp->next;     // head가 검색한 노드의 다음 노드를 가리키고 free
			free(temp);
			// temp = NULL;
			return;
		}

		else 
		{
			if (temp->next == NULL)               // 삭제하려는 노드가 맨 마지막 노드일때
			{
				temp->prev->next = NULL;
				free(temp);
				return;
			}
			else
			{
				while (curr->next != temp)        // 노드가 2개 이상일때 그 전 노드를 찾아줌
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
