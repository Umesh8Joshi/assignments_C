// Functions

// headers
#include <stdio.h>
#include <stdlib.h>
#include "normals.h"

// Function to swap two int by using pointers
void swap(int *a, int *b){
    if(a == b){
        return;
    }

    int temp = *a;
    *a = *b;
    *b = temp;
}

// function to print given array
void printIntArray(int *A, int size){
    int i;
    for(i = 0; i < size; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}


// create Array of random numbers
int *createIntArray(int size){
    int i;
    int *A = (int *)malloc(size * sizeof(int));
    for(i = 0; i < size; i++){
        A[i] = rand() % MAX_RAND_NUM;
    }
    return A;
}


void deleteIntArray(int *A){
    if(A){
        free(A);
    }
}


// function to compare items
int defaultComp(void *thiss, void *that){
    if( *(int *)thiss < *(int *)that){
        return -1;
    }else if( *(int *)thiss > *(int *)that){
        return 1;
    }else{
        return 0;
    }
}

int defaultDataToInt(void *data){
    return *(int *)data;
}