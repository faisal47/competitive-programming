#include <stdio.h>
#include <string.h>
int main ()
{
    int t,i,len,j,a,b,k,flag;
    char z,arr[300];
    scanf("%d%c",&t,&z);
    for(i=1;i<=t;i++)
    {
        a=0;
        gets(arr);
        printf("Case %d: ",i);
        len=strlen(arr);
        z=arr[0];
        for(j=1;j<len;j++)
        {
            if(arr[j]>='A'&&arr[j]<='Z')
            flag=1;
            if(flag==1)
            {
                for(k=0;k<a;k++)
                printf("%c",z);
                a=0;z=arr[j];
                flag=0;
            }
            if(arr[j]>='0'&&arr[j]<='9')
            {
                a=(a*10)+(arr[j]-'0');
            }
        }
        for(j=0;j<a;j++)
        printf("%c",z);
        printf("\n");
    }
    return 0;
}
