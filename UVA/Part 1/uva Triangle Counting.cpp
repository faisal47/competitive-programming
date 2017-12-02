#include <stdio.h>
#include <iostream>
using namespace std;
unsigned long long arr[1000010];
int main ()
{
   unsigned long long i,jog=1,t=1,x=1;
   int n=1000010;
    arr[3]=1;
    for(i=3;i<=n-5;i++)
    {
        arr[i+1]=arr[i]+jog;
        //cout<<i+1<<" "<<jog<<endl;
       // cout<<i+1<<" "<<arr[i+1]<<endl;
        t++;
        if(t==2)
        {
            t=0;
            jog+=x;
            x++;
        }
        else
        jog+=x;
    }
    while(cin>>n)
    {
        if(n<3)
        break;
        cout<<arr[n]-1<<endl;
    }
    return 0;
}
