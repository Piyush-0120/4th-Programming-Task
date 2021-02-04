//WAP to find the sum of two fractions.
#include <stdio.h>
#include <stdio.h>
struct frac
{
    float a;
    float b;
};
typedef struct frac Frac;
Frac input()
{
    Frac f;
    printf("Enter numerator:");
    scanf("%f",&f.a);
    printf("Enter denominator:");
    scanf("%f",&f.b);
    return f;
}
float compute(Frac f1,Frac f2)
{
    float sum;
    sum=(f1.a / f1.b)+(f2.a/f2.b); 
    return sum;
}
void output(Frac f1, Frac f2, float res)
{
    printf("The answer is: %f",res);
}
int main(void)
{
    float res;
    Frac f1,f2;
    f1=input();
    f2=input();
    res=compute(f1,f2);
    output(f1,f2,res);
    return 0;
}
