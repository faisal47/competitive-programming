#include <stdio.h>
int main ()
{
    int n,a,b,m,i;
    while((scanf("%d",&n))==1)
    {
        if(n==0)
        break;
        else if(n%2==1)
        {
            if(n==1)
            printf("1\n");
            else
           {a=(n+1)/2;
           printf("%d\n",(a*a)-1);}
        }
        else if(n%2==0)
        {
            a=2;
            m=n-1;
            b=(n/2)-1;
            for(i=0;i<b;i++)
            {
                a+=m;
                m--;
            }
            printf("%d\n",a);
        }
    }
    return 0;
}
