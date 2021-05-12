#include <stdio.h>

// gets 는 띄어쓰기도 저장됨 (문자열 특화함수 -> 입력할때 배열을 넣음) 
// scanf 는 띄어쓰기 전까지 저장됨( 입력할때 %s를 넣음)
int main() 
{
	char student[2][3][20];
	for (int i = 0; i < sizeof(student) / sizeof(student[0]); i++) 
	{
		printf("\n학생 %d의 이름 : ", i + 1);
		gets(student[i][0]);
		printf("학생 %d의 학과 : ", i + 1);
		gets(student[i][1]);
		printf("학생 %d의 학번 : ", i + 1);
		gets(student[i][2]);
	}

	for (int i = 0; i < 2; i++) 
	{
		printf("\n\n 학생 %d", i + 1);
		for (int j = 0; j < 3; j++) 
		{
			printf("\n\t");
			for (int k = 0; student[i][j][k] != '\0'; k++) 
			{
				printf("%c", student[i][j][k]);
			}
		}
	}

	return 0;
}