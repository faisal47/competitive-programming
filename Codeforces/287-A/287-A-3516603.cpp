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
    ll i,j,n,c,d;
    string arr[5];
    for(i=0;i<4;i++)
    cin>>arr[i];
    for(i=0;i<3;i++)
    for(j=0;j<3;j++)
    {
        c=d=0;
        if(arr[i][j]=='#')
        c++;
        else
        d++;
        if(arr[i+1][j]=='#')
        c++;
        else
        d++;
        if(arr[i][j+1]=='#')
        c++;
        else
        d++;
        if(arr[i+1][j+1]=='#')
        c++;
        else
        d++;
        if(c<=1 || d<=1)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}