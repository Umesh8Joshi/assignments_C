// Circular queue implementation in C
// Circular queue saves the space left behind doing dequeuing

// Headers
#include <stdio.h>
#include <stdlib.h>

// Macros
#define SIZE 10 // size of circular queue

// Function definations
int isFull(void);
int isEmpty(void);
void enQueue(int);
int deQueue(void);
void display(void);

// global declarations
int items[SIZE]; // queue
int front = -1, rear = -1;

int isFull(void){
    if((front == rear +1) || (front == 0 && rear == SIZE - 1)) return 1;
    return 0;
}

int isEmpty(void){
    if(front == -1 ) return 1;
    return 0;
}

void enQueue(int item){
    if(isFull()) printf("\nQueue is full");
    else{
        if(front == -1) front = 0;
        rear = (rear + 1)%SIZE;
        items[rear] = item;
        printf("\nInserted -> %d", item);
    }
}

int deQueue(void){
    int item;
    if(isEmpty()){
        printf("\nQueue is empty");
        return -1;
    }else{
        item = items[front];
        if(front == rear){
            front = -1;
            rear = -1;
        }else{
            front = (front + 1)%SIZE;
        }
        printf("\nDeleted item -> %d",item);
        return item;
    }
}

void display(void){
    int i;
    if(isEmpty()) printf("\nQueue is empty");
    else{
        printf("\nFront is -> %d\nItems\t", items[front]);
        for(i = front + 1; i < rear; i++){
            printf("%d\t", items[i]);
        }
        printf("\nRear is -> %d\n", items[rear]);
    }
}

int main()
{
    printf("\nCircular queue implementation using C\n");
    int c,item;
    int choice;
    do{
        printf("\n1.Insert Item\n2.Remove Item\n3.Display Item\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:   
                printf("\nEnter value -> \t\t");
                scanf("%d", &item);
                enQueue(item);
                break;
            case 2:
                deQueue();
                break;
            case 3:   
                display();
                break;
            default:
                printf("\nWrong choice\n");
                break;
        }
        printf("\nDO you want to continue 1. for yes\t\t");
        scanf("%d", &c);
    }while(c == 1);
    return 0;
}