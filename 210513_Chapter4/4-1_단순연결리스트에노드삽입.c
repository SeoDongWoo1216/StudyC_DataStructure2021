/*
순차나 연결리스트를 구분짓는법
삽입 삭제 안일어나면 순차리스트(배열)
삽입 삭제가 빈번하면 연결리스트

순차 자료구조 문제점
삽입 연산이나 삭제 연산 후에 물리 주소를 유지하기위해 원소들을 이동시키는 추가작업과 시간이 소요된다.
배열로 구현하니까 배열이 갖는 메모리 사용의 비효율성 문제를 그대로 가진다.
순차 자료구조에서의 연산 시간에 대한 문제와 저장 공간에 대한 문제를 개선한 자료표현 방법이 필요하다.


연결자료구조
자료의 논리적인 순서와 물리적인 순서가 불일치
  각 원소에 저장된 다음 원소의 주소에의해 순서가 연결되는 방식.
    물리적인 순서를 맞추기위한 오버헤드가 발생하지 않음.
  여러 개의 작은 공간을 연결하여 하나의 전체 자료구조를 표현.
     크기 변경이 유연하고 더 효율적으로 메모리 사용

연결리스트
리스트의 연결자료구조로 표현
연결하는 방식에따라 단순연결, 원형연결, 이중연결, 이중원형연결리스트로 나뉜다.

연결리스트의 노드
연결자료구조에서 하나의 원소를 표현하기위한 단위구조

데이터필드
원소값 저장, 저장할 원소의 형태에따라 하나 이상의 필드로 구성

링크필드
다음 노드의 주소를 저장
포인터(주소)를 사용하여 주소값 저장


리스트이름 week : 연결리스트의 시작을 가리키는 포인터 변수
- week는 연결리스트의 첫번째 노트를 가리킴과 동시에 연결된 리스트 전체를 의미한다.

공백 연결리스트 : 포인터 변수 week에 널 저장

각 노드의 필드에 저장한 값은 점 연산자를 사용해 액세스







realloc : 방 추가나 삭제할때쓰던 매크로함수
*/

#include <stdio.h>

int main() 
{

}