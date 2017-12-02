#include <iostream>
#include <stdio.h>
using namespace std;
int arr[70000];
int main ()
{
    unsigned long long n,c=0;
    int a=10,i=1;
    for(i=1;i<10;i++)
    arr[c++]=i;
    while(1)
    {
        i=a;
        if(i>=10&&i<100)
        {
            arr[c+1]=i%10;
            arr[c]=i/10;
            c+=2;
        }
        else if(i>=100&&i<1000)
        {
            arr[c+2]=i%10;i/=10;
            arr[c+1]=i%10;i/=10;
            arr[c]=i%10;
            c+=3;
        }
        else if(i>=1000&&i<10000)
        {
            arr[c+3]=i%10;i/=10;
            arr[c+2]=i%10;i/=10;
            arr[c+1]=i%10;i/=10;
            arr[c]=i%10;
            c+=4;
        }
        else if(i>=10000&&i<100000)
        {
            arr[c+4]=i%10;i/=10;
            arr[c+3]=i%10;i/=10;
            arr[c+2]=i%10;i/=10;
            arr[c+1]=i%10;i/=10;
            arr[c]=i%10;
            c+=5;
        }
        else if(i>=100000&&i<1000000)
        {
            arr[c+5]=i%10;i/=10;
            arr[c+4]=i%10;i/=10;
            arr[c+3]=i%10;i/=10;
            arr[c+2]=i%10;i/=10;
            arr[c+1]=i%10;i/=10;
            arr[c]=i%10;
            c+=6;
        }
        else if(i>=1000000&&i<10000000)
        {
            arr[c+6]=i%10;i/=10;
            arr[c+5]=i%10;i/=10;
            arr[c+4]=i%10;i/=10;
            arr[c+3]=i%10;i/=10;
            arr[c+2]=i%10;i/=10;
            arr[c+1]=i%10;i/=10;
            arr[c]=i%10;
            c+=7;
        }
        else if(i>=10000000&&i<100000000)
        {
            arr[c+7]=i%10;i/=10;
            arr[c+6]=i%10;i/=10;
            arr[c+5]=i%10;i/=10;
            arr[c+4]=i%10;i/=10;
            arr[c+3]=i%10;i/=10;
            arr[c+2]=i%10;i/=10;
            arr[c+1]=i%10;i/=10;
            arr[c]=i%10;
            c+=8;
        }
        ++a;
        if(c>=66000)
        break;
    }
    while((scanf("%llu",&n))==1)
    cout<<arr[n-1]<<endl;
    return 0;
}
