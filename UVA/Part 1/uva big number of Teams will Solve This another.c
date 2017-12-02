#include <stdio.h>
#include <string.h>
int main ()
{
    char arr[1000],arr1[1000],arr2[1000],z;
    int n,a,b,i,j,m,o;
    scanf("%d%c",&n,&z);
    for(i=1; i<=n; i++)
    {o=0;
        m=0;
        gets(arr);
        a=strlen(arr);
        gets(arr1);
        b=strlen(arr1);
        if(a==b)
        {
            for(j=0; j<a; j++)
            {
                if(arr[j]==arr1[j])
                {
                    m++;
                }
            }
            if(m==a)
            {
                printf("Case %d: Yes\n",i);
            }
            else
            {
                printf("Case %d: Wrong Answer\n",i);
            }
        }
        else
        {
            for(j=0; j<a; j++)
            {
                if(arr[j]!=' ')
                {
                    arr2[o]=arr[j];
                    o++;
                }
            }
            for(j=0;j<b;j++)
            {
                if(arr1[j]==arr2[j])
                {
                    m++;
                }
            }
            if(b==m)
            {
                printf("Case %d: Output Format Error\n",i);
            }
            else
            {
                printf("Case %d: Wrong Answer\n",i);
            }

        }
    }
    return 0;
}
