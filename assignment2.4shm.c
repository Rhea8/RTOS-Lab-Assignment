#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>

int main(void)
{
    char str[10] = { 0 };
int i,shmid,pid,c=0,count;
key_t key;
int *shmptr;
int pipefd[2];
    printf("enter a string\n");
    fgets(str, 10, stdin);
    for(i=0;str[i]!='\0';i++);

   printf("Length %d \n", i-1);
shmid=shmget(key,100,IPC_CREAT|0666);
if (shmid < 0) 
     {
          printf("shmget error (server) \n");
          exit(1);
     }
shmptr=(int *) shmat(shmid,NULL,0);
if ((int)shmptr == -1) 
     {
          printf("shmat error (server) \n");
          exit(1);
     }
pid=fork();
if(pid==0)
{
printf("Inside child process\n");
while (str[c] != '\0') 
{
    if (str[c] == 'a' || str[c] == 'A' || str[c] == 'e' || str[c] == 'E' || str[c] == 'i' || str[c] == 'I' || str[c] =='o' || str[c]=='O' || str[c] == 'u' || str[c] == 'U')
      count++;
    c++;
  }
printf("No. of vowels in string: %d\n",count);
exit(1);
}
else
{
wait(1);
shmdt((void *) shmptr);
printf("the parent process has detached the shared memory\n ");
                  shmctl(shmid, IPC_RMID, NULL); // remove
          printf("the parent process has removed the shared memory...\n");
return 0;
}
}
