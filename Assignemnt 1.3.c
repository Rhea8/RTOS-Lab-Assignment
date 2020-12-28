#include<stdio.h>


int main(int argc,char *argv[])
{
int i, n, sum=0, avg=0, prod=1;
for(i=1;i<11;i++)
{
n=atoi(argv[i]);
sum=sum+n;
}
printf("Sum: %d\n",sum);
for(i=1;i<11;i++)
{
n=atoi(argv[i]);
prod=prod*n;
}
printf("Product: %d\n",prod);
for(i=0;i<11;i++)
{
n=atoi(argv[i]);
avg=avg+n;
}
avg=sum/10;
printf("Average: %d\n", avg);
}