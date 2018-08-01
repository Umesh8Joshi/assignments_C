/* Write a menu driven program to insert data of patient which will be stored in a linked list and at the termination of program it will save that data into a txt file */

/********************************************************************
 * @file    main.c                                                  *
 * @author  Umesh                                                   *
 * @brief   To enter data using linked list and writing into a file *
 * @date    01/08/2018                                              *
 ********************************************************************/

// header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// structure for linked list
struct Patient{
    int Age;
    char name[20];
    char houseName[20];
    char street[20];
    char city[20];
    char symp[50];
};

struct node{
    struct Patient patient;
    struct node *next;
};


// head and current node
struct node *head = NULL;
struct node *curr = NULL;

// Function declarations
void insertFirst(struct Patient);
struct Patient getData(void);
void printList(void);
void printGiven(struct node*);
int editChoiceOpt(void);
struct node* edit(void);
struct node* delete(void);
void fileSave(void);
void menu(void);

/**Function     insertFirst
 * @date        01/08/2018
 * @brief       Insert data at head
 * @param       struct Patient
 * @return      void
 */
void insertFirst(struct Patient p){
    struct node *link = (struct node*)malloc(sizeof(struct node));
    
    // All assignements
    strcpy(link->patient.name, p.name);
    strcpy(link->patient.houseName, p.houseName);
    strcpy(link->patient.street, p.street);
    strcpy(link->patient.city, p.city);
    strcpy(link->patient.symp, p.symp);
    link->patient.Age = p.Age;

    link->next = head;
    head = link;
}

/**Function     getData
 * @date        01/08/2018
 * @brief       get Data from keyboard
 * @param       struct Patient
 * @return      void
 */
struct Patient getData(void){
    struct Patient p;
    printf("\nEnter Name of Patient\t");
    scanf(" %[^\n]p.name",p.name);
    printf("\nEnter Age\t");
    scanf("%d", &p.Age);
    printf("\nEnter House Name\t");
    scanf("%s", p.houseName);
    printf("\nEnter Street Name\t");
    scanf("%s", p.street);
    printf("\nEnter City\t");
    scanf("%s", p.city);
    printf("\nEnter symptoms seperated by space\t");
    scanf(" %[^\n]p.symp", p.symp);
    return p;
}

/**Function     printlist
 * @date        01/08/2018
 * @brief       Print all data from linked list
 * @param       void
 * @return      void
 */
void printList(void){
    struct node *ptr = head;
    printf("\nPrinting all data\n");
    while(ptr != NULL){
        printf("######################\n");
        printf("Name :\t%s\n",ptr->patient.name);
        printf("Age :\t%d\n",ptr->patient.Age);
        printf("Address\n");
        printf("House name :\t %s\n", ptr->patient.houseName);
        printf("Street :\t%s\n", ptr->patient.street);
        printf("City :\t%s\n", ptr->patient.city);
        printf("Symptoms :\t%s\n\n",ptr->patient.symp);
        ptr = ptr->next;
    }
}

/**Function     printGiven
 * @date        01/08/2018
 * @brief       Print particular item from linked list
 * @param       struct node pointer
 * @return      void
 */
void printGiven(struct node* n){
    printf("$$$$$$$$$$$$$$$$$$$$\n");
    printf("Name :\t %s\n", n->patient.name);
    printf("Age :\t %d\n", n->patient.Age);
    printf("\t\tAddress\n");
    printf("House name :\t %s\n", n->patient.houseName);
    printf("Street :\t %s\n", n->patient.street);
    printf("City :\t %s\n", n->patient.city);
    printf("Symptoms :\t %s", n->patient.symp);
}

/**Function     editChoice
 * @date        01/08/2018
 * @brief       get choice for editing data
 * @param       struct Patient
 * @return      int : choice entered by user
 */
int editChoiceOpt(){
    int choice = 0;
    printf("Enter choice\n1.\tTo edit Name\n2.\tTo edit Age\n3.\tTo edit Address\n4.\tTo edit Symptoms\n5.\tBack to MAIN\n");
    scanf("%d", &choice);
    return choice;
}

