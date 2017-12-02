#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <math.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define ll long long
#define FOR_0(i,n) for(i=0;i<n;i++)
#define FOR_1(i,n) for(i=1;i<=n;i++)
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
//ll bigmod(ll a,ll b,ll m)
//{
//    if(b == 0) return 1%m;
//    ll x = bigmod(a,b/2,m);
//    x = (x * x) % m;
//    if(b % 2 == 1) x = (x * a) % m;
//    return x;
//}
#define sz
using namespace std;
int main ()
{
    ll i,j,a,b,n;
    bool yes_flag;
    while(cin>>a>>b>>n)
    {
        yes_flag=0;
        for(i=0;i<=9;i++)
        {
            if((a*10+i)%b==0)
            {
                cout<<a<<i;
                for(j=1;j<n;j++)
                cout<<0;
                cout<<endl;
                yes_flag=1;
                break;
            }
        }
        if(!yes_flag)
        cout<<-1<<endl;
    }
    return 0;
}