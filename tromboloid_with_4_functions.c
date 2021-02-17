//WAP to find the volume of a tromboloid using 4 functions.
#include <stdio.h>
float input(char *s)
{
    float a;    
    printf("Enter %s:",s);
    scanf("%f",&a);
    return a;
}

float getVolume(float h,float b,float d)
{
    float v= (1/3.0)*((h*d*b)+(d/b));
    return v;
}
void display(float h,float b,float d,float v)
{
    printf("Volume of tromboloid of length,breadth and depth respectively %f,%f and %f is: %f\n",h,b,d,v);
}
int main()
{
    float h,b,d,v;
    h=input("h");
    b=input("b");
    d=input("d");
    v=getVolume(h,b,d);
    display(h,b,d,v);
    return 0;
}

