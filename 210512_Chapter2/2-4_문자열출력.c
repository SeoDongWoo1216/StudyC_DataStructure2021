// ���� �迭�� ���ڿ��� �����ϰ� ����ϱ�
/*
char s1[] = "string";      // �ι��ڰ� ������ �����
char s2[] = {'s','t','r','i','n','g'}; // �ι��ڰ� ����� ������ ����

�ʱ�ȭ����� ���������������� s1ó�� �ʱ�ȭ�ϴ°� �� ���ϴ�.
*/

#include <stdio.h>

void main() 
{
	char str[20] = "Data Structure!";
	int i;
	int cnt = 0;
	printf("\n���� �迭 str[] : ");
	for (i = 0; str[i]; i++) 
	{
		cnt++;
		printf("%c", str[i]);
	}
	printf("\n\nfor�� ������ Ƚ�� : %d", cnt);
	getchar();
}