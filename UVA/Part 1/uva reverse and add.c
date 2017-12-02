#include <stdio.h>
#include <string.h>
int arr1[30],arr2[30];
int main ()
{
    int b,a,i,c,t,j,d;
    char arr[20],z;
    scanf("%d%c",&t,&z);
    for(j=0; j<t; j++)
    {
        gets(arr);
        c=0;
        a=strlen(arr);
        for(i=0; i<a; i++)
            arr1[i]=(arr[i]-'0');
        while(1)
        {
            b=0;
            for(i=(a-1); i>=0; i--)
            {arr2[i]=arr1[b];b++;}
            b=0;
            for(i=0; i<a; i++)
            {
                if(arr1[i]!=arr2[i])
                    break;
                b++;
            }
            if(b==a)
            {
                printf("%d ",c);
                for(i=0; i<a; i++)
                    printf("%d",arr1[i]);
                printf("\n");
                break;
            }
            else
            {
                b=0;
                for(i=0; i<a; i++)
                {
                    arr1[i]+=b+arr2[i];
                    b=0;
                    if(arr1[i]>=10)
                    {b=(arr1[i]/10);arr1[i]%=10;}
                }
                if(b>0)
                {arr1[a]=b;a+=1;}
            }
            c++;
        }
    }
    return 0;
}
