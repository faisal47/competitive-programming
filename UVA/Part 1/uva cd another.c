#include <stdio.h>
int arr[1000000050];
int main ()
{
    unsigned long long m,n,i,j,max,count;
    while((scanf("%llu %llu",&m,&n))==2)
    {
        if(m==0&&n==0)
            break;
        max=0;
        count=0;
        for(i=0; i<m; i++)
        {
            scanf("%llu",&j);
            arr[j]=1;
            if(max<j)
            max=j;
        }
        for(i=0; i<n; i++)
        {
            scanf("%llu",&j);
            if(arr[j]==1)
                count++;
        }
        printf("%llu\n",count);
        for(i=1; i<=max; i++)
            arr[i]=0;
    }
    return 0;
}
