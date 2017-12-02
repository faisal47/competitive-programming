#include <stdio.h>
int main ()
{
    int n,i,arr1[15],arr2[15],m=1;
    while((scanf("%d",&n))==1)
    {
        if(n<0)
        break;
        for(i=0;i<12;i++)
        scanf("%d",&arr1[i]);
        for(i=0;i<12;i++)
        scanf("%d",&arr2[i]);
        printf("Case %d:\n",m);
        for(i=0;i<12;i++)
        {
            if(n>=arr2[i])
            {
                printf("No problem! :D\n");
                n-=arr2[i];
            }
            else
            {
                printf("No problem. :(\n");
            }
            n+=arr1[i];
        }
        m++;
    }
    return 0;
}