/**Function     edit()
 * @date        01/08/2018
 * @brief       edit particular item from list
 * @param       void
 * @return      struct nod pointer
 *                  : NULL if not found
 */
struct node* edit(){
    struct node *curr = head;
    char nameToFind[20];
    printf("Enter the Name to find data of");
    scanf("%s", nameToFind);
    if(head == NULL){
        printf("No data found");
        return NULL;
    }

    while(strcmp(curr->patient.name, nameToFind) != 0){
        if(curr->next == NULL){
            printf("No data found");
            return NULL;
        }else{
            curr = curr->next;
        }
    }
    printf("Data found following is entered\n");
    printGiven(curr);
    int editChoice = 0;
    choiceMenu: editChoice = editChoiceOpt();
    switch(editChoice){
        case 1:
            printf("Enter Name\t");
            scanf(" %[^\n]curr->patient.name", curr->patient.name);
            goto choiceMenu;
        case 2:
            printf("Enter Age\t");
            scanf("%d",&curr->patient.Age);
            goto choiceMenu;
        case 3:
            printf("Enter Address\n");
            printf("Enter Hous Name\t");
            scanf("%s", curr->patient.houseName);
            printf("\nEnter Street\t");
            scanf("%s", curr->patient.street);
            printf("\nEnter City\t");
            scanf("%s", curr->patient.city);
            goto choiceMenu;
        case 4:
            printf("Enter Symptoms\t");
            scanf(" %[^\n]curr->patient.symp", curr->patient.symp);
            goto choiceMenu;
        case 5:
            break;
    }
    return curr;
}

/**Function     delete
 * @date        01/08/2018
 * @brief       delete particular item from linked list
 * @param       void
 * @return      struct node pointer
 *                  : NULL if not found
 */
struct node* delete(){
    struct node* curr = head;
    struct node* prev = NULL;

    char delName[20];
    printf("Enter name to be deleted");
    scanf("%s", delName);

    if(head == NULL){
        printf("No data found");
        return NULL;
    }
    while(strcmp(curr->patient.name, delName) != 0){
        if(curr->next == NULL){
            printf("No data found");
            return NULL;
        }else{
            prev = curr;
            curr = curr->next;
        }
    }

    // Match found
    if(curr == head){
        head = head->next;
    }else{
        prev->next = curr->next;
    }
    return curr;
}

/**Function     fileSave
 * @date        01/08/2018
 * @brief       write to a file
 * @param       void
 * @return      void
 */
void fileSave(void){
    FILE *fp;
    fp = fopen("hospital.txt", "w");
    struct node* curr = head;
    if(curr == NULL){
        fclose(fp);
    }else{
        while(curr != NULL){
            fprintf(fp, "-----------------------------------");
            fprintf(fp, "\nName :\t %s", curr->patient.name);
            fprintf(fp, "\nAge :\t %d", curr->patient.Age);
            fprintf(fp, "\n\t\tAddress");
            fprintf(fp, "\nHouse Name:\t%s", curr->patient.houseName);
            fprintf(fp, "\nStreet    :\t %s", curr->patient.street);
            fprintf(fp, "\nCity      :\t %s", curr->patient.city);
            fprintf(fp, "\nSymptoms  :\t %s", curr->patient.symp);
            fprintf(fp, "\n");
            curr = curr->next;
        }
        fclose(fp);
    }
}

/**Function     menu
 * @date        01/08/2018
 * @brief       main menu for choices
 * @param       void
 * @return      void
 */
void menu(void){
    int choice = 0;
    printf("\nWelcome to Hospital managment System\nPlease select your option");
    printf("1.\tInsert Data\n2.\tDelete Data\n3.\tEdit Data\n4.\tPrint All\n5.\tExit\n");
    char c = getchar();
    if(isdigit(c)){
        choice = (int)c;
    }else{
        printf("%c", c);
        printf("\n\n\t\tWrong Choice\n\n");
        menu();
    }
    switch(choice){
        case '1':
            insertFirst(getData());
            menu();
            break;
        case '2':
            delete();
            menu();
            break;
        case '3':
            edit();
            menu();
            break;
        case '4':
            printList();
            menu();
            break;
        case '5':
            fileSave();
            break;
    }
}

int main()
{
    menu();
    return 0;
}