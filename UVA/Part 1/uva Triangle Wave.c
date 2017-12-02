#include <stdio.h>
int main ()
{
    int t,n,a,i,j,k,l;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d",&n,&a);
        for(j=1;j<=a;j++)
        {
            for(k=1;k<=n;k++)
            {
                for(l=0;l<k;l++)
                printf("%d",k);
                printf("\n");
            }
            for(k=n-1;k>0;k--)
            {
               for(l=0;l<k;l++)
                printf("%d",k);
                printf("\n");
            }
            if(i==t&&j==a)
            ;
            else
            printf("\n");
        }
    }
    return 0;
}
