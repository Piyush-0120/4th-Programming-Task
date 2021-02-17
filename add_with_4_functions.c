//Write a program to add two user input numbers using 4 functions.
#include <stdio.h>
int input()
{
    int a;
    printf("Enter Number:");
    scanf("%d",&a);
    return a;
}
int getSum(int a,int b)
{
    return a+b;
}
void display(int a,int b,int c)
{
    printf("Sum of %d and %d is: %d",a,b,c);
}
int main()
{
    int a,b,c;
    a=input();
    b=input();
    c=getSum(a,b);
    display(a,b,c);
    return 0;
}
