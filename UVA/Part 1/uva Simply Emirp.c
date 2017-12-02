#include <stdio.h>
#include <string.h>
int arr[10000020];
int main ()
{
    char arr1[100];
    long long int a,b,c,i,j,l,len;
    arr[2]=1;
    for(i=3; i<10000020; i+=2)
    {
        if(arr[i]==0)
        {
            arr[i]=1;
            for(j=i+i; j<10000020; j+=i)
                arr[j]=3;
        }
    }
    while(gets(arr1))
    {
        len=strlen(arr1);
        a=b=0;
        for(i=0; i<len; i++)
            a=((a*10)+(arr1[i]-'0'));
        for(i=len-1; i>=0; i--)
            b=((b*10)+(arr1[i]-'0'));
        if(arr[a]!=1)
            printf("%lld is not prime.\n",a);
        else
        {
            if(a==b&&arr[a]==1)
            printf("%lld is prime.\n",a);
            else if(arr[a]==1&&arr[b]==1)
            printf("%lld is emirp.\n",a);
            else
            printf("%lld is prime.\n",a);
        }
    }
    return 0;
}
