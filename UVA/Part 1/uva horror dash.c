#include <stdio.h>
int main ()
{
    int t,n,i,j;
    long long int arr[150],max;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
        scanf("%lld",&arr[j]);
        max=arr[0];
        for(j=1;j<n;j++)
        {
            if(arr[j]>max)
            max=arr[j];
        }
        printf("Case %d: %lld\n",i,max);
    }
    return 0;
}
