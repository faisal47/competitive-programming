#include <stdio.h>
int main ()
{
    long int n,r,a,i,j,k=1,b;
    while((scanf("%ld%ld",&n,&r))==2)
    {
        if(n==0&&r==0)
        break;
        else if(n<r||n==r)
        {
            printf("Case %ld: 0\n",k);
        }
        else
        {
            a=n-r;
            b=(a/r);
            if((a%r)!=0)
            {
                b+=1;
            }
            if(b>26)
            {
                printf("Case %ld: impossible\n",k);
            }
            else
            {
                printf("Case %ld: %ld\n",k,b);
            }
        }

        k++;
    }
    return 0;
}
