//Write a program to add two user input numbers using one function.
#include <stdio.h>
int sum()
{
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    return a+b;
}
int main()
{
    printf("Enter two numbers:");
    printf("The sum of numbers is : %d",sum());
    return 0;
}
