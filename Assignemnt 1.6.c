#include<stdio.h>
typedef struct date
{
int day;
int month;
int year;
}dat;
int main()
{
dat d1, d2;
printf("Enter the Day:\t");
scanf("%d",&d1.day);
printf("Enter the month:");
scanf("%d",&d1.month);
printf("Enter the year:\t");
scanf("%d",&d1.year);
printf("Enter the Day:");
scanf("%d",&d2.day);                                                                                                                                                                                 scan$printf("Enter the month:");
scanf("%d",&d2.month);                                                                                                                                                                                sca$printf("Enter the year:");
scanf("%d",&d2.year);

if(d1.year>d2.year)
{
printf("%d%d%d",d1.day,d1.month,d1.year);
}
else if((d1.year==d2.year)&&(d1.month>d2.month))
{
printf("%d%d%d",d1.day,d1.month,d1.year);
}
else if((d1.year==d2.year)&&(d1.month==d2.month)&&(d1.day>d2.day))
{printf("%d%d%d",d1.day,d1.month,d1.year);}
else
{
printf("%d.%d.%d",d2.day,d2.month,d2.year);
}

}