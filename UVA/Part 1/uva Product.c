#include <stdio.h>
#include <string.h>
int arr1[300],arr2[300],arr3[300][1000],arr[1000];
int main ()
{
    char arr10[300],arr20[300];
    int i,d,c1,max,len1,len2,j,c,e,flag;
    while(gets(arr10))
    {
        gets(arr20);
        len1=strlen(arr10);
        len2=strlen(arr20);
        flag=0;
        for(i=0; i<len1; i++)
            arr1[i]=arr10[i]-'0';
        for(i=0; i<len2; i++)
            arr2[i]=arr20[i]-'0';
        if(len1>=len2)
        {
            d=c=c1=max=e=0;
            for(i=len2-1; i>=0; i--)
            {
                for(j=len1-1; j>=0; j--)
                {
                    d+=arr2[i]*arr1[j];
                    arr3[e][c++]=d%10;
                    d/=10;
                }
                if(d>0)
                    arr3[e][c++]=d;
                if(max<c)
                    max=c;
                    d=0;
                ++c1;
                c=c1;
                 e++;
            }
            e=0;
            for(i=0; i<max; i++)
            {
                for(j=0; j<len2; j++)
                 e+=arr3[j][i];
                 arr[i]=e%10;
                 e/=10;
            }
            if(e>0)
            {
                max+=1;
                arr[i]=e;
            }
            flag=0;
            for(i=max-1;i>=0;i--)
            {
                if(arr[i]>0)
                flag=1;
                if(flag==1)
                printf("%d",arr[i]);
            }
            if(flag==0)
            printf("0");
            printf("\n");
        }
        else
        {
            d=c=c1=max=e=0;
            for(i=len1-1; i>=0; i--)
            {
                for(j=len2-1; j>=0; j--)
                {
                    d+=arr2[j]*arr1[i];
                    arr3[e][c++]=d%10;
                    d/=10;
                }
                if(d>0)
                    arr3[e][c++]=d;
                if(max<c)
                    max=c;
                ++c1;
                c=c1;
                 e++;
                 d=0;
            }
            e=0;
            for(i=0; i<max; i++)
            {
                for(j=0; j<len1; j++)
                 e+=arr3[j][i];
                 arr[i]=e%10;
                 e/=10;
            }
            if(e>0)
            {
                max+=1;
                arr[i]=e;
            }
            flag=0;
            for(i=max-1;i>=0;i--)
            {
                if(arr[i]>0)
                flag=1;
                if(flag==1)
                printf("%d",arr[i]);
            }
            if(flag==0)
            printf("0");
            printf("\n");
        }
        for(i=0;i<1000;i++)
        arr[i]=0;
        for(i=0;i<300;i++)
        for(j=0;j<1000;j++)
        arr3[i][j]=0;
        for(i=0;i<300;i++)
        arr1[i]=arr2[i]=0;
    }
    return 0;
}
