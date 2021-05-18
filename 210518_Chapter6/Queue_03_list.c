#include <stdio.h>
#include <stdlib.h>

typedef struct QNode {
    int data;
    struct QNode* next;
}QNode;

typedef struct {
    QNode* front;
    QNode* rear;
}NodeType;

/*
        -------------------
  rear ->                      -> front
        -------------------
*/

NodeType* createQueueNode()
{
    NodeType* Node;
    Node = (NodeType*)malloc(sizeof(NodeType));
    if (Node == NULL) 
    {
        printf("메모리 할당 실패!\n");
        return;
    }
    else 
    {
        Node->front = NULL;
        Node->rear = NULL;
        return Node;
    }
}


int Empty(NodeType* Node)
{
    if (Node->front == NULL)
    {
        printf("Queue에 자료가 없다!!\n");
        return 1;   //true 를 준것 
    }
    else
    {
        return 0;   //false 를 준것
    }
}


void enQueue(NodeType* Q, int data)
{
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    newNode->data = data;
    newNode->next = NULL;

    if (Q->front == NULL) // 큐에 아무고토 없을 때 
    {
        Q->front = newNode;
        Q->rear = newNode;
    }
    else                  // 그 외 
    {
        Q->rear->next = newNode;
        Q->rear = newNode;
    }
}


void deQueue(NodeType* Q)
{
    QNode* del = Q->front;

    if (Empty(Q)) return 0;
    else
    {
        Q->front = Q->front->next;
        free(del);
    }
}


void printQ(NodeType* Q)
{
    QNode* Node = Q->front;
    if (Empty(Q)) return 0;
    else
    {
        while (Node)
        {
            printf("%d\n", Node->data);
            Node = Node->next;
        }
    }

}


int main()
{
    NodeType* Q = createQueueNode();

    enQueue(Q, 1);
    enQueue(Q, 2);
    enQueue(Q, 3);
    enQueue(Q, 4);

    deQueue(Q);
    deQueue(Q);

    printQ(Q);

    return 0;
}