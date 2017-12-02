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
    ll i,j,n,maan,a,b,c;
    while(cin>>n)
    {
        c=j=0;
        for(i=0;i<n;i++)
        {
            cin>>a;
            j+=a;
        }
        n++;
        for(i=1;i<=5;i++)
        {
            maan=j+i;
            if(maan%n!=1)
            c++;
        }
        cout<<c<<endl;
    }
    return 0;
}