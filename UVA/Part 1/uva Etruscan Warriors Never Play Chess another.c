#include <stdio.h>
#include <math.h>
int main ()
{
    unsigned long long t,n,i,m,sum,p;
    scanf("%llu",&t);
    for(i=0; i<t; i++)
    {
        scanf("%llu",&n);
        sum=sqrt(1+(4*2*n));
        sum-=1;
        printf("%llu\n",sum/2);
    }
    return 0;
}
