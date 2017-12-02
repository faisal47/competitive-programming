#include <stdio.h>
unsigned long long fibonacci(unsigned long long n)
{
    if(n==0||n==1)
    return 1;
    else
    return (fibonacci(n-1)+fibonacci(n-2));
}
int main ()
{
   unsigned long long b,n;
    while((scanf("%llu",&n))==1)
    {
        if(n==0)
        break;
        b=fibonacci(n);
        printf("%llu\n",b);
    }
    return 0;
}
