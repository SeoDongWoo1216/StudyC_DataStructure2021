#include <stdio.h>

int main() 
{
	int array[2][3][4];
	int value = 1;
	/*for (int i = 0; i < 2; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			for (int k = 0; k < 4; k++) 
			{
				array[i][j][k] = value;
				printf("array[%d][%d][%d] = %d\n", i, j, k, array[i][j][k]);
				value++;
			}
		}
	}*/

	printf("%d\n", sizeof(array));                                // 24 * 4 = 96 출력
	printf("%d\n", sizeof(array) / sizeof(array[0]));             // 96 / 48 = 2 출력
	printf("%d\n", sizeof(array[0]) / sizeof(array[0][0]));       // 48 / 16 = 3 출력
	printf("%d\n", sizeof(array[0][0]) / sizeof(array[0][0][0])); // 16 / 4 = 4 출력

	// 배열 요소의 길이를 동적으로 구하기
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
	{
		for (int j = 0; j < sizeof(array[0]) / sizeof(array[0][0]); j++)
		{
			for (int k = 0; k < sizeof(array[0][0]) / sizeof(array[0][0][0]); k++)
			{
				array[i][j][k] = value;
				printf("array[%d][%d][%d] = %d\n", i, j, k, array[i][j][k]);
				value++;
			}
		}
	}

	return 0;
}