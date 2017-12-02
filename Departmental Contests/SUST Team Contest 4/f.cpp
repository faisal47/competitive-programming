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

string str,s;
char dp[100010][11];
int solve(int i,int j,int op)
{
    char &ret=dp[i][j];

    if(sz(s)==j)
        return op;
    if(op==sz(s) || i>=str.size())
        return 11;
    int mn=10;
    if(ret!=-1)
        return ret;
    if(str[i]==s[j]){
        mn=min(mn,solve(i+1,j+1,op));
        if(j==0)
            mn=min(mn,solve(i+1,j,op));
        else
            mn=min(mn,solve(i+1,j,op+1));
    }
    else{
        mn=min(mn,solve(i+1,j+1,op+1));
        if(j==0)
            mn=min(mn,solve(i+1,j,op));
        else
            mn=min(mn,solve(i+1,j,op+1));
    }
    return ret=mn;

}

int main ()
{
    int n,ans,ret;
    string ans1;
    while(cin>>str)
    {
        cin>>n;
        ans=inf;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            string a, b, c;
            a = s.substr(0, SZ(s) / 2);
            b = s.substr(SZ(s) / 2);
            c = s.substr(SZ(s) * 2/ 3);
            ms(dp,-1);
            ret=min(ans,solve(0,0,0));
            if(ans>ret)
            {
                ans=ret;
                ans1=s;
            }
        }
        cout<<s<<" "<<ans<<endl;
    }
    return 0;
}


