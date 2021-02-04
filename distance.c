//WAP to find the distance between two point using 4 functions.
#include <stdio.h>
#include <math.h>
float a,b,p,q;
void getValue()
{
    printf("Enter coordinates of point1:");
    scanf("%f%f",&a,&b);
    printf("Enter coordinates of point2:");
    scanf("%f%f",&p,&q);
}
double getDistance()
{
    double d= sqrt((p-a)*(p-a)+(q-b)*(q-b));
    return d;
}
void display()
{
   printf("The distance between %f,%f and %f,%f is %f\n",a,b,p,q,getDistance());
}
int main()
{
    getValue();
    display();
}
