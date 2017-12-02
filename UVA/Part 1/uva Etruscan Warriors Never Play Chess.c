#include <stdio.h>
#include <math.h>
int main ()
{
    unsigned long long t,n,i,m,sum,p;
    scanf("%llu",&t);
    for(i=0; i<t; i++)
    {
        sum=0,m=1;
        scanf("%llu",&n);
        m=sqrt(n);
        while(1)
        {
            sum+=m;
            p=n-sum;
            m++;
            if(m>p)break;
        }
        printf("%llu\n",m-1);
    }
    return 0;
}
