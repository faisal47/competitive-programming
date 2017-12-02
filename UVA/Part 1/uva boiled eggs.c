#include <stdio.h>
int main ()
{
    int arr[1000],sum,d,n,a,b,c,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        sum=0;
        d=0;
        scanf("%d%d%d",&a,&b,&c);
        for(j=0;j<a;j++)
        {
            scanf("%d",&arr[j]);
        }
        for(j=0;j<a;j++)
        {
            sum+=arr[j];
            if(sum>c||j>=b)
            break;
            d+=1;
        }
        printf("Case %d: %d\n",i,d);
    }
    return 0;
}
