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
ll mat[2][2],ref[2][2],emne[2][2],mod;
void goon(void)
{
    emne[0][0]=((((mat[0][0]%mod)*(mat[0][0]%mod))%mod)+(((mat[0][1]%mod)*(mat[1][0]%mod))%mod))%mod;
    emne[0][1]=((((mat[0][0]%mod)*(mat[0][1]%mod))%mod)+(((mat[0][1]%mod)*(mat[1][1]%mod))%mod))%mod;
    emne[1][0]=((((mat[1][0]%mod)*(mat[0][0]%mod))%mod)+(((mat[1][1]%mod)*(mat[1][0]%mod))%mod))%mod;
    emne[1][1]=((((mat[1][0]%mod)*(mat[0][1]%mod))%mod)+(((mat[1][1]%mod)*(mat[1][1]%mod))%mod))%mod;
    mat[0][0]=emne[0][0];
        mat[1][0]=emne[1][0];
        mat[1][1]=emne[1][1];
        mat[0][1]=emne[0][1];
}
void goon1(void)
{
    emne[0][0]=(((mat[0][0]*ref[0][0])%mod)+((mat[0][1]*ref[1][0])%mod))%mod;
    emne[0][1]=(((mat[0][0]*ref[0][1])%mod)+((mat[0][1]*ref[1][1])%mod))%mod;
    emne[1][0]=(((mat[1][0]*ref[0][0])%mod)+((mat[1][1]*ref[1][0])%mod))%mod;
    emne[1][1]=(((mat[1][0]*ref[0][1])%mod)+((mat[1][1]*ref[1][1])%mod))%mod;
    mat[0][0]=emne[0][0];
    mat[1][0]=emne[1][0];
    mat[1][1]=emne[1][1];
    mat[0][1]=emne[0][1];
}
void func(ll n)
{
    if(n==1)
    {
        mat[0][0]=ref[0][0];
        mat[1][0]=ref[1][0];
        mat[1][1]=ref[1][1];
        mat[0][1]=ref[0][1];
        return;
    }
    func(n/2);
    goon();
    if(n%2==1)
    {
        goon1();
    }
}
int main ()
{
    ref[0][0]=1;
    ref[0][1]=1;
    ref[1][0]=1;
    ref[1][1]=0;
    ll i,j,test,t,a,b,n,m,ans;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        cin>>a>>b>>n>>m;
        if(m==1)
        mod=10;
        else if(m==2)
        mod=100;
        else if(m==3)
        mod=1000;
        else
        mod=10000;
        if(n==0)
        {
            printf("Case %lld: %lld\n",t,a%mod);
            continue;
        }
        else if(n==1)
        {
            printf("Case %lld: %lld\n",t,b%mod);
            continue;
        }
        if(m==1)
        mod=10;
        else if(m==2)
        mod=100;
        else if(m==3)
        mod=1000;
        else
        mod=10000;
        func(n-1);
        ans=(((mat[0][0]*b)%mod)+((mat[0][1]*a)%mod))%mod;
        printf("Case %lld: %lld\n",t,ans);
    }
    return 0;
}

