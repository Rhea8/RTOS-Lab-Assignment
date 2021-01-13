#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>


int findsum(int a[10]);
float findavg(int a[10]);
int findprod(int a[10]);


struct Passing  {
    int array[LIMIT];
    int array_size;
    int sum;
}; typedef struct Passing arg_t;

int main()
{
int i, a[10], sum, avg, prod;
arg_t args;
printf("Enter 10 no.s\n");
for(i=0;i<10;i++)
{
scanf("%d", &a[i]);
}
pthread_t thread;
pthread_create(&thread, NULL, routine, &args);
pthread_join(thread, NULL);

}

int findsum(int a[10])
{
int j, sum=0;
for(j=0;j<10;j++)
{
sum=sum+a[j];
}
printf("Sum = %d \n", sum);
}

float findavg(int a[10])
{
int j;
float avg=0;
for(j=0;j<10;j++)
{
avg=avg+a[j];
}
avg=avg/10;
printf("Average = %d \n",avg);
}

int findprod(int a[10])
{
int j, prod=1;   
for(j=0;j<10;j++)                                                                                                                                                                                         for(j=0;j<10;j++)
{
prod=prod*a[j];
}
printf("Product = %d \n",prod);
}