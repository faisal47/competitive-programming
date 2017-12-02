#include <stdio.h>
#include <math.h>
int main ()
{
    int n,arr[506],i,y,z,d,temp,j,m,a;
    scanf("%d",&z);
    for(y=0; y<z; y++)
    {
        scanf("%d",&n);
        for(i=0; i<n; i++)
            scanf("%d",&arr[i]);
        for(i=0; i<n-1; i++)
            for(j=i+1; j<n; j++)
            {
                if(arr[i]>arr[j])
                {
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            }
        if((n%2)==0)
        {
            a=n/2;
            m=arr[a-1]+arr[a];
            m/=2;

        }
        else
        {
            a=n/2;
            m=arr[a];
        }
        d=0;
        for(i=0; i<n; i++)
            d+=abs(arr[i]-m);
        printf("%d\n",d);

    }
    return 0;
}
