#include <stdio.h>
int main ()
{
    long long int n;
    unsigned long long a,b,i,temp;
    while((scanf("%lld",&n))==1)
    {
        a=1;
        b=2;
        if(n==-1)
            break;
        else if(n==0)
            printf("0 1\n");
        else
        {

            for(i=0; i<n-1; i++)
            {
                temp=b;
                b+=a+1;
                a=temp;
            }
            printf("%llu %llu\n",a,b);
        }
    }
    return 0;
}
