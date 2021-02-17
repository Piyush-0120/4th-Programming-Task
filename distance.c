//WAP to find the distance between two point using 4 functions.
#include <stdio.h>
#include <math.h>

float input(char *s)
{
    float a;    
    printf("Enter %s:",s);
    scanf("%f",&a);
    return a;
}
float getDistance(float a,float b,float p,float q)
{
    double d= sqrt((p-a)*(p-a)+(q-b)*(q-b));
    return d;
}
void display(float a,float b,float p,float q,float d)
{
   printf("The distance between %f,%f and %f,%f is %f\n",a,b,p,q,d);
}
int main()
{
    float a,b,p,q,d;
    a=input("abscissa 1");
    b=input("ordinate 1");
    p=input("abscissa 2");
    q=input("ordinate 2");
    d=getDistance(a,b,p,q);
    display(a,b,p,q,d);
}
