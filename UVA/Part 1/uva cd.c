#include <stdio.h>
unsigned long long arr1[1000000],arr2[1000000];
int main ()
{
    unsigned long long m,n,i,j,o;
    while((scanf("%llu %llu",&m,&n))==2)
    {
        if(m==0&&n==0)
        break;
        o=0;
        for(i=0;i<m;i++)
        scanf("%llu",&arr1[i]);
        for(i=0;i<n;i++)
        scanf("%llu",&arr2[i]);
        if(m>=n)
        {
            for(i=0;i<m;i++)
            for(j=0;j<n;j++)
            {
                if(arr1[i]==arr2[j])
                o++;
            }
        }
        else if(m<n)
        {
            for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                if(arr1[i]==arr2[j])
                o++;
            }
        }
        printf("%llu\n",o);

    }
    return 0;
}
