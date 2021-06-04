/*
	*연결리스트
	1. 알파벳을 입력받고 노드 생성(이때 노드를 다 이어줍니다)
	2. 삽입정렬을 사용하여 알파벳을 정렬.
	3. 정렬된 알파벳들을 대소문자를 구별해서 출력


	구현(연성님꺼 참고해서 작성했습니다)
	1. 헤드노드 동적할당하여 생성
	2. 알파벳을 입력받고 전위삽입으로 새로운 노드 생성
	3. 알파벳을 아스키코드 순으로 정렬
	4. 대문자출력, 소문자출력


	오류
	1. 알파벳중에 숫자를 입력했을시 오류 메세지 출력후에 종료
	2. 중복문자있으면 중복문자 있는그대로 정렬 후에 출력(a a b b c  이렇게 출력됨)
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node      // 연결리스트 노드 구조체 선언
{	
	char alpha;
	struct node* next;
}Node;

typedef struct          // 헤더 구조체 선언
{		
	Node* Head;
}HeadNode;


void insertionSort(HeadNode* head);  // 삽입 정렬 함수
void inputNode(HeadNode* head);      // 노드 입력 함수
void printNode(HeadNode* head);      // 노드 출력 함수


int main()
{
	HeadNode* head = malloc(sizeof(HeadNode));  // 헤드노드 선언
	if (head != NULL) head->Head = NULL;        // 헤드가 없으면 헤드 생성

	inputNode(head);

	insertionSort(head);	 // 아스키 코드 값 순으로 정렬

	printNode(head);         // 정렬 후 노드 출력

	return 0;
}

/// <summary>
/// 노드 입력 및 추가 함수
/// </summary>
void inputNode(HeadNode* head)
{
	printf("알파벳 입력 10개 입력 : ");
	
		for (int i = 0; i < 10; i++)                // 알파벳 입력받고 새로운 노드 생성(전위삽입)
		{

			Node* newNode = malloc(sizeof(Node));	// 새로운 노드에 메모리 동적 할당
			if (newNode != NULL)
			{
				char temp;
				scanf(" %c", &temp);
				if ((temp >= 'A' && temp <= 'Z') || (temp >= 'a' && temp <= 'z'))
				{
					newNode->alpha = temp;           // 새 노드 데이터에 입력받은 알파벳 저장
					newNode->next = head->Head;      // 새 노드를 다음 노드로 연결
					head->Head = newNode;	         // 헤드가 가리키는 곳을 새 노드로 연결 

					// 헤드 -> 기존 노드(NULL)가 있을때  (NULL이면 기존 노드가 없는 경우)
					// 헤드 1-> 새노드 2-> 기존 노드가 되는 원리
					 
					// 1-> : head->Head = newNode;
					// 2-> : newNode->next = head->Head;
				}

				else                                 // 10개 문자중에 다른 문자가 입력되있으면 오류메세지 출력하고 종료
				{
					printf("10개 문자중에 알파벳을 입력하지 않았습니다. 종료합니다.");
					exit(1);
				}
			}
		}	
}



/// <summary>
/// 삽입 정렬(노드) 함수
/// </summary>
void insertionSort(HeadNode* head)
{
	Node* curr, * tmp;
	curr = head->Head;   // 정렬을위해 임시 노드 curr 생성

	while (curr->next != NULL)
	{
		if (curr->alpha > curr->next->alpha)
		{
			tmp = curr->next;               // 옮길 노드를 임시 저장
			curr->next = curr->next->next;  // 옮길 노드 빼고 연결 
			tmp->next = head->Head;         // tmp 다음 첫 노드 연결
			head->Head = curr = tmp;        // 헤더 노드=현재 노드=tmp
			continue;
		}
		curr = curr->next;
	}
}


/// <summary>
/// 노드 출력 함수
/// </summary>
void printNode(HeadNode* head)
{
	printf("\n");
	Node* curr = head->Head;        // 임시 노드 생성

	if ('Z' >= curr->alpha)         // 첫 문자가 대문자가 있을때 
	{
		printf("대문자 : ");
		while ('Z' >= curr->alpha)      // 대문자 출력
		{
			printf("%c ", curr->alpha);
			curr = curr->next;

			if (curr->next == NULL)     // curr->next가 NULL이면 제일 마지막 배열이라는뜻 => 소문자가 없음
			{
				printf("\n소문자 배열이 없습니다.\n");
				return;
			}
		}
	}

	else
	{
		printf("대문자 배열이 없습니다.\n");
	}



	printf("\n소문자 : ");
	while (curr != NULL)            // 소문자 출력
	{
		
		printf("%c ", curr->alpha);
		curr = curr->next;
	}
	printf("\n");
}