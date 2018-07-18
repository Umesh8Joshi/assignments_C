#include <stdio.h>
#include <ctype.h>

int main()
{
    char name[50];

    // ask user for name
    printf("What is your name? ");
    //scanf("%s", name);
    fgets(name, 49, stdin);

    printf("Hello. Your name is ");
    int ii = 1, foundSpace = 0;
    printf("%c", name[0]);
    while (name[ii] != '\0')
    {
        if (name[ii]==' ') foundSpace = 1;
        if (foundSpace == 0 && isupper(name[ii])) {
          printf(" %c", name[ii]);
        }
        else {
          putchar(name[ii]);
          foundSpace = 0;
        }
        ii++;
    }
    return 0;
}