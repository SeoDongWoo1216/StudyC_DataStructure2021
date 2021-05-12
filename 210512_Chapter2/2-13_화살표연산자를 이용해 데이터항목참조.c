/*
화살표 연산자 : ->
구조체 포인터 변수에서 포인터가 가리키는 구조체 변수의 데이터항목을 지정하기위해 사용

Sptr -> name = "이순신";
(*Sptr).name = "이순신;  // 둘은 같은 코드이다.


구조체는 자료형만 동일하다면 복사가 가능하다.
변수도 같은 자료형만 복사 되는것처럼 구조체도 변수처럼 생각해라.
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
	strcpy(Sptr->name, "이순신");
	Sptr->year = 2015;
	Sptr->pay = 5900;

	printf("\n 이름 : %s", Sptr->name);
	printf("\n 입사 : %d", Sptr->year);
	printf("\n 연봉 : %d", Sptr->pay);

	getchar(); // 엔터치면 프로그램종료되고, 꺼짐
	           // 문자 입력받을때 사용(1 누르고 엔터하면 1, 엔터가 들어갔다가 1만 리턴됨)

	return 0;
}