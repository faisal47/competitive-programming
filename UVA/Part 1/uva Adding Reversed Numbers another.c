#include <stdio.h>
#include <string.h>
int arr3[405],arr4[405];
int main ()
{
    int t,j,i,len,c,d,e,flag,f;
    char arr[405],z;
    scanf("%d%c",&t,&z);
    for(j=0;j<t;j++)
    {
        gets(arr);
        len=strlen(arr);
        c=0;d=0;e=0;flag=0;
        for(i=0;i<len;i++)
        {
            if(arr[i]==' ')
            flag=1;
            else if(flag==0)
            arr3[c++]=arr[i]-'0';
            else
            arr4[d++]=arr[i]-'0';
        }
        e=0;f=0;flag=0;
        if(c>=d)
        {
            for(i=0;i<c;i++)
            {
                f+=arr3[i]+arr4[i];
                if(f>9)
                arr4[i]=f%10;
                else
                arr4[i]=f;
                f/=10;
            }
            if(f>0)
            arr4[c++]=f;
            for(i=0;i<c;i++)
            {
                if(arr4[i]>0)
                flag=1;
                if(flag==1)
                printf("%d",arr4[i]);
            }
        }
        else
        {
            for(i=0;i<d;i++)
            {
                f+=arr3[i]+arr4[i];
                if(f>9)
                arr4[i]=f%10;
                else
                arr4[i]=f;
                f/=10;
            }
            if(f>0)
            arr4[d++]=f;
            for(i=0;i<d;i++)
            {
                if(arr4[i]>0)
                flag=1;
                if(flag==1)
                printf("%d",arr4[i]);
            }
        }
        for(i=0;i<405;i++)
        {
            arr3[i]=0;
            arr4[i]=0;
        }
        printf("\n");
    }
    return 0;
}
