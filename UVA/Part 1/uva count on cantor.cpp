#include <iostream>
#include <stdio.h>
using namespace std;
int arr[10000005][2];
int main ()
{
    long long int i,j,a,b,temp,c=1,flag1=0;
    arr[0][0]=1;
    arr[0][1]=1;
    i=1;
    j=2;
    a=1;
    b=2;
    while(1)
    {
        arr[c][0]=i;
        arr[c][1]=j;
        if(i==b&&j==1&&flag1==0)
        {
                flag1=1;
                b=i+1;
                i+=2;
                j=0;
        }
        else if(i==1&&j==b&&flag1==1)
        {
            flag1=0;
            b=j+1;
            i=0;
            j+=2;
        }
        if(flag1==0)
        {
            i+=1;
        j-=1;
        }
        else
        {
            i-=1;
        j+=1;
        }
        ++c;
        if(c==10000002)
            break;
    }
    while((scanf("%lld",&c))==1)
        cout<<"TERM "<<c<<" IS "<<arr[c-1][0]<<"/"<<arr[c-1][1]<<endl;
    return 0;
}
