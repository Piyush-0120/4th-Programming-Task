//WAP to find the volume of a tromboloid using 4 functions.
#include <stdio.h>
double h,b,d;
void getValue()
{
    printf("Enter h:");
    scanf("%lf",&h);
    printf("Enter d:");
    scanf("%lf",&d);
    printf("Enter b:");
    scanf("%lf",&b);
}
double getVolume()
{
    double v= (1/3.0)*((h*d*b)+(d/b));
    return v;
}
void display()
{
    printf("Volume of tromboloid is: %lf\n",getVolume());
}
int main()
{
    getValue();
    display();
}
