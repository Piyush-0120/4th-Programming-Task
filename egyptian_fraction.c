#include<stdio.h>
struct unit_fraction
{
	int a;
	int b;
};
typedef struct unit_fraction Frac;

struct n_fraction
{
    int n;
    Frac f[100];
    Frac res;
};
typedef struct n_fraction N_frac;

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

Frac input_one_fraction()
{
	Frac f;
    f.a=1;
	scanf("%d",&f.b);
	return f;
}

N_frac input_n_fraction(N_frac F)
{
	scanf("%d",&F.n);
	for(int i=0;i<F.n;i++)
	{
		F.f[i]=input_one_fraction();
	}
	return F;
}
int input_tCases(N_frac F[])
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        F[i]=input_n_fraction(F[i]);
    }
    return n;
}
Frac compute_one_fraction(Frac res,Frac f)
{
    Frac sum;
    int l = lcm(res.b,f.b);
    sum.a = res.a*(l/res.b)  + f.a*(l/f.b);
    sum.b = l;
    return sum;
}
N_frac compute_n_fraction(N_frac F)
{
    for(int i=0;i<F.n;i++)
    {
        if(i==0)
            F.res=F.f[i];
        else
            F.res=compute_one_fraction(F.res,F.f[i]);
    }
   
    int g=gcd(F.res.a,F.res.b);
    F.res.a/=g;
    F.res.b/=g;
    return F;
}
void compute_tCases(int n,N_frac F[])
{
    for(int i=0;i<n;i++)
    {
        F[i]=compute_n_fraction(F[i]);
    }
}
void output(int t,N_frac F[])
{
   for(int j=0;j<t;j++)
   {
       int limit=F[j].n;
       for(int i=0;i<limit-1;i++)
       {
           printf("%d/%d + ",F[j].f[i].a,F[j].f[i].b);
       }
       printf("%d/%d ",F[j].f[limit-1].a,F[j].f[limit-1].b);
       printf("= %d/%d \n",F[j].res.a,F[j].res.b);
   }
}

int main()
{
    int t;
    N_frac F[100];
    t=input_tCases(F);
    compute_tCases(t,F);
    output(t,F);
    return 0;
}

