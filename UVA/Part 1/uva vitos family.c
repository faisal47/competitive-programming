#include <stdio.h>
int main ()
{
    long long int i,t,n,arr[550],a,b,j;
    scanf("%d",&t);
    for(j=0;j<t;j++)
    {
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        scanf("%lld",&arr[i]);
        a=arr[0];b=arr[0];
        for(i=0;i<n;i++)
        {
            if(a<arr[i])
            a=arr[i];
            if(b>arr[i])
            b=arr[i];
        }
        printf("%lld\n",a-b);
    }
    return 0;
}
