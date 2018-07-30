// Main file

#include "main.h"

void printData(struct User);
struct User enterData(struct User);
struct node* createList(struct User);
struct node* addToList(struct User, bool);
void print_list(void);
int menu(void);
int delFromList(char*);
struct node* searchInList(char*,struct node**);

// Initial Linked List
struct node *head = NULL;
struct node *curr = NULL;

int main(int argc, char const *argv[])
{
    struct User p;
    int i;
    fprintf(stdout, "Welcome to Hospital Management System\n");
    p = enterData(p);
    addToList(p, false);
    fprintf(stdout, "\n\nList has been created\n\n");
    while(true){
        i = menu();
        if(i == 5){
            break;
        }
    }
    return 0;
}

void printData(struct User p){
    fprintf(stdout, "\n\nData of given Patient\n");
    fprintf(stdout, "Name :\t\t %s\nAge : \t\t %d\n", p.name, p.age);
    fprintf(stdout, "Address\nHouse Name : \t\t %s\nStreet Name : \t\t %s\nCity Name : \t\t %s\n\n",p.address.houseName,p.address.street,p.address.city);
    fprintf(stdout, "\nSymptoms\n");
    for(int i = 0;i < p.numSymp; i++){
        fprintf(stdout, "%s\t", p.symp[i]);
    }
}

struct User enterData(struct User p){
    fprintf(stdout, "Enter name of Patient\n");
    scanf(" %[^\n]p.name", p.name);
    fprintf(stdout, "Enter Age of %s\n", p.name);
    scanf("%d", &p.age);
    fprintf(stdout, "Enter address of %s\n", p.name);
    fprintf(stdout, "Enter house name\t\t");
    scanf("%s", p.address.houseName);
    fprintf(stdout, "Enter Street Name\t\t");
    scanf("%s", p.address.street);
    fprintf(stdout, "Enter City Name\t\t");
    scanf("%s", p.address.city);
    fprintf(stdout, "\nEnter number of Symptoms\n");
    scanf("%d", &p.numSymp);
    for(int i = 0; i <p.numSymp; i++){
        scanf("%s",p.symp[i]);
    }
    return p;
}

struct node* createList(struct User p1){
    fprintf(stdout, "\n\n You are at the start of List\n\n");
    struct  node *ptr = (struct node*)malloc(sizeof(struct node));
    if(NULL == ptr){
        fprintf(stderr, "Creation Failed");
        return NULL;
    }
    ptr->p = p1;
    ptr->next = NULL;

    head = curr = ptr;
    
    return ptr;
}

struct node* addToList(struct User p1, bool at_end){
    if(NULL == head){
        createList(p1);
        return NULL;
    }else{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    // if(NULL == ptr){
    //     fprintf(stderr, "List Failed");
    //     return NULL;
    // }
    ptr->p = p1;
    ptr->next = NULL;
    // if(at_end){
    //     curr->next = ptr;
    //     curr = ptr;
    // }else{
    ptr->next = head;
    head = ptr;
    // }
    return ptr;
    free(ptr);
    }
}

struct node* searchInList(char *name, struct node **prev){
    struct node *ptr = head;
    struct node *tmp = NULL;
    bool found = false;
    while(ptr != NULL){
        fprintf(stdout, "%s", p.name);
        if(ptr->p.name == name){
            found = true;
            break;
        }else{
            tmp = ptr;
            ptr = ptr->next;
        }
    }

    if(found){
        if(prev){
            *prev = tmp;
        }
        return ptr;
    }else{
        return NULL;
    }
}

int delFromList(char *name){
    struct node *prev = NULL;
    struct node *del = NULL;
    fprintf(stdout, "Deleting %s's data", name);
    del = searchInList(name, &prev);
    if(del == NULL){
        fprintf(stderr, "Data not found");
        return -1;
    }else{
        if(prev != NULL){
            prev->next = del->next;
        }
        if(del == curr){
            curr = prev;
        }else if(del == head){
            head = del->next;
        }
    }
    free(del);
    del = NULL;
    return 0;
}

void print_list(void){
    struct node *ptr = head;
    while(ptr != NULL){
        printData(ptr->p);
        fprintf(stdout, "\n#######################################\n");
        ptr = ptr->next;
    }
}

int menu(void){
    int i = 0;
    struct User p;
    char delName[20];
    fprintf(stdout, "\nSelection Menu\n");
    fprintf(stdout, "1.\t\tAdd User\n2.\t\tUpdate User\n3.\t\tDelete User\n4.\t\tPrint ALL\n5.\t\tExit\n");
    scanf("%d", &i);
    switch(i){
        case 1:
            p = enterData(p);
            addToList(p, true);
            break;
        case 3:
            fprintf(stdout, "Enter name to be deleted");
            scanf(" %[^\n]delName", delName);
            delFromList(delName);
            break;
        case 4:
            print_list();
            break;
    }
    return i;
}