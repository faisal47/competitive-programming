#include <stdio.h>
int main ()
{
    int n;
    long long int a,b,sum,i;
    while((scanf("%d",&n))==1)
    {
        if(n==0)
            break;
        a=1;
        b=2;
        sum=0;
        if(n==a)
            sum=a;
        else if(n==b)
            sum=b;
        else
        {
            for(i=0; i<n-2; i++)
            {
                sum=a+b;
                a=b;
                b=sum;
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
