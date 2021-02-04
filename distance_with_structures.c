//WAP to find the distance between two points using structures and 4 functions.
#include <stdio.h>
#include <math.h>
struct point
{
    float a;
    float b;
};
typedef struct point Point;
Point input()
{
    Point p;
    printf("Enter abcissa:");
    scanf("%f",&p.a);
    printf("Enter ordinate:");
    scanf("%f",&p.b);
    return p;
}
float compute(Point p1,Point p2)
{
    float distance;
    distance=sqrt(pow((p1.a-p2.a),2)+pow((p1.b-p2.b),2));
    return distance;
}
void output(Point p1, Point p2, float dist)
{
    printf("The distance between %f,%f and %f,%f is %f",p1.a,p1.b,p2.a,p2.b,dist);
}
int main(void)
{
    float dist;
    Point p1,p2;
    p1=input();
    p2=input();
    dist=compute(p1,p2);
    output(p1,p2,dist);
    return 0;
}
