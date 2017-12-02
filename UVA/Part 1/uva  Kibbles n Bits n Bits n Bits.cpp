#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main ()
{
    long long int a,b,r,test,i;
    char sign;
    int arr[15];
    cin>>test;
    while(test--)
    {
        cin>>hex>>a>>sign>>hex>>b;
        if(sign=='+')
        r=a+b;
        else
        r=a-b;
        a=(long long int)a;
        b=(long long int)b;
        memset(arr,0,sizeof(arr));
        i=0;
        while(1)
        {
            arr[i++]=a%2;
            if(a==0)
            break;
            a/=2;
        }
        for(i=12;i>=0;i--)
        printf("%d",arr[i]);
        cout<<" ";
        memset(arr,0,sizeof(arr));
        i=0;
        while(1)
        {
            arr[i++]=b%2;
            if(b==0)
            break;
            b/=2;
        }
        cout<<sign<<" ";
        for(i=12;i>=0;i--)
        printf("%d",arr[i]);
        cout<<" ";
        printf("= %d\n",r);
    }
    return 0;
}
