#include <stdio.h>
#include <string.h>
int main ()
{
    char arr2[505],a;
    int n,i,flag,t,k,b,flag2,j;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        flag2=0;
        scanf("%d%c",&t,&a);
        for(j=0; j<t; j++)
        {
            gets(arr2);
            b=strlen(arr2);
            if(flag2==0)
            {
                if(i>1)
            printf("\n");
            printf("Case %d:\n",i);

            }
            flag=0;
            for(k=0; k<b; k++)
            {
                flag2=1;
                if(flag==0&&arr2[k]==' ')
                {
                    printf("%c",arr2[k]);
                    flag=1;
                }
                else if(arr2[k]!=' ')
                {
                    printf("%c",arr2[k]);
                    flag=0;
                }
            }

            printf("\n");
        }
    }
    return 0;
}
