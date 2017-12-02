#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
long long dp1[35],dp2[35];
long long res=0;
long long call(int n);
long long call1(int n);
int main ()
{
    memset(dp1,-1,sizeof(dp1));
    memset(dp2,-1,sizeof(dp2));
    int n;
    while(cin>>n)
    {
        res=0;
        if(n==-1)
        break;
        if(n==0)
        {
            cout<<"1"<<endl;continue;
        }
        if(n%2==1)
        {
            cout<<"0"<<endl;continue;
        }
        cout<<call(n)<<endl;
    }
    return 0;
}
long long call(int n)
{
    if(n==0)
    return 1;
    else if(n==1)
    return 0;
    if(dp1[n]!=-1)
    return dp1[n];
    return dp1[n]=call(n-2)+call1(n-1)+call1(n-1);
}
long long call1(int n)
{
    if(n==0)
    return 0;
    else if(n==1)
    return 1;
    if(dp2[n]!=-1)
    return dp2[n];
    return dp2[n]=call(n-1)+ call1(n-2);
}
