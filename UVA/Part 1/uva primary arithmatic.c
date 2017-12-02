#include <stdio.h>
#include <string.h>
int main ()
{
    int a,b,i,m,arr2[1000],arr3[1000],d;
    char arr[1000],arr1[1000];
    while(gets(arr))
    {m=0;
        a=strlen(arr);
        gets(arr1);
        b=strlen(arr1);
        if(a==1&&b==1&&arr[0]=='0'&&arr1[0]=='0')
        break;
        for(i=(a-1);i>-1;i--)
        {
            arr2[m]=arr[i]-'0';
            m++;
        }
        m=0;
        for(i=(b-1);i>-1;i--)
        {
            arr3[m]=arr1[i]-'0';
            m++;
        }
        if(a>b)
        {
            for(i=b;i<a;i++)
            {
                arr3[i]=0;
            }
            d=a;
        }
        else if(a<b)
        {
            for(i=a;i<b;i++)
            {
                arr2[i]=0;
            }
            d=b;
        }
        else
        {
            d=a;
        }
        int e,f=0,g=0;
        for(i=0;i<d;i++)
        {
            e=arr2[i]+arr3[i]+f;
            f=e/10;
            if(f==1)
            {
                g++;
            }
        }
        if(g==0)
        {
            printf("No carry operation.\n");
        }
        else if(g==1)
        {
            printf("1 carry operation.\n");
        }
        else
        {
            printf("%d carry operations.\n",g);
        }

    }
    return 0;
}
