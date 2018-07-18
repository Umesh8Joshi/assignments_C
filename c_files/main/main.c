#include "main.h"

int main(int argc, char **argv){
    FILE *fptr;
    char *filename;
    char data[200]; // data read from 
    filename = argv[1];
    fptr = fopen(filename, "r");
    fgets(data, 200, fptr); //  get strings from file
    fprintf(stdout, "%s", data);
    fclose(fptr);
    return 0;
}