// Queue implementation in C

// header files
#include <stdio.h>
#include <stdlib.h>

// Macros
#define SIZE 10 // size of queue

// Function declarations
void enQueue(int);
void deQueue(void);
void desplay(void);

// global declarations
int items[SIZE], front = -1, rear = -1;

void enQueue(int item){
    if(rear == SIZE - 1){
        printf("\nQueue is full");
    }else{
        if(front == -1){
            front = 0;
        }
        rear++;
        items[rear] = item;
        printf("\nInserted -> %d", item);
    }
}

void deQueue(void){
    if(front == -1){
        printf("\nQueue is empty");
    }else{
        printf("\nDelted item -> %d",items[front]);
        front++;
        if(front >  rear){
            front = rear = -1; // Queue reset
        }
    }
}

void display(void){
    if(rear == -1){
        printf("\nQueue is empty");
    }else{
        int i;
        printf("\nQueu elements are:\n");
        for(i = front; i <= rear; i++){
            printf("%d\t",items[i]);
        }
    }
}

int main(int argc, char const *argv[])
{
    printf("\nWelcome to Queue implementation in C\n");
    int queueItem,c;
    int choice;
    do{
        printf("Enter your choice\n1.Insert into queue\n2.Delete from queue\n3.Display Queue\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter element\t");
                scanf("%d", &queueItem);
                enQueue(queueItem);
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
        printf("\nDo you want to continue\t1 for yes\t\t");
        scanf("%d", &c);
    }while(c == 1);
    return 0;
}
