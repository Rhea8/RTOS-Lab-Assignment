#include<stdio.h>
int cond1(int a[10]);
int findsum(int a[10]);
float findavg(int a[10]);
int findprod(int a[10]);

int main()
{
int i,cond, a[10], sum, avg, prod;
FILE *fptr;
if ((fptr = fopen("program.txt", "r"))!= NULL)
{
 for(i=0;i<10;i++)
{ fscanf(fptr,"%d",a[i]);
 printf("Data from the file:\n%d", a[i]);
if(a[i]!=999 && (i==0))
{continue;
}
else if(a[i]!=999 && (i>0))
{
continue;
}
else
{
 break;
}
}
}
sum=findsum(a);
printf("Sum = %d \n", sum);
avg= findavg(a);
printf("Average = %d \n",avg);
prod=findprod(a);
printf("Product = %d \n",prod);
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


float findavg(int a[10])
{                                                                                                                                                                                                         int j;
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
