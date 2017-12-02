#include <stdio.h>
#include <string.h>
int main ()
{
    int n,a,b,i,m,j;
    char arr[1000],arr1[1000],c;
    scanf("%d%c",&n,&c);
    for(i=1;i<=n;i++)
    {
        m=0;
        gets(arr);
        a=strlen(arr);
        gets(arr1);
        b=strlen(arr1);
        if(a!=b)
        printf("Case %d: Output Format Error\n",i);
        else
        {
            for(j=0;j<a;j++)
            if(arr[j]==arr1[j])
                m++;
            if(m==a)
            printf("Case %d: Yes\n",i);
            else
            printf("Case %d: Wrong Answer\n",i);
        }
    }
    return 0;
}
