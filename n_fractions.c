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
void input(int n,Frac f[n])
{
    for(int i=0;i<n;i++)
    {
        printf("Enter numerator %d:",i+1);
        scanf("%d",&f[i].a);
        printf("Enter denominator %d:",i+1);
        scanf("%d",&f[i].b);    
    }
}
Frac compute_one_fraction(Frac res,Frac f)
{
    Frac sum;
    int l = lcm(res.b,f.b);
    sum.a = res.a*(l/res.b)  + f.a*(l/f.b);
    sum.b = l;
    return sum;
}
void compute_n_fraction(int n,Frac f[],Frac *res)
{
    for(int i=0;i<n;i++)
    {
        if(i==0)
            *res=f[i];
        else
            *res=compute_one_fraction(*res,f[i]);
    }
    
    int g=gcd(res->a,res->b);
    res->a/=g;
    res->b/=g;
}

void output(int n,Frac f[n],Frac res)
{
   for(int i=0;i<n-1;i++)
   {
       printf("%d/%d + ",f[i].a,f[i].b);
   }
   printf("%d/%d ",f[n-1].a,f[n-1].b);
   printf("is %d/%d ",res.a,res.b);
}
int main(void)
{
    int n;
    printf("Enter the value of n:");
    scanf("%d",&n);
    Frac res,f[n];
    input(n,f);
    compute_n_fraction(n,f,&res);
    output(n,f,res);
    return 0;
}
