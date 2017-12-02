#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int main ()
{
    long long int n,a,b,arr[20],c,i;
    while(cin>>n)
    {
        c=a=b=0;
        while(1)
        {
            if(n==0)
                break;
            arr[c++]=n%10;
            n/=10;
        }
        sort(arr,arr+c);
        for(i=c-1; i>=0; i--)
            a=((a*10)+arr[i]);
        if(arr[0]==0)
        {
            for(i=0; i<c; i++)
            {
                if(arr[i]>0)
                {
                    arr[0]=arr[i];
                    arr[i]=0;
                    break;
                }
            }
        }
        for(i=0; i<c; i++)
            b=((b*10)+arr[i]);
        n=a-b;
        n/=9;
        printf("%lld - %lld = %lld = 9 * %lld\n",a,b,a-b,n);
    }
    return 0;
}
