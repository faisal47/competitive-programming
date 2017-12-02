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
#define scll1(a) scanf(" %lld",&a)
#define scll2(a,b) scanf(" %lld %lld",&a,&b)
#define scll3(a,b,c) scanf(" %lld %lld %lld",&a,&b,&c)
#define sci1(a) scanf(" %d",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define sci3(a,b,c) scanf(" %d %d %d",&a,&b,&c)
#define sz(a) a.size()
#define ll long long
#define mt
using namespace std;

const ll mod=1000000007;

struct matrix
{
    ll x[36][36];
};

matrix base,zero,ans;

matrix matmult(matrix &a,matrix &b,int n)//m*n and n*r matrix  //1 based
{
    matrix ret;
    int i,j,k;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            ret.x[i][j]=0;
            for(k=1; k<=n; k++)
                ret.x[i][j]=ret.x[i][j]+(a.x[i][k]*b.x[k][j])%mod; //we can reduce complexity here
            ret.x[i][j]%=mod;
        }
    return ret;
}

matrix bigmod(matrix b,long long p,int n) //have to pass n
{
    matrix xx=zero;
    int i;
    for(i=1; i<=n; i++) xx.x[i][i]=1;
    matrix power=b;
    while(p)
    {
        if((p&1)==1) xx=matmult(xx,power,n);
        power=matmult(power,power,n);
        p/=2;
    }
    return xx;
}

map<ll,ll>m1;

bool check1(int a)
{
    return a>=0 && a<=6;
}

bool check2(int a,int b,int c,int d)
{
    return a!=b && a!=c && a!=d && b!=c && b!=d && c!=d;
}

int main ()
{
    ll mask=1<<7,c=1,asi;

    ll test,t=1,arr[36],x[]= {-1,1},i,j,k,l,n,a,b,d,jabo,ans1,arr1[5],m;

    while(mask--)
    {
        if(__builtin_popcountll(mask)==4)
            {
                m1[mask]=c;
                arr[c++]=mask;
            }
    }

    for(i=1;i<=35;i++)
    {
        asi=m1[arr[i]];

        c=1;

        for(j=0;j<7;j++)
        if((1<<j) & arr[i])
        arr1[c++]=j;
        for(j=0;j<2;j++)
        for(k=0;k<2;k++)
        for(l=0;l<2;l++)
        for(m=0;m<2;m++)
        {
            jabo=0;
            a=arr1[1]+x[j];
            b=arr1[2]+x[k];
            c=arr1[3]+x[l];
            d=arr1[4]+x[m];

            jabo|=1<<a;
            jabo|=1<<b;
            jabo|=1<<c;
            jabo|=1<<d;

            if(check1(a) && check1(a) && check1(a) && check1(a) && check2(a,b,c,d))
            base.x[asi][m1[jabo]]=1;

        }
    }

    scll1(test);
    while(test--)
    {
        c=1;
        scll1(n);

        asi=0;

        for(i=0; i<7; i++)
        {
            scll1(j);
            if(j)
            {
                asi|=(1<<i);
                arr[c++]=i;
            }
        }

        asi=m1[asi];


        printf("Case %lld: ",t++);

//        for(i=1;i<=35;i++)
//        {
//            for(j=1;j<=35;j++)
//            cout<<base.x[i][j]<<" ";
//            cout<<endl;
//        }

        if(n==1LL)
            cout<<1LL<<endl;
        else
        {
            ans1=0;
            ans=bigmod(base,n-1,35);
            for(i=1; i<=35; i++)
                ans1=(ans1+ans.x[asi][i])%mod;
            printf("%lld\n",ans1);
        }

    }

    return 0;
}


