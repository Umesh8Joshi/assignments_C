/* Program to take a string and tokenize it by given separater 
 * Store that data into an array
 */

#include <stdio.h>
#include <string.h>

int main(){
    char str[] = "Testing the code";
    char *token;
    char *rest = str;
    //using strtok from string to tokenize
    while((token = __strtok_r(rest, " ", &rest))){
        fprintf(stdout, "%s\n", token);
    }
    return(0);
}