#include <stdio.h>
int main ()
{
    int arr[150],n,m,i,j,c=1;
    while((scanf("%d",&n))==1)
    {
        if(n==0)
        break;
        m=0;j=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            j+=arr[i];
        }
        j/=n;
        for(i=0;i<n;i++)
        {
            if(j>arr[i])
            m+=(j-arr[i]);
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",c,m);
        c++;
    }
    return 0;
}
