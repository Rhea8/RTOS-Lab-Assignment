#include<stdio.h>
int cond1(char *argv[]);
int findsum(char *argv[]);
float findavg(char *argv[]);
int findprod(char *argv[]);

int main(int argc,char *argv[])
{
int i,a, sum, avg, prod;
for(i=1;i<11;i++)
{
a=atoi(argv[i]);
if(a!=999 && (i==0))
{
continue;
}
else if(a!=999 && (i>0))
{
continue;
}
else
{
 break;
}
}
sum=findsum(argv);
printf("Sum = %d \n", sum);
avg= findavg(argv);
printf("Average = %d \n",avg);
prod=findprod(argv);
printf("Product = %d \n",prod);
}

int findsum(char *argv[])
{
int j, sum=0;
for(j=0;j<10;j++)
{
sum=sum+atoi(argv[j]);
}
return sum;
}


float findavg(char *argv[])
{                                                                                                                                                                                                        $float avg=0;
for(j=0;j<10;j++)
{
avg=avg+atoi(argv[j]);
}
avg=avg/10;
return avg;
}


int findprod(char *argv[])
{
int j, prod=1;
for(j=0;j<10;j++)
{
prod=prod*atoi(argv[j]);
}
return prod;
}