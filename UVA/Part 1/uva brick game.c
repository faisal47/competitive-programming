#include <stdio.h>
int main ()
{
    int j,n,i,arr[100],t;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&t);
        for(j=1;j<=t;j++)
        scanf("%d",&arr[j]);
        t=t/2;
        t+=1;
        printf("Case %d: %d\n",i,arr[t]);
    }
    return 0;
}
