
#include<stdio.h>

int main() 
{
	int i;
	char string1[20] = "Dreams come true!";
	char string2[20];
	char* ptr1, * ptr2;

	ptr1 = string1;
	printf("\n string1�� �ּ� : %u \t ptr1 = %u", string1, ptr1); // string1 �ּҿ� ptr1�� �ּ� ���
	printf("\n string1 = %s \n ptr1 = %s", string1, ptr1);  // string1�� ����� ptr1�� ����Ű�� ���ڿ� ���
	printf("\n\n %s", ptr1 + 7);  // �迭 7��° ����� ���
	
	ptr2 = &string1[7];
	printf("\n %s \n\n", ptr2);

	for (i = 16; i >= 0; i--)  // ���ڿ� �� ���������� ��ó������ �ϳ��� ���(�Ųٷ����)
	{
		putchar(*(ptr1 + i));
	}

	for (i = 0; i < 20; i++)   // string2�� stinrg1�� �迭��Ҹ� �ϳ��� ����
	{
		string2[i] = *(ptr1 + i);
	}

	printf("\n\n string1 = %s", string1);  // string1 ���
	printf("\n string2 = %s", string2);    // stirng2 ���


	*ptr1 = 'P';
	*(ptr1 + 1) = 'e';
	*(ptr1 + 2) = 'a';
	*(ptr1 + 3) = 'c';
	*(ptr1 + 4) = 'e';
	printf("\n\n string1 = %s\n", string1);

	return 0;
}