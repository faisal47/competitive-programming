#include <stdio.h>
int main ()
{
    long long int n,a,i;
    while((scanf("%lld",&n))==1)
    {
        a=0;
        for(i=1;i<=n;i++)
        a+=(i*i*i);
        printf("%lld\n",a);
    }
    return 0;
}
