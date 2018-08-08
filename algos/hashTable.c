// Hash table implementation in C

#include <stdio.h>
#include <stdlib.h>

/* Node for storing item in an Linked List */
struct node{
    int key;
    int value;
    struct node *next;
};

/* For storing Linked list at each index of Hash Array */
struct arrayItem{
    struct node *head;
    struct node *tail;
};

struct arrayItem *array;

int size = 0; // number of elements present in Hash array
int max = 10; // Max number of elements in Hash array

// For generating hash codes as per key
int hashCode(int key){
    return  (key % max);
}

// Function definations
struct node *get_element(struct node *list, int find_index);
void remove_element(int key);
void rehash();
void init_array();
int find(struct node*, int);

void insert(int key, int value){
    float n = 0.0;
    // Load factor for checking if rehashing required or not

    int index = hashCode(key);

    struct node *list = (struct node*)array[index].head;
    // Extracting list at given index

    struct node *item = (struct node*)malloc(sizeof(struct node));
    // creating an item to insert into hash table
    item->key = key;
    item->value = value;
    item->next = NULL;

    if(list == NULL){
        /* There is no Linked list at given index */
        printf("inserting %d (key) and %d (value)\n", key, value);
        array[index].head = item;
        array[index].tail = item;
        size++;
    }else{
        /* Linked list is present at given Index already */

        int find_index = find(list, key);
        if(find_index == -1){
            /* key not found in existing linked list
             * Adding key at the end of list
             */

            array[index].tail->next = item;
            array[index].tail = item;
            size++;
        }else{
            /* Key present in Linked list
             * updating the data
             */

            struct node *element = get_element(list, find_index);
            element->value = value;
        }
    }

    // Load factor
    n = (1.0 * size) / max;
    if( n <= 0.75){
        printf("rehashing\n");
        rehash();
    }
}

void rehash(){
    struct arrayItem *temp = array;
    /* temp pointing to current Hash Table Array */

    int i = 0, n = max;
    size = 0;
    max = 2*max;

    array = (struct arrayItem*)malloc(max * sizeof(struct node));
    init_array();

    for(i = 0; i < n; i++){
        // Extracting list at position i from index
        struct node* list = (struct node*) temp[i].head;

        if(list == NULL){
            /* No item present then contiue */
            continue;
        }else{
            /* Presence of linked list at i
             * take 1 key by 1 and add it to
             * new hash table 
             */

            while(list != NULL){
                insert(list->key, list->value);
                list = list->next;
            }
            

        }
    }
    temp = NULL;
}

/* This function finds the given key in hash array
 * returns it's index
 * return -1 if not found 
 */

int find(struct node *list, int key){
    int retval = 0;
    struct node *temp = list;
    while(temp != NULL){
        if(temp->key == key){
            return retval;
        }
        temp = temp->next;
        retval++;
    }
    return -1;
}

/* Returns node at given node located at find given index */
struct node* get_element(struct node *list, int find_index){
    int i = 0;
    struct node *temp = list;
    while(i != find_index){
        temp = temp->next;
        i++;
    }
    return temp;
}

// To remove an element from Hash array
void remove_element(int key){
    int index = hashCode(key);
    struct node *list = (struct node*) array[index].head;

    if(list == NULL){
        printf("The key does not exists\n");
    }else{
        int find_index = find(list, key);
        if(find_index == -1){
            printf("This key does not exists\n");
        }else{
            struct node *temp = list;
            if(temp->key == key){
                array[index].head = temp->next;
                printf("The key has been removed\n");
                return;
            }

            while(temp->next->key != key){
                temp = temp->next;
            }if(array[index].tail == temp->next){
                temp->next = NULL;
                array[index].tail = temp;
            }else{
                temp->next = temp->next->next;
            }
            printf("Key has been removed\n");
        }
    }
}

void display(){
    int i = 0;
    for(i = 0; i < max; i++){
        struct node *temp = array[i].head;
        if(temp == NULL){
            printf("array[%d] has no value", i);
        }else{
            printf("array[%d] has elements:- ",i);
            while(temp != NULL){
                printf("key= %d\tvalue= %d\t",temp->key,temp->value);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}

void init_array(){
    int i = 0;
    for(i = 0; i < max; i++){
        array[i].head = NULL;
        array[i].tail = NULL;
    }
}

int size_of_array(){
    return size;
}

int main(int argc, char const *argv[]){
    int choice, key,value, n, c;
    array = (struct arrayItem*)malloc(max*sizeof(struct arrayItem*));
    init_array();

    do{
        printf("Implemntation of Hash Table chaining Linked list\n");
        printf("MENU-:: \n1. Inserting Item in Hash Table\n2. Removing Item from Hash Table\n3. Check size of Hash Table\n4. To display Hash Table\n\n Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nInserting value into Hash Table\n");
                printf("Enter key and value\t");
                scanf("%d %d", &key, &value);
                insert(key,value);
                break;
            
            case 2:
                printf("\nDeleting in Hash Table");
                printf("\nEnter key to delete\t");
                scanf("%d", &key);
                remove_element(key);
                break;
            
            case 3:
                n = size_of_array();
                printf("\nSize of Hash table is %d\n", n);
                break;
            
            case 4:
                display();
                break;
            
            default:
                printf("Wrong input");
        }

        printf("\n\nDo you want to continue - { press 1 for yes}\t");
        scanf("%d" ,&c);
    }while(c == 1);
    return 0;
}