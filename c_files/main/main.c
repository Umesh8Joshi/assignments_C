#include "main.h"

void printLine();

int main(int argc, char **argv){
    FILE *fptr;
    char *filename;
    char data[200]; // data read from
    short int i = 0;
    filename = argv[1];
    fptr = fopen(filename, "r");
    fgets(data, 200, fptr); //  get strings from file
    // fprintf(stdout, "%s", data);
    fclose(fptr);
    char *p = strtok(data, " ");
    char *words[10];
    while(p != NULL){
        words[i++] = p;
        p = strtok(NULL, " ");
    }
    printLine();
    for(i = 0;i < (int)(sizeof(words)/sizeof(words[0])); i++){
        fprintf(stdout, "word[%d]:\t%s\n",i,words[i]);
    }
    printLine();
    char *upperHold[10], *lowerHold[10];
    short int upperIndex=0, lowerIndex=0;
    for(i=0; i<(int)(sizeof(words)/sizeof(words[0])); i++){
        if(words[i][0] >= 'A' && words[i][0] <= 'Z'){
            upperHold[upperIndex++] = words[i];
        }else if(words[i][0] >= 'a' && words[i][0] <= 'z'){
            lowerHold[lowerIndex++] = words[i];
        }
    }
    i = 0;
    while(upperHold[i] != NULL){
        fprintf(stdout, "Upper[%d]\t%s\n",i,upperHold[i]);
        i++;
    }
    printLine();
    i = 0;
    while(lowerHold[i] != NULL){
        fprintf(stdout, "Lower[%d]\t%s\n",i,lowerHold[i]);
        i++;
    }
    printLine();
    return 0;
}

void printLine(){
    fprintf(stdout, "\n\n####################################\n\n");
}

/* Output
 * ./main smaple.txt

####################################

word[0]:        This
word[1]:        is
word[2]:        sample
word[3]:        text
word[4]:        to
word[5]:        check
word[6]:        the
word[7]:        working
word[8]:        of
word[9]:        program


####################################

Upper[0]        This
Upper[1]        H��0��


####################################

Lower[0]        is
Lower[1]        sample
Lower[2]        text
Lower[3]        to
Lower[4]        check
Lower[5]        the
Lower[6]        working
Lower[7]        of
Lower[8]        program


####################################
*/