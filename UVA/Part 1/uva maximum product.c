#include <stdio.h>
int main ()
{
    int n,arr[100],i,j,m=1;
    long long int max,a;
    while((scanf("%d",&n))==1)
    {
        max=0;
        for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
        for(i=0;i<n-1;i++)
        {
            a=arr[i];
            if(a>max)
            max=a;
            for(j=i+1;j<n;j++)
            {
                a*=arr[j];
                if(max<a)
                max=a;
            }
        }
        if(max<arr[n-1])
        max=arr[n-1];
        printf("Case #%d: The maximum product is %lld.\n\n",m,max);
        m++;
    }
    return 0;
}
