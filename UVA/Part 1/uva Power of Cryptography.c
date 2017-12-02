#include <stdio.h>
#include <math.h>
int main ()
{
    double p;
    unsigned long long a,b;
    while((scanf("%lf",&p))==1)
    {
        scanf("%llu",&a);
        b=pow(a,1/p);
        printf("%llu\n",b);
    }
    return 0;
}
