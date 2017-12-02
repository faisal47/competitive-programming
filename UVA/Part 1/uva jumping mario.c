#include <stdio.h>
int main ()
{
    int arr[1000],n,a,b,c,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {b=0;c=0;
        scanf("%d",&a);
        for(j=0;j<a;j++)
        {
            scanf("%d",&arr[j]);
        }
        for(j=1;j<a;j++)
        {
            if(arr[j-1]<arr[j])
            {b=b+1;}
            else if(arr[j-1]>arr[j])
            {c=c+1;}
        }
        printf("Case %d: %d %d\n",i,b,c);
    }
    return 0;
}
