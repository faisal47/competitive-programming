#include <stdio.h>
int main ()
{
    int i,t;
    long long int n;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%lld",&n);
        n=((n*133245)+15634926)/423;
        n=n%100;
        n=n/10;
        if(n>=0)
        printf("%d\n",n);
        else
        printf("%d\n",((-1)*n));
    }
    return 0;
}
