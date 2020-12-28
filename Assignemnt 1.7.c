#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
    char str[10] = { 0 };
int i;
    printf("enter a string\n");
    fgets(str, 10, stdin);
    for(i=0;str[i]!='\0';i++);

   { printf("Length %d \n", i-1);
   }
return 0;
}