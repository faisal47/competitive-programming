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
    ll i,j,s1,s2,e1,e2,n;
    string arr;
    cin>>n>>s1>>s2>>e1>>e2;
    cin>>arr;
    for(i=0;i<n;i++)
    {
        if(arr[i]=='E')
        {
            if(s1<e1)
            s1++;
        }
        else if(arr[i]=='N')
        {
            if(s2<e2)
            s2++;
        }
        else if(arr[i]=='W')
        {
            if(s1>e1)
            s1--;
        }
        else if(arr[i]=='S')
        {
            if(s2>e2)
            s2--;
        }
        if(s1==e1 && s2==e2)
        {
            cout<<i+1;
            return 0;
        }
    }
    cout<<"-1";
    return 0;
}