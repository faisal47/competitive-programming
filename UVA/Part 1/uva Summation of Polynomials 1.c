#include <stdio.h>
int main ()
{long long int n,a;
while((scanf("%lld",&n))==1)
    printf("%lld\n",((n*(n+1))*(n*(n+1)))/4);
    return 0;}
