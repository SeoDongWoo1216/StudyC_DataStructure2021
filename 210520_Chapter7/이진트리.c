/*
트리의 모든 노드의 차수를 2 이하로 제한하여 전체 트리의 차수가 2 이하가 되도록
정의한 것이 이진(바이너리) 트리이다.

이진트리는 좌우가 구분된 왼쪽과 오른쪽 노드 두개만 가질 수 있다.(공백이나 1개의 트리도 가능)

순회는 원소를 빠트리거나 중복하지않고 처리하는 연산을 의미한다.
현재 노드를 처리한 후에 어떤 노드를 처리할지 결정하는 기준을 정해놓은 순회연산이 필요함.

순회는 3가지가 있다.
전위 : 데이터처리하고 왼쪽에서 오른쪽으로 이동
중위 : 왼쪽이동하고 데이터처리하고 오른쪽으로 이동
후위 : 왼쪽에서 오른쪽으로 이동하고 데이터처리
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct btnode 
{
	char data;
	struct BtNode* left;
	struct BtNode* right;
}BtNode;


BtNode* makeBTNode(char data);
void makeLeftTree(BtNode* root, BtNode* sub);
void makeRightTree(BtNode* root, BtNode* sub );
void preOrder(BtNode* root);   // 전위 순회
void inOrder(BtNode* root);   // 중위 순회
void postOrder(BtNode* root);  // 후위 순회


int main() 
{
	// 트리 생성
	BtNode* b1 = makeBTNode('a');
	BtNode* b2 = makeBTNode('b');
	BtNode* b3 = makeBTNode('c');
	BtNode* b4 = makeBTNode('d');
	BtNode* b5 = makeBTNode('e');
	BtNode* b6 = makeBTNode('f');
	BtNode* b7 = makeBTNode('g');
	BtNode* b8 = makeBTNode('h');

	// 트리 연결
	makeLeftTree(b1, b2);
	makeRightTree(b1, b3);

	makeLeftTree(b2, b4);
	makeRightTree(b2, b5);

	makeLeftTree(b3, b6);
	makeRightTree(b3, b7);

	makeLeftTree(b4, b8);


	// 전위 순회
	preOrder(b1);
	printf("\n");

	// 중위 순회
	inOrder(b1);
	printf("\n");

	// 후위 순회
	postOrder(b1);
	printf("\n");
	return 0;
}


/// <summary>
/// 트리의 노드 정의(메모리 동적할당)
/// </summary>
BtNode* makeBTNode(char data)
{
	BtNode* newNode = (BtNode*)malloc(sizeof(BtNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void makeLeftTree(BtNode* root, BtNode* sub) 
{
	if (root->left != NULL)    // 기존 왼쪽에 서브트리가 있으면 삭제
	{
		free(root->left);
	}
	root->left = sub;          // 새로운 서브트리를 연결
}

void makeRightTree(BtNode* root, BtNode* sub) 
{
	if (root->right != NULL)   // 기존 오른쪽에 서브트리가 있으면 삭제
	{
		free(root->right);
	}
	root->right = sub;         // 새로운 서브트리를 연결
}


/// <summary>
/// 전위 순회 함수 : 데이터처리 -> 왼쪽서브 -> 오른쪽서브
/// </summary>
void preOrder(BtNode* root)   
{
	if (root == NULL)           // 뿌리 노드가 NULL이면 그냥 리턴
	{
		return;
	}
	printf("%c  ", root->data); // 데이터처리
	preOrder(root->left);       // 왼쪽이동
	preOrder(root->right);      // 오른쪽이동
	/*
	출력하고 왼쪽으로 이동
	a b d h e c f g
	*/
}


/// <summary>
/// 중위 순회 함수 : 왼쪽서브 -> 데이터처리 -> 오른쪽서브
/// </summary>
/// <param name="root"></param>
void inOrder(BtNode* root) 
{
	if (root == NULL)           // 뿌리 노드가 NULL이면 그냥 리턴
	{
		return;
	}
	inOrder(root->left);       // 왼쪽이동
	printf("%c  ", root->data); // 데이터처리
	inOrder(root->right);      // 오른쪽이동
	/*
	h d b e a f c g
	*/
}


/// <summary>
/// 후위 순회 함수 : 왼쪽서브 -> 오른쪽서브 -> 데이터처리
/// </summary>
void postOrder(BtNode* root) 
{
	if (root == NULL)
	{
		return;
	}
	postOrder(root->left);       // 왼쪽이동
	postOrder(root->right);      // 오른쪽이동
	printf("%c  ", root->data);  // 데이터처리
}