/*
ȭ��ǥ ������ : ->
����ü ������ �������� �����Ͱ� ����Ű�� ����ü ������ �������׸��� �����ϱ����� ���

Sptr -> name = "�̼���";
(*Sptr).name = "�̼���;  // ���� ���� �ڵ��̴�.


����ü�� �ڷ����� �����ϴٸ� ���簡 �����ϴ�.
������ ���� �ڷ����� ���� �Ǵ°�ó�� ����ü�� ����ó�� �����ض�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct employee 
{
	char name[10];
	int year;
	int pay;
};

int main() 
{
	struct employee Lee;
	struct employee* Sptr = &Lee;
	strcpy(Sptr->name, "�̼���");
	Sptr->year = 2015;
	Sptr->pay = 5900;

	printf("\n �̸� : %s", Sptr->name);
	printf("\n �Ի� : %d", Sptr->year);
	printf("\n ���� : %d", Sptr->pay);

	getchar(); // ����ġ�� ���α׷�����ǰ�, ����
	           // ���� �Է¹����� ���(1 ������ �����ϸ� 1, ���Ͱ� ���ٰ� 1�� ���ϵ�)

	return 0;
}