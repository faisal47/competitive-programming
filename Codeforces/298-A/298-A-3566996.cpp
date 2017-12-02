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
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
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
    ll i,j,n,s,t;
    bool lflag=0,rflag=0,suru=0,shesh=0;
    string arr;
    while(cin>>n)
    {
        cin>>arr;
        for(i=0;i<n;i++)
        {
            if(arr[i]=='R' && rflag==0)
            {
                s=i+1;
                rflag=1;
            }
            if(arr[i]=='L' && lflag==0)
            {
                lflag=1;
                t=i;
            }
        }
        if(rflag && lflag)
        {
            cout<<s<<" "<<t<<endl;
            return 0;
        }
        if(lflag && rflag==0)
        {
            t=-2;
            for(i=n-1;i>=0;i--)
            {
                if(arr[i]=='L' && suru==0)
                {
                    suru=1;
                    s=i+1;
                }
                else if(arr[i]=='L' && suru)
                {
                    t=i;
                }
            }
            if(t==-2)
            {
                cout<<s<<" "<<s-1;
                return 0;
            }
            else
            {
                cout<<s<<" "<<t;
                return 0;
            }
        }
        if(lflag==0 && rflag)
        {
            t=-2;
            for(i=0;i<n;i++)
            {
                if(arr[i]=='R' && suru==0)
                {
                    suru=1;
                    s=i+1;
                }
                else if(arr[i]=='R' && suru)
                {
                    t=i+2;
                }
            }
            if(t==-2)
            {
                cout<<s<<" "<<s+1;
                return 0;
            }
            else
            {
                cout<<s<<" "<<t;
                return 0;
            }
        }
    }
    return 0;
}