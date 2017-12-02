#include <bits/stdc++.h>

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
#define allr(a) a.rbegin(),a.rend()
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);
#define scch(a) scanf(" %c",&a)
#define scll1(a) scanf(" %lld",&a)
#define sci1(a) scanf(" %d",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define sci3(a,b,c) scanf(" %d %d %d",&a,&b,&c)
#define scd1(a) scanf(" %lf",&a)
#define scd2(a,b) scanf(" %lf %lf",&a,&b)
#define scd3(a,b,c) scanf(" %lf %lf %lf",&a,&b,&c)
using namespace std;

template<class T1> void deb(T1 e)
{
    cout<<e<<endl;
}
template<class T1,class T2> void deb(T1 e1,T2 e2)
{
    cout<<e1<<" "<<e2<<endl;
}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3)
{
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;
}




#define mt 110
#define mod
#define MAX 210
ll arr[mt][mt];
int n,m;
int par[MAX];
ll num;
bool col[MAX];
bool dfs(int u)
{
    if(col[u])
        return false;
    col[u] = true;
    for(int i = 1; i <=m;i++)
    {
        if(arr[u][i]>num)
            continue;
        if(par[i] == -1 || dfs(par[i]))
        {
            par[i] = u;
            return true;
        }
    }
    return false;
}


int MAX_BMP()
{
    int ret = 0, i;
    ms(par, -1);
    for(i = 1; i <= n; i++)
    {
        ms(col, 0);
        if(dfs(i)) ret++;
    }
    return ret;
}
int k;

ll bs()
{
    ll l=1ll,h=1e12 + 1,mid;
    ll ret=h+10;
    while(l <= h)
    {
        num=mid=(l+h)/2ll;
        if(MAX_BMP() >= k)
        {
            ret=min(ret,mid);
            h=mid-1;
        }
        else
            l=mid+1;
    }
    return ret;
}

int main ()
{
    int i,j;
    sci3(n,m,k);

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        scll1(arr[i][j]);

    printf("%lld\n",bs());

    return 0;
}


