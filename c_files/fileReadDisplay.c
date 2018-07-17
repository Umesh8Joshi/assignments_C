/* Program to read file from command line arguments and showing the content on screen */

#include <stdio.h>

int main(int argc, char *argv[]){    
    FILE *fp;
    char *filename;
    char ch;

    // Check if a filename has been specified in the command
    if (argc < 2){
            printf("Missing Filename\n");
            return(1);
    }
    else{
            filename = argv[1];
            //printf("Filename : %s\n", filename);
    }
    fp = fopen(filename,"r");
    if(fp){
            while ( (ch = fgetc(fp)) != EOF ){
                    fprintf(stdout, "%c",ch);
                    }
    }
    else{
            fprintf(stderr, "Failed to open file, check for permissions\n");
            }

    return(0);
}