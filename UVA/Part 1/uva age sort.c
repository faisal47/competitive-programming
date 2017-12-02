#include <stdio.h>
long long int arr[2000000];
int main ()
{
    long long int n;
    long long int i,j,temp;
    while((scanf("%lld",&n))==1)
    {
        if(n==0)
        break;
        for(i=0;i<n;i++)
        scanf("%lld",&arr[i]);
        for(i=0;i<n-1;i++)
        {
            for(j=(i+1);j<n;j++)
            {
                if(arr[i]>arr[j])
                {
                    temp=arr[j];
                    arr[j]=arr[i];
                    arr[i]=temp;
                }
            }
        }
        printf("%lld",arr[0]);
        for(i=1;i<n;i++)
        printf(" %lld",arr[i]);
        printf("\n");
    }
    return 0;
}
