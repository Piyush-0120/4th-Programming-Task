//Write a program to add two user input numbers using 4 functions.
#include <stdio.h>
int a,b;
void getNum()
{
    printf("Enter Number:");
    scanf("%d",&a);
    printf("Enter Number:");
    scanf("%d",&b);
}
int getSum()
{
    return a+b;
}
void display()
{
    printf("Sum of %d and %d is: %d",a,b,getSum());
}
int main()
{
    getNum();
    display();
    return 0;
}
