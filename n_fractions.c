#include <stdio.h>
struct frac
{
    int a;
    int b;
};
typedef struct frac Frac;
int gcd(int,int);
int lcm(int,int);
Frac input();
Frac compute(Frac,Frac);
Frac simplified(Frac);
void output(Frac);

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
Frac simplified(Frac res)
{
    int g=gcd(res.a,res.b);
    res.a/=g;
    res.b/=g;
    return res;    
}
void output(Frac res)
{
   printf("The simplified fraction is: %d/%d",res.a,res.b);  
}
int main(void)
{
    int n;
    Frac res,f;
    printf("Enter the value of n:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        f=input();
        if(i==0)
            res=f;
        else
            res=compute(res,f);
    }
    res = simplified(res);
    output(res);
    return 0;
}
