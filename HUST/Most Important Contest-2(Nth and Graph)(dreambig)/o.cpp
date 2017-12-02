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
#define sf scanf
#define pf printf
#define all(a) a.begin(),a.end()
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
#define deb1(a) cout<<a<<endl;
#define deb2(a,b) cout<<a<<" "<<b<<endl
#define deb3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
using namespace std;
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
int X[]={0,-1,-1,-1,0,1,1,1};
int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};

///***************************************************** ekhon kamer kam ********************************************************************///

#define mt 110

char arr[mt][mt];
int flag[mt][mt],c;
int n,m;

pii solve(char *arr)
{
    int a=0,b=0,len,i;
    bool f=0;
    len=strlen(arr);
    for(i=0;i<len;i++)
    {
        if(arr[i]==' ')
            f=1;
        else if(f)
            b=(b*10)+arr[i]-'0';
        else
            a=(a*10)+arr[i]-'0';
    }

    return mp(--a,--b);
}

bool check(int s,int e)
{
    return s>=0 && e<n && e>=0 && e<m && arr[s][e]=='W';
}

void dfs(int s,int e)
{
    int i,s1,e1;
    for(i=0;i<8;i++)
    {
        s1=s+X[i];
        e1=e+Y[i];
        if(check(s1,e1) && !flag[s1][e1])
        {
            flag[s1][e1]=1;
            c++;
            dfs(s1,e1);
        }
    }
}

int main ()
{
    int test,t=0;
    pii a;
    char z;
    sf(" %d%c",&test,&z);
    getchar();
    while(test--)
    {
        n=0;

        while(gets(arr[n]))
        {
            if(arr[n][0]!='L' && arr[n][0]!='W')
                break;
            n++;
        }

        m=strlen(arr[n-1]);
        a=solve(arr[n]);
        ms(flag,0);
        if(t++)
            cout<<endl;
        c=1;
        flag[a.fs][a.sc]=1;
        dfs(a.fs,a.sc);
        cout<<c<<endl;

        while(gets(arr[n]))
        {
            if(strlen(arr[n])==0)
                break;
            a=solve(arr[n]);
            ms(flag,0);
            c=1;
            flag[a.fs][a.sc]=1;
            dfs(a.fs,a.sc);
            cout<<c<<endl;
        }
    }
    return 0;
}


