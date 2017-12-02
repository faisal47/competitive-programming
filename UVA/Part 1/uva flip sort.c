#include <stdio.h>
int main ()
{
    long long int n,i,j,arr[1050],temp,a;
    while((scanf("%lld",&n))==1)
    {
        a=0;
        for(i=0;i<n;i++)
        scanf("%lld",&arr[i]);
        for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                a++;
            }
        }
        printf("Minimum exchange operations : %lld\n",a);
    }
    return 0;
}
