#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <utility>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define mp make_pair
#define pii pair<int,int>
#define fs first
#define sc second
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define sort_n(a) sort(a.begin(),a.end())
#define sort_m(a) sort(a.begin(),a.end(),comp)
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define scch(a) scanf(" %c",&a)
#define scll1(a) scanf(" %I64d",&a)
#define scll2(a,b) scanf(" %I64d %I64d",&a,&b)
#define scll3(a,b,c) scanf(" %I64d %I64d %I64d",&a,&b,&c)
#define sci1(a) scanf(" %d",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define sci3(a,b,c) scanf(" %d %d %d",&a,&b,&c)
#define scd1(a) scanf(" %lf",&a)
#define scd2(a,b) scanf(" %lf %lf",&a,&b)
#define scd3(a,b,c) scanf(" %lf %lf %lf",&a,&b,&c)
#define pri1(a) printf("%d ",a)
#define pri2(a,b) printf("%d %d ",a,b)
#define prll1(a) printf("%I64d ",a)
#define prll2(a,b) printf("%I64d %I64d ",a,b)
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define mt
using namespace std;

struct matrix{
     ll x[5][5];
};

const ll mod=10007;

matrix base,zero,ans;

matrix matmult(matrix &a,matrix &b,int n)//m*n and n*r matrix  //1 based
{
    matrix ret;
    int i,j,k;
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
        ret.x[i][j]=0;
        for(k=1;k<=n;k++)
            ret.x[i][j]=ret.x[i][j]+(a.x[i][k]*b.x[k][j])%mod; //we can reduce complexity here
        ret.x[i][j]%=mod;
    }
    return ret;
}

matrix bigmod(matrix b,long long p,int n) //have to pass n
{
    matrix xx=zero;
    int i;
    for(i=1;i<=n;i++) xx.x[i][i]=1;
    matrix power=b;
    while(p)
    {
        if((p&1)==1) xx=matmult(xx,power,n);
        power=matmult(power,power,n);
        p/=2;
    }
    return xx;
}

int main ()
{
    ll x,n,y,ans1;
    while(scll3(n,x,y)==3)
    {
            base.x[1][1]=1;
            base.x[1][2]=(x*x)%mod;
            base.x[1][3]=(2*x*y)%mod;
            base.x[1][4]=(y*y)%mod;

            base.x[2][1]=0;
            base.x[2][2]=(x*x)%mod;
            base.x[2][3]=(2*x*y)%mod;
            base.x[2][4]=(y*y)%mod;

            base.x[3][1]=0;
            base.x[3][2]=x%mod;
            base.x[3][3]=y%mod;
            base.x[3][4]=0;

            base.x[4][1]=0;
            base.x[4][2]=1;
            base.x[4][3]=0;
            base.x[4][4]=0;

            ans=bigmod(base,n-1,4);

            ans1=0;
            ans1=(ans.x[1][1]*2)%mod;
            ans1=(ans1+ans.x[1][2])%mod;
            ans1=(ans1+ans.x[1][3])%mod;
            ans1=(ans1+ans.x[1][4])%mod;

        cout<<ans1<<endl;
    }
    return 0;
}


