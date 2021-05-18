/*
Queue : FIFO 구조 => 처음 들어간게 처음 나가는 구조

rear : 입구
front : 출구


원형큐
마지막방을 항상 비워둠. (꽉찼을때랑 비었을때랑 구분하기위해)
rear == front     => empty
rear + 1 == front => full   

*/


// 원형 큐를 구현해보자.

