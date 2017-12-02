#include <stdio.h>
#include <string.h>
int main ()
{
    char arr1[1001][20],a[1005];
    unsigned long m,n,arr2[1001],i,j,k,l,len;
    unsigned long long b;
    while((scanf("%lu %lu",&m,&n))==2)
    {
        for(i=0;i<m;i++)
        scanf("%s %lu",arr1[i],&arr2[i]);
        for(i=0;i<n;i++)
        {
            b=0;
            while(1)
            {
                scanf("%s",a);
                j=strlen(a);
                if(j==1&&a[0]=='.')
                break;
                for(j=0;j<m;j++)
                if(strcmp(a,arr1[j])==0)
                b+=arr2[j];
            }
            printf("%llu\n",b);
        }
    }
    return 0;
}
