//Write a program to add two user input numbers using one function.
#include <stdio.h>
int sum(int a,int b)
{
    return a+b;
}
int main()
{
    int a,b;
    printf("Enter Number:");
    scanf("%d",&a);
    printf("Enter Number:");
    scanf("%d",&b);
    printf("Sum of %d and %d is %d",a,b,sum(a,b));
    return 0;
}
