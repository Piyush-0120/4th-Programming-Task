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
int GCD(int n, int d) {
	int g;
	for (int i = 1; i <= n && i <= d; i++) {
		if (n % i == 0 && d % i == 0)
			g = i;
	}
	return g;
}
int lcm(int a,int b)
{
    return ((a*b)/GCD(a,b)); 
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
Frac compute(Frac f1,Frac f2)
{
    Frac sum;
    int l = lcm(f1.b,f2.b);
    sum.a = f1.a*(l/f1.b)  + f2.a*(l/f2.b);
    sum.b = l;
    return sum;
}
Frac simplified(Frac res)
{
    int g=GCD(res.a,res.b);
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
    Frac f1,f2,res;
    f1=input();
    f2=input();
    res=compute(f1,f2);
    res = simplified(res);
    output(res);
    return 0;
}


