#include <stdio.h>
int main ()
{
    int n,i;
    unsigned long long a,b,c;
    while((scanf("%d",&n))==1)
    {
        if(n==0)
        break;
        a=1;b=2;
        if(n==1)
        b=1;
        else
        for(i=2;i<n;i++)
        {
            c=b;
            b+=a;
            a=c;
        }
        printf("%llu\n",b);
    }
    return 0;
}
