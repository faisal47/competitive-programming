#include <stdio.h>
int arr1[1000090][3],arr[1000090];
int main ()
{
    long long int n,i,j,m,c;
    int d;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        c=d=0;
        scanf("%lld",&m);
        for(j=0;j<m;j++)
        scanf("%d %d",&arr1[j][0],&arr1[j][1]);
        for(j=m-1;j>=0;j--)
        {
            d+=arr1[j][0]+arr1[j][1];
            arr[c++]=d%10;
            d/=10;
        }
        for(j=m-1;j>=0;j--)
        printf("%d",arr[j]);
        printf("\n");
        if(i<n-1)
        printf("\n");
    }
    return 0;
}
