/*
책 7-4 356~359예제

왼쪽에 작은값, 오른쪽에 큰값이 오는게 규칙 / 중복되면 안됨
*/

#include <stdio.h>
#include <stdlib.h>

typedef char element;
typedef struct treeNode 
{
	char key;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;


treeNode* searchBST(treeNode* root, char x);
treeNode* insertNode(treeNode* p, char x);
void deleteNode(treeNode* root, element key);
void displayInorder(treeNode* root);


int main() 
{
	treeNode* root = NULL;
	// searchBST(root, 'k');

	root = insertNode(root, 'a');
	
	insertNode(root, 'i');
	insertNode(root, 'c');
	insertNode(root, 'j');
	insertNode(root, 'b');
	insertNode(root, 'z');
	insertNode(root, 'o');

	//insertNode(root, 'b');
	//insertNode(root, 'c');
	//insertNode(root, 'd');
	//insertNode(root, 'e');
	//insertNode(root, 'f');
	//insertNode(root, 'g');

	displayInorder(root);
	printf("\n\n");

	deleteNode(root, 'i');
	displayInorder(root);
	return 0;
}


// 이진 탐색 트리에서 키값이 x인 노드의 위치를 탐색하는 연산
treeNode* searchBST(treeNode* root, char x)
{
	if (root == NULL) 
	{
		printf("루트가 없는데요?\n\n");
	}
	else
	{
		treeNode* p = root;
		while (p != NULL)
		{
			if (x < p->key)
			{
				p = p->left;
			}
			else if (x == p->key)
			{
				return p;
			}
			else
			{
				p = p->right;
			}
		}
		printf("\n 찾는 키가 없습니다.");
		return p;
	}
}


// 포인터 p가 가리키는 노드와 비교하여 노드 x를 삽입하는 연산
treeNode* insertNode(treeNode* p, char x)
{
	treeNode* newNode;
	if (p == NULL)
	{
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	else if (x < p->key)
	{
		p->left = insertNode(p->left, x);
	}
	else if (x > p->key)
	{
		p->right = insertNode(p->right, x);
	}
	else
	{
		printf("\n 이미 같은 키가 있습니다! \n");
	}

	return p;
}


// 루트 노드부터 탐색하여 키 값과 같은 노드를 찾아 삭제하는 연산
void deleteNode(treeNode* root, element key)
{
	treeNode* parent;
	treeNode* p;
	treeNode* succ;
	treeNode* succ_parent;
	treeNode* child;

	parent = NULL;
	p = root;
	while ((p != NULL) && (p->key != key))  // 삭제할 연산의 위치 탐색
	{
		parent = p;
		if (key < p->key) p = p->left;
		else p = p->right;
	}

	// 삭제할 노드가 없는 경우
	if (p == NULL)
	{
		printf("\n 찾는 키가 이진 트리에 없습니다!");
		return;
	}

	// 삭제할 노드가 단말 노드인 경우
	if ((p->left == NULL) && (p->right == NULL))
	{
		if (parent != NULL)
		{
			if (parent->left == p)
			{
				parent->left = NULL;
			}
			else
			{
				parent->right = NULL;
			}
		}
		else
		{
			root = NULL;
		}
	}

	// 삭제할 노드가 자식 노드를 한 개 가진 경우 (자식 노드를 삭제하고 손자노드와 부모노드를 연결)
	else if ((p->left == NULL) || (p->right == NULL))
	{
		if (p->left != NULL)
		{
			child = p->left;
		}
		else
		{
			child = p->right;
		}

		if (parent != NULL)
		{
			if (parent->left == p)
			{
				parent->left = child;
			}
			else
			{
				parent->right = child;
			}
		}
		else
		{
			root = child;
		}
	}

	// 삭제할 노드가 자식 노드를 두 개 가진 경우
	// (왼쪽의 경우)오른쪽이 제일 큰 값이기때문에 삭제할 노드 위치에 그 큰 값을 복사해주고 큰 값의 자리를 삭제
	else
	{
		succ_parent = p;
		succ = p->left;
		while (succ->right != NULL)   // 왼쪽 서브 트리에서 후계자 찾기
		{
			succ_parent = succ;
			succ = succ->right;
		}
		if (succ_parent->left == succ)
		{
			succ_parent->left = succ->left;
		}
		else
		{
			succ_parent->right = succ->left;
		}
		p->key = succ->key;
		p = succ;
	}
	free(p);
}


// 이진 탐색 트리를 중위 순회하면서 출력하는 연산
void displayInorder(treeNode* root)
{
	if (root)
	{
		displayInorder(root->left);
		printf("%c  ", root->key);
		displayInorder(root->right);
	}
}