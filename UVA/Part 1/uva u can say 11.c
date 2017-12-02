#include <stdio.h>
int main ()
{
    long long int n,a,b,c;
    while((scanf("%lld",&n))==1)
    {
        if(n==0)
        break;
        if(n%11==0)
        printf("%lld is a multiple of 11.\n",n);
        else
        printf("%lld is not a multiple of 11.\n",n);
    }
    return 0;
}
