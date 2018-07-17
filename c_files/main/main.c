#include "main.h"

// int tokenString(char *);

int main(int argc, char *argv[])
{
    // FILE *fp;
    // char *filename;
    // char ch,data[100];
    // int i=0;
    // //check for proper command line argument
    // if(argc < 2){
    //     fprintf(stderr, "Missing Filename");
    //     return(-1);
    // }else{
    //     filename = argv[1];
    // }
    // fp = fopen(filename, "r");
    // if(fp){
    //     while((ch = fgetc(fp)) != EOF){
    //         // fprintf(stdout, "%c", ch);
    //     }
    //     // for(int j=0; j < data.length(); j++){
    //     //     fprintf(stdout, "%s\n", data[j]);
    //     // }
    //     // fprintf(stdout, "%s", data);
    //     // fprintf(stdout, "Data read successfully");
    // }else{
    //     fprintf(stderr, "Failed to open file");
    // }
    // tokenString(data);
    // for(i=0; data[i] != '\0'; ++i);
    // printf("%s",data);

    FILE *fp;
    char data[200], stored[][200];
    int i = 0;
    fp = fopen(argv[1], "r");
    while(fgets(data, 200, fp) != NULL){
        fprintf(stdout, "%s", data);
        i++;
    }
    fclose(fp);
    return 0;
}