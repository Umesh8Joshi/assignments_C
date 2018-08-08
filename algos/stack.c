// Stack data structure implementation in C

// header files
#include <stdio.h>

// Macros
#define MAX 10 // max stack size

// Structure for stack
struct Stack{
    int items[MAX];
    int top;
};

typedef struct Stack stack;

// function definations
void createEmptyStack(stack*);
int isFull(stack*);
int isEmpty(stack*);
void push(stack*);
void pop(stack*);

/*-----------------------------*/

void createEmptyStack(stack *s){
    s->top = -1;
}

int isFull(stack *s){
    if(s->top == MAX - 1)
        return 1;
    else
        return 0;
}

int isEmpty(stack *s){
    if(s->top == -1)
        return 1;
    else
        return 0;
}

void push(stack *s){
    int newItem;
    printf("\nEnter new item :\t");
    scanf("%d", &newItem);
    if(isFull(s)){
        printf("\nSTACK IS FULL !!!!\n");
    }else{
        s->top++;
        s->items[s->top] = newItem;
    }
}

void pop(stack *s){
    if(isEmpty(s)){
        printf("\nSTACK is EMPTY !!\n");
    }else{
        printf("\nItem Poped  -> %d", s->items[s->top]);
        s->top--;
    }
}

int main(void)
{
    int ch = 2;
    int loop = 1;
    stack *s;
    createEmptyStack(s);
    do{
        printf("\n**** STACK OPERATIONS ****\n");
        //printf("1.\tPUSH\n2.\tPOP\n3.\tEXIT\nCHOICE : \t");
        //scanf("%d", &ch);
        switch(ch){
            case 1:
                push(s);
                break;
            case 2:
                pop(s);
                break;
            case 3:
                printf("\n----EXIT----\n");
                loop = 0;
                break;
            default:
                printf("\nWrong Choice\n");
                break;
        }
    }while(loop);
    return 0;
}
