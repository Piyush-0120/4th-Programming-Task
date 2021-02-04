//WAP to find the sum of n fractions.
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
float compute(Frac f)
{
    float res;
    res=(f.a / f.b); 
    return res;
}
void output(float res)
{
    printf("The answer is: %f",res);
}
int main(void)
{
    int n;
    float sum=0.0;
    Frac f;
    printf("Enter the value of n:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        f=input();
        sum+=compute(f);
    }
    output(sum);
    return 0;
}
