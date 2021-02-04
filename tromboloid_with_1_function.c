//Write a program to find the volume of a tromboloid using one function
#include <stdio.h>
int main()
{
    double h,b,d,v;
    printf("Enter h:");
    scanf("%lf",&h);
    printf("Enter d:");
    scanf("%lf",&d);
    printf("Enter b:");
    scanf("%lf",&b);
    if(b==0)
        printf("b cannot be 0\n");
    else
    {
        v=(1/3.0)*((h*d*b)+(d/b));
        printf("Volume of tromboloid is: %lf\n",v);
    }
    return 0;
}
