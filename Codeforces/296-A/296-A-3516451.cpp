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
    ll i,j,n,ma,arr1[1010];
    while(cin>>n)
    {
        ma=-1;
       ms(arr1,0);
       for(i=0;i<n;i++)
       {
           cin>>j;
           arr1[j]++;
           ma=max(ma,arr1[j]);
       }
       if(n%2==1 && ma>((n/2)+1))
       cout<<"NO\n";
       else if(n%2==0 && ma>(n/2))
       cout<<"NO\n";
       else
       cout<<"YES\n";
    }
    return 0;
}