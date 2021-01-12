#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
    char str[10] = { 0 };
int i,pid,c=0,count;
int pipefd[2];
pid=fork();
if(pid==0)
{
printf("In Child\n");
    printf("enter a string\n");
    fgets(str, 10, stdin);
    for(i=0;str[i]!='\0';i++);

   printf("Length %d \n", i-1);

write(pipefd[1], &str, sizeof(str));
close(pipefd[0]);
while (str[c] != '\0') 
{
    if (str[c] == 'a' || str[c] == 'A' || str[c] == 'e' || str[c] == 'E' || str[c] == 'i' || str[c] == 'I' || str[c] =='o' || str[c]=='O' || str[c] == 'u' || str[c] == 'U')
      count++;
    c++;
  }
printf("No. of vowels in string: %d\n",count);
exit(1);
}
wait(1);
return 0;
}
