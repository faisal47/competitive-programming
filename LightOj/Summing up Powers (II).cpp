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
#define mod 10
using namespace std;

struct matrix{
     ll x[35][35];
};
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
            ret.x[i][j]=ret.x[i][j]+(a.x[i][k]*b.x[k][j])%mod;
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

matrix multadd(matrix a,matrix b,int n)
{
    int i,j;
    matrix ret;
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    ret.x[i][j]=a.x[i][j]+b.x[i][j];

    return ret;
}

matrix solve(matrix a,int p,int n)
{
    if(p==1)
    return a;

    int m=p>>1;
    matrix ret=solve(a,m,n);
    matrix big=bigmod(base,m,n);
    big=matmult(big,ret,n);
    ret=multadd(big,ret,n);
    if(p&1)
    {
        big=bigmod(base,p,n);
        ret=multadd(ret,big,n);
    }
    return ret;
}

int main ()
{
    int test,t=1,n,m,i,j;
    sci1(test);
    while(test--)
    {
        sci2(n,m);
        base=zero;
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        scll1(base.x[i][j]);
        ans=solve(base,m,n);
        printf("Case %d:\n",t++);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            cout<<ans.x[i][j]%10;
            cout<<endl;
        }

    }
    return 0;
}


