#include <stdio.h>
#include <string.h>
int main ()
{
    int n,l,l1,i,j,k;
    char arr[1000],z;
    while((scanf("%d",&n))==1)
    {
        if(n==0)
        break;
        scanf("%c",&z);
        gets(arr);
        l=strlen(arr);
        l1=l/n;
        for(i=1;i<=n;i++)
        {
            k=(i*l1)-1;
            for(j=0;j<l1;j++)
            {
                printf("%c",arr[k]);
                k--;
            }
        }
        printf("\n");
    }
    return 0;
}
