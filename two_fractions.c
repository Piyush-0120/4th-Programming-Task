//WAP to find the sum of two fractions.
#include <stdio.h>
struct frac
{
    int a;
    int b;
};
typedef struct frac Frac;
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int lcm(int a,int b)
{
    return ((a*b)/gcd(a,b)); 
}
Frac input()
{
    Frac f;
    printf("Enter numerator:");
    scanf("%d",&f.a);
    printf("Enter denominator:");
    scanf("%d",&f.b);
    return f;
}
Frac compute(Frac res,Frac f)
{
    Frac sum;
    int l = lcm(res.b,f.b);
    sum.a = res.a*(l/res.b)  + f.a*(l/f.b);
    sum.b = l;
    return sum;
}
void output(Frac res)
{
    int g=gcd(res.a,res.b);
    res.a/=g;
    res.b/=g;
    printf("The simplified fraction is: %d/%d",res.a,res.b);
}
int main(void)
{   
    Frac f1,f2,res;
    f1=input();
    f2=input();
    res=compute(f1,f2);
    output(res);
    return 0;
}

