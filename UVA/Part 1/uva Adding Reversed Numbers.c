#include <stdio.h>
#include <string.h>
int arr1[200],arr2[200],arr3[200],arr4[200],arr5[200];
int main ()
{
    char arr[205],z;
    int len,i,flag,c,d,t,e,j;
    scanf("%d%c",&t,&z);
    for(j=0;j<t;j++)
    {
        gets(arr);
        len=strlen(arr);
        flag=0;c=0;d=0;
        for(i=len-1;i>=0;i--)
        {
            if(arr[i]==' ')
            flag=1;
            else if(flag==1)
            arr4[d++]=arr[i]-'0';
            else
            arr5[c++]=arr[i]-'0';
        }
        e=0;
        for(i=c-1;i>=0;i--)
        arr1[e++]=arr5[i];
        e=0;
        for(i=d-1;i>=0;i--)
        arr2[e++]=arr4[i];
        flag=0;e=0;
        if(c>=d)
        {
            for(i=0;i<c;i++)
            {
                e+=arr1[i]+arr2[i];
                arr[i]=e%10;
                e/=10;
            }
            for(i=0;i<c;i++)
            {
                if(arr3[i]>0)
                flag=1;
                if(flag==1)
                printf("%d",arr3[i]);
            }
        }
        else
        {
            for(i=0;i<d;i++)
            arr3[i]=arr1[i]+arr2[i];
            for(i=0;i<d;i++)
            {
                if(arr3[i]>0)
                flag=1;
                if(flag==1)
                printf("%d",arr3[i]);
            }
        }
        printf("\n");
    }
    return ;
}
