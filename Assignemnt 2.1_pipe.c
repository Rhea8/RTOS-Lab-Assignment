
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int sum=0,prod=1,i,a[10];
float avg;
int findsum(int a[10]);
float findavg(int a[10]);
int findprod(int a[10]);
int main()
{
int i,pid,j, a[10], sum=0, avg, prod;
int pipefd[2];
printf("Enter 10 no.s\n");
 for(i=0;i<10;i++)
{
  scanf("%d", &a[i]);
}
pipe(pipefd);
pid=fork();
if(pid==0)
{
 printf("Entering child process\n");
sum=findsum(a);
printf("Sum:%d\n",sum);
write(pipefd[1], &sum, sizeof(sum));
close(pipefd[0]);
prod=findprod(a);
printf("Prod:%d\n",prod);
exit(1);
}
read(pipefd[0],&avg, 100);
avg=findavg(a);
printf("Avg:%d\n",avg);

close(pipefd[1]);
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