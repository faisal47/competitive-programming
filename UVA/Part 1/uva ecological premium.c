#include <stdio.h>
int main ()
{
    int t,n,i,j;
    unsigned long long arr[22][5],b;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        b=0;
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {scanf("%llu %llu %llu",&arr[j][0],&arr[j][1],&arr[j][2]);b+=(arr[j][0]*arr[j][2]);}
        printf("%llu\n",b);

    }
    return 0;
}
