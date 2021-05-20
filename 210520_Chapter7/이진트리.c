/*
Ʈ���� ��� ����� ������ 2 ���Ϸ� �����Ͽ� ��ü Ʈ���� ������ 2 ���ϰ� �ǵ���
������ ���� ����(���̳ʸ�) Ʈ���̴�.

����Ʈ���� �¿찡 ���е� ���ʰ� ������ ��� �ΰ��� ���� �� �ִ�.(�����̳� 1���� Ʈ���� ����)

��ȸ�� ���Ҹ� ��Ʈ���ų� �ߺ������ʰ� ó���ϴ� ������ �ǹ��Ѵ�.
���� ��带 ó���� �Ŀ� � ��带 ó������ �����ϴ� ������ ���س��� ��ȸ������ �ʿ���.

��ȸ�� 3������ �ִ�.
���� : ������ó���ϰ� ���ʿ��� ���������� �̵�
���� : �����̵��ϰ� ������ó���ϰ� ���������� �̵�
���� : ���ʿ��� ���������� �̵��ϰ� ������ó��
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
void preOrder(BtNode* root);   // ���� ��ȸ
void inOrder(BtNode* root);   // ���� ��ȸ
void postOrder(BtNode* root);  // ���� ��ȸ


int main() 
{
	// Ʈ�� ����
	BtNode* b1 = makeBTNode('a');
	BtNode* b2 = makeBTNode('b');
	BtNode* b3 = makeBTNode('c');
	BtNode* b4 = makeBTNode('d');
	BtNode* b5 = makeBTNode('e');
	BtNode* b6 = makeBTNode('f');
	BtNode* b7 = makeBTNode('g');
	BtNode* b8 = makeBTNode('h');

	// Ʈ�� ����
	makeLeftTree(b1, b2);
	makeRightTree(b1, b3);

	makeLeftTree(b2, b4);
	makeRightTree(b2, b5);

	makeLeftTree(b3, b6);
	makeRightTree(b3, b7);

	makeLeftTree(b4, b8);


	// ���� ��ȸ
	preOrder(b1);
	printf("\n");

	// ���� ��ȸ
	inOrder(b1);
	printf("\n");

	// ���� ��ȸ
	postOrder(b1);
	printf("\n");
	return 0;
}


/// <summary>
/// Ʈ���� ��� ����(�޸� �����Ҵ�)
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
	if (root->left != NULL)    // ���� ���ʿ� ����Ʈ���� ������ ����
	{
		free(root->left);
	}
	root->left = sub;          // ���ο� ����Ʈ���� ����
}

void makeRightTree(BtNode* root, BtNode* sub) 
{
	if (root->right != NULL)   // ���� �����ʿ� ����Ʈ���� ������ ����
	{
		free(root->right);
	}
	root->right = sub;         // ���ο� ����Ʈ���� ����
}


/// <summary>
/// ���� ��ȸ �Լ� : ������ó�� -> ���ʼ��� -> �����ʼ���
/// </summary>
void preOrder(BtNode* root)   
{
	if (root == NULL)           // �Ѹ� ��尡 NULL�̸� �׳� ����
	{
		return;
	}
	printf("%c  ", root->data); // ������ó��
	preOrder(root->left);       // �����̵�
	preOrder(root->right);      // �������̵�
	/*
	����ϰ� �������� �̵�
	a b d h e c f g
	*/
}


/// <summary>
/// ���� ��ȸ �Լ� : ���ʼ��� -> ������ó�� -> �����ʼ���
/// </summary>
/// <param name="root"></param>
void inOrder(BtNode* root) 
{
	if (root == NULL)           // �Ѹ� ��尡 NULL�̸� �׳� ����
	{
		return;
	}
	inOrder(root->left);       // �����̵�
	printf("%c  ", root->data); // ������ó��
	inOrder(root->right);      // �������̵�
	/*
	h d b e a f c g
	*/
}


/// <summary>
/// ���� ��ȸ �Լ� : ���ʼ��� -> �����ʼ��� -> ������ó��
/// </summary>
void postOrder(BtNode* root) 
{
	if (root == NULL)
	{
		return;
	}
	postOrder(root->left);       // �����̵�
	postOrder(root->right);      // �������̵�
	printf("%c  ", root->data);  // ������ó��
}