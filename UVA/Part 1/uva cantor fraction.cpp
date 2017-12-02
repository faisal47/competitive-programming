#include <iostream>
#include <stdio.h>
using namespace std;
unsigned long long arr[100000][2];
int main ()
{
    unsigned long long i,j,a,b,c=1,flag1=0;
    arr[0][0]=1;
    arr[0][1]=1;
    i=2;
    j=1;
    a=2;
    b=1;
    while(1)
    {
        arr[c][0]=i;
        arr[c][1]=j;
        if(i==1)
        {
                flag1=1;
                i=j+2;
                j=0;
        }
        i-=1;
        j+=1;
        ++c;
        if(c==10000004)
            break;
    }
    while((scanf("%llu",&c))==1)
        cout<<arr[c-1][0]<<"/"<<arr[c-1][1]<<endl;
    return 0;
}
