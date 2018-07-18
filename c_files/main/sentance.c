#include "main.h"
#include "rule.h"

int main(int argc, char **argv){
    FILE *fptr;
    char *filename;
    char buf[200]; // we will use it as buffer to hold data in one string
    filename = argv[1];
    fptr = fopen(filename, "r");
    fgets(buf,200,fptr);
    fclose(fptr);
    int i = 0;
    char *p = strtok(buf, " ");
    char *words[20];
    while(p != NULL){
        words[i++] = p;
        p = strtok(NULL, " ");
    }
    i = 0;
    while(words[i] != NULL){
        fprintf(stdout, "%s\n", words[i]);
        i++;
    }
    char *sentances[20];
    int j = 0;
    i = 0;
    while(words[i] != NULL){
        int flag = 0;
        if(isupper(words[i][0])){
            sentances[j] = words[i];
            flag = 1;
        }
        // if(flag == 1){
        //     while(*(words + 1) != NULL){
        //         if(islower(words[i+1][0])){
        //             // sentances[j] += words[i+1];
        //         }
        //     }
        // }
    }
    return 0;
}