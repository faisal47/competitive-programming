#include <stdio.h>
int main ()
{
    long long int m,n,flag,a;
    while((scanf("%lld %lld",&m,&n))==2)
    {
        if((m<n)||m==0||n==0||(m==1&&n==1)||n==1)
        {
            printf("Boring!\n");
            continue;
        }
        flag=0;a=m;
        while(1)
        {
            if((m%n)!=0)
            {
                flag=1;
                break;
            }
            m/=n;
            if(m==1)
            break;
        }
        if(flag==1)
        printf("Boring!\n");
        else
        {
            m=a;
            printf("%lld",m);
            while(1)
            {
                m/=n;
                printf(" %lld",m);
                if(m==1)
                break;
            }
            printf("\n");
        }
    }
    return 0;
}
