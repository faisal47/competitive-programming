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
#define mt 15
using namespace std;

int f[mt],dp[mt][(1<<mt)+10],n;

string pattern;
string a,b;
int kmp()
{
   pattern=b+'#'+a;
    int k;

    f[0]=k=0;
    int i;

    int len1=sz(b);

    for(i=1; i<sz(pattern); i++)
    {
        while(k>0 && pattern[i]!=pattern[k])
            k=f[k-1];

        if(pattern[i]==pattern[k])
            k++;
        if(k==len1)
        return len1;
        f[i]=k;
    }

    return f[sz(pattern)-1];
}

string st[16];

int mx,matching[16][16];

int solve(int pre,int mask)
{
    if(mask == (1<<n)-1)
    return 0;

    int &ret=dp[pre][mask];

    if(ret!=-1)
    return ret;

    ret=0;

    for(int i=0;i<n;i++)
    if(!(mask & (1<<i)))
    {
        if(matching[pre][i] == sz(st[i]))
        ret=max(ret,matching[pre][i]+solve(pre,mask | (1<<i)));
        else
        ret=max(ret,matching[pre][i]+solve(i,mask | (1<<i)));
    }

    return ret;

}

int main ()
{
    int i,j,mot;

    while(cin>>n && n)
    {
        mx=mot=0;

        for(i=0; i<n; i++)
            {
                cin>>st[i];
                mot+=sz(st[i]);
            }

        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        if(i!=j)
        {
            a=st[i];
            b=st[j];
            matching[i][j]=kmp();
        }
        ms(dp,-1);

        for(i=0;i<n;i++)
        {
            mx=max(mx,solve(i, 0 | (1<<i) ));
        }

        cout<<mot-mx<<endl;
    }
    return 0;
}


