/*
전위로 노드를 삽입하는 형태

노드의 데이터를 출력 : 헤드노드가 첫번째 노드를 가리켜서 하나씩 순회시켜서 출력했음.

역참조 : NULL이 h를 가리키는 경우 (반대로 가리키는거)

단일연결리스트(단방향)

노드를 서로가리키는게 서로 양방향연결리스트

맨끝에있는게 맨앞을 가리키면 원형연결리스트
*/

// 노드를 검색, 노드를 삭제, 노드를 해제하는 함수를 이용하여 단방향 연결리스트를 만들어보자.
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* next;  // 자기 참조 구조체
}Node;

typedef struct          // 헤드는 첫번째 노드를 가리키는 역할(★헤드가 가리키는게 무조건 첫번째 노드이다★)
{
	Node* head;         // 노드를 가리킬 수 있는 자료형이 와야함. 
}HeadNode;


HeadNode* createHead(void);                 // 헤더 생성 함수
void preInsertNode(HeadNode* h, int data);  // 노드 전위 삽입 함수
void rearInsertNode(HeadNode* h, int data); // 노드 후위 삽입 함수
void print_Node(HeadNode* h);               // 노드 출력 함수
void delAllNode(HeadNode* h);               // 모든 노드 삭제 함수
Node* searchNode(HeadNode* h, int data);    // 특정 노드 검색 함수
Node* delNode(HeadNode* h, Node* temp);     // 특정 노드 삭제 함수(searchNode에서 검색한 노드를 삭제)


int main()
{
	HeadNode* h = createHead();

	// 전위
	preInsertNode(h, 10);
	//preInsertNode(h, 20);
	//preInsertNode(h, 30);

	//// 후위
	//rearInsertNode(h, 40);
	//rearInsertNode(h, 50);
	//rearInsertNode(h, 60);

	// print_Node(h);  // 노드 생성이 잘됬는지 확인할 출력문

	Node* temp = searchNode(h, 10);  // 검색한 노드를 temp에 넣음
	 
	delNode(h, temp);   // 검색한 노드를 삭제

	// delAllNode(h);   // 노드 전체 삭제

	print_Node(h);      // 삭제후에 노드의 상태가 어떤지 다시 확인하기위한 출력문

	return 0;
}




/// <summary>
/// 헤드를 생성하는 함수
/// </summary>
/// <returns></returns>
HeadNode* createHead(void)          // 헤드를 만드는거니까 굳이 인수를 매개변수로 받을 필요는 없음. 
{
	// 함수가 어떻게 동작할지 정의를 작성(일단 이름작성하고 기능을 작성, 매개변수랑 반환은 나중에 생각)

	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));   // Head를 만들꺼니까 HeadNode의 크기만큼 동적할당
														 // 헤더노드는 노드의 포인터 저장

	if (h != NULL) h->head = NULL;  // h가 구조체변수니까 구조체변수 안에 넣어줘야함.

	return h;    // 다른 함수에서도 head를사용하니까 만들었을때 출력이 있는 형태가 좋음
				 // 모든 노드를 생성할때도 head를 기준으로 동작해야함.
}


/// <summary>
/// 전위노드 생성 함수 : 새로운 노드가 맨 처음으로 오는 형태
/// </summary>
void preInsertNode(HeadNode* h, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL)
	{
		newNode->data = data;      // 데이터는 그대로 집어넣음
		newNode->next = h->head;   // newnode의 넥스트값이 h의 head에 삽입
		h->head = newNode;         // h의 head에 newNode 주소값 삽입
	}
}


/// <summary>
/// 후위 삽입 함수 : 새로운 노드가 맨 마지막으로 가는 형태
/// </summary>
void rearInsertNode(HeadNode* h, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL)
	{
		newNode->data = data;          // 데이터는 바로 삽입.
		newNode->next = NULL;          // 마지막 노드가 될꺼니까 NULL이 들어가야함.

		if (h->head == NULL)           // newNode가 제일 처음 생성된 노드일때(ㅁ->ㅁ일때)
		{
			h->head = newNode;         // head에 newnode 주소 삽입
		}
		else                           // newNode가 두번째부터 생성된 노드일때
		{
			Node* curr = h->head;
			while (curr->next != NULL) // next가 NULL인지 찾기위해 순회 => 마지막 노드를 찾기
			{
				curr = curr->next;
			}
			// NULL인 노드를 찾으면 while문이 끝남

			curr->next = newNode;      // NULL인 노드에 newNode 주소값을 삽입
		}
	}
}

/// <summary>
/// 노드 출력 함수
/// </summary>
void print_Node(HeadNode* h)
{
	if (h->head == NULL)
	{
		printf("\n현재 노드가 NULL입니다.\n");
		return;
	}
	Node* curr = h->head;
	int i = 1;
	while (curr != NULL)
	{
		printf("%d번째 노드 데이터 %d\n", i++, curr->data);
		curr = curr->next;
	}
}

/// <summary>
/// 전체 노드 삭제 함수
/// </summary>
void delAllNode(HeadNode* h)
{
	if (h->head == NULL) 
	{
		printf("삭제할 노드가 비어있습니다\n");
	}
	else 
	{
		Node* curr = h->head;    // 기존의 노드를 저장할 curr
		Node* temp;              // 기존노드를 담아둘 변수
		while (curr != NULL)
		{
			temp = curr->next;   // temp에 기존의 노드를 넣어줌
			free(curr);          // 기존의 노드 삭제
			curr = temp;         // 삭제된 노드에 temp 넣어줌 => 다음 노드를 삭제하기위해
		}
		h->head = NULL;          // h(헤드)는 free되지 않음.
		printf("삭제 완료\n");
	}
	
}


/// <summary>
/// 노드 검색 함수
/// </summary>
Node* searchNode(HeadNode* h, int data)
{
	Node* s = h->head;          // 검색할 노드 s 선언
	int i = 1;
	while (s != NULL) 
	{
		if (s->data == data) 
		{
			printf("찾은 값 : %d번째 %d\n", i, s->data);
			return s;
		}
		else 
		{
			s = s->next;
			i++;
		}
	}
	printf("찾는 값이 없습니다.\n");
	return s;
}

/// <summary>
/// 특정 노드 삭제 함수(main에서 검색했던 노드를 삭제하는 함수)
/// </summary>
Node* delNode(HeadNode* h, Node* temp)
{
	Node* curr;
	if (h == NULL)
	{
		printf("헤드가 NULL입니다.\n");
		return;
	}
	if (temp == NULL)
	{
		printf("검색한 노드가 NULL입니다.\n");
		return;
	}
	else if (h->head->next == NULL)  // 노드가 한개있을때(한개 있는 노드 다음이 NULL이므로 노드의 next값이 NULL이 나올것임)
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

