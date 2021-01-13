#include<stdio.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<stdlib.h>

int sum=0,prod=1,i,a[10];

int findsum(int a[10]);
float findavg(int a[10]);
int findprod(int a[10]);

void main()
{
key_t key;
pid_t pid;
int j,i,shmid, a[10], sum=0, avg=0, prod=1;
int *shmptr;
printf("Enter 10 no.s\n");
for(i=0;i<10;i++)
{
scanf("%d", &a[i]);
}
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
printf("In Child Process\n");
sum=findsum(a);
printf("Sum:%d\n",sum);
shmptr[0] = sum;
prod=findprod(a);
printf("Prod:%d\n",prod);
exit(1);
}
else
{
wait(1);
int sum2;
avg=findavg(a);
printf("Avg:%d\n",avg);
shmdt((void *) shmptr);
printf("the parent process has detached the shared memory\n ");
                  shmctl(shmid, IPC_RMID, NULL); // remove
          printf("the parent process has removed the shared memory...\n");
}
}

int findsum(int a[10])
{
int j, sum=0;
for(j=0;j<10;j++)
{
sum=sum+a[j];
}
return sum;
}
float findavg(int a[10])                                                                                                                                                                                  {
int j;
float avg=0;
for(j=0;j<10;j++)
{
avg=avg+a[j];
}
avg=avg/10;
return avg;
}

int findprod(int a[10])
{
int j, prod=1;
for(j=0;j<10;j++)
{
prod=prod*a[j];
}
return prod;
}
