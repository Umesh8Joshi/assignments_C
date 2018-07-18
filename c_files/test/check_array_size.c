#include "stdio.h"

int main(int argc,char **argv){
    char *data[10]  ;
    data[0] = "test";
    data[1] = "test1";
    fprintf(stdout, "%lu",sizeof(data)/sizeof(data[0]));
    return 0;
}