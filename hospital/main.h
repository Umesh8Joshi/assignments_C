// Main header file

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct Address{
    char houseName[50];
    char street[50];
    char city[50];
};

struct User{
    char name[50];
    int age;
    int numSymp;
    char symp[4][10];
    struct Address address;
}p;

struct node{
    struct User p;
    struct node* next;
};