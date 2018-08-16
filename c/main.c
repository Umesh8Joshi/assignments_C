// Header Files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User{
    char name[20];
    long long int mobile;
    char area[20];
    char email[20];
};

struct Node{
    struct User user;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *curr = NULL;

// Function Definations
void insertFirst(struct User);
struct User getData(void);

void insertFirst(struct User u){
    struct Node *link = (struct Node*)malloc(sizeof(struct Node));
    strcpy(link->user.name,u.name);
    strcpy(link->user.email,u.email);
    strcpy(link->user.area,u.area);
    link->user.mobile = u.mobile;

    link->next = head;
    head = link;
}

struct User getData(void){
    struct User u;
    printf("\nEnter name of User :\t");
    scanf(" %[^\n]u.name", u.name);
    printf("\nEnter Mobile Number :\t");
    scanf("%lld", &u.mobile);
    printf("\nEnter email :\t");
    scanf("%s", u.email);
    printf("\nEnter Area :\t");
    scanf("%s", u.area);
    return u;
}

void printList(void){
    struct Node *ptr = head;
    printf("\nPrinting all data\n");
    while(ptr != NULL){
        printf("#######################");
        printf("\nName :\t%s\n", ptr->user.name);
        printf("Mobile :%lld\n", ptr->user.mobile);
        printf("Email :\t%s\n", ptr->user.email);
        printf("Area : \t%s\n\n", ptr->user.area);
        ptr = ptr->next;
    }
}

void printGiven(struct Node *n){
    printf("@@@@@@@@@@@@@@@@@@@@@");
    printf("Name :\t%s\n", n->user.name);
    printf("Mobile :\t%lld\n", n->user.mobile);
    printf("Email :\t%s\n", n->user.email);
    printf("Area : \t%s\n\n",n->user.area);
}

int editChoiceOpt(void){
    int choice = 0;
    printf("Enter Choice\n1.\tTo edit Name\n2.\tTo edit Mobile\n3.\tTo edit Email\n4.\tTo edit Area\n5.\tExit\n");
    scanf("%d", &choice);
    return choice;
}

struct Node* edit(void){
    struct Node *curr = head;
    char nameToFind[20];
    printf("\nEnter Name to Edit\t");
    scanf("%s", nameToFind);
    if(head == NULL){
        printf("\nList is empty");
        return NULL;
    }

    while(strcmp(curr->user.name, nameToFind ) != 0){
        if(curr->next == NULL){
            printf("\nData not Found");
            return NULL;
        }else{
            curr = curr->next;
        }
    }
    printf("\nData found given Below\n");
    printGiven(curr);
    int editChoice = 0;
    choiceMenu: editChoice = editChoiceOpt();
    switch(editChoice){
        case 1:
            printf("\nEnter Name :\t");
            scanf("%[^\n]curr->user.name",curr->user.name);
            goto choiceMenu;
        case 2:
            printf("\nEnter Mobile Number :\t");
            scanf("%lld", &curr->user.mobile);
            goto choiceMenu;
        case 3:
            printf("\nEnter Email :\t");
            scanf("%s", curr->user.email);
            goto choiceMenu;
        case 4:
            printf("\nEnter Area :\t");
            scanf("%s", curr->user.area);
            goto choiceMenu;
        case 5:
            break;
    }
    return curr;
}

struct Node* delete(void){
    struct Node* curr = head;
    struct Node* prev = NULL;

    char delName[20];
    printf("Enter Name to be deleted\t");
    scanf("%[^\n]delName", delName);
    if(head == NULL){
        printf("List is empty");
        return NULL;
    }

    while(strcmp(curr->user.name, delName) != 0){
        if(curr->next == NULL){
            printf("No Data found");
            return NULL;
        }else{
            prev = curr;
            curr = curr->next;
        }
    }

    if(curr == head){
        head = head->next;
    }else{
        prev->next = curr->next;
    }
    return curr;
}

int fileSave(void){
    struct Node* curr = head;
    if(curr == NULL){
        return 0;
    }else{
        FILE *fp;
        fp = fopen("directory.txt", "w");
        while(curr != NULL){
            fprintf(fp, "-----------------------------------");
            fprintf(fp, "\nName :\t %s", curr->user.name);
            fprintf(fp, "\nMobile : %lld", curr->user.mobile);
            fprintf(fp, "\nEmail :\t %s", curr->user.email);
            fprintf(fp, "\nArea :\t %s\n", curr->user.area);
            curr = curr->next;
        }
        fclose(fp);
    }
    return 0;
}

void menu(void){
    int choice = 0;
    printf("\nWelcome to Telephone Directory\nPlease select your option\n");
    printf("1.\tEnter\n2.\tEdit\n3.\tPrint All\n4.\tDelete\n5.\tSave and Exit\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            insertFirst(getData());
            menu();
            break;
        case 2:
            edit();
            menu();
            break;
        case 3:
            printList();
            menu();
            break;
        case 4:
            delete();
            menu();
            break;
        case 5:
            fileSave();
            break;
    }
}

int main(){
    menu();
    return 0;
}