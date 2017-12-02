#include <bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define clr(a) a.clear()
#define pb push_back
#define pob pop_back
#define vec_ vector
#define eps 1E-7
#define sort_n(a) sort(a.begin(),a.end())
#define sort_m(a) sort(a.begin(),a.end(),comp)
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define scch(a) scanf("%c",&a)
#define scll1(a) scanf("%I64d",&a)
#define scll2(a,b) scanf("%I64d %I64d",&a,&b)
#define scll3(a,b,c) scanf("%I64d %I64d %I64d",&a,&b,&c)
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define scd1(a) scanf("%lf",&a)
#define scd2(a,b) scanf("%lf %lf",&a,&b)
#define scd3(a,b,c) scanf("%lf %lf %lf",&a,&b,&c)
#define mp make_pair
#define sz(a) a.size()
#define mt 1010
using namespace std;
bool flag[mt];
vec_<int>v[mt];
struct info1
{
    int koyta;
    bool bachbe;
};
info1 dfs(int s)
{
    info1 info,info_apato;
    info.koyta=0;
    info.bachbe=0;
    flag[s]=1;
    int i,j;
    for(i=0;i<sz(v[s]);i++)
    {
        j=v[s][i];
        if(!flag[j])
        {
            info_apato=dfs(j);
            info.koyta+=info_apato.koyta;
            info.bachbe=info.bachbe|info_apato.bachbe;
        }
    }
    if(!info.koyta)
    {
        info.koyta=1;
        info.bachbe=1;
        return info;
    }
    if(!info.bachbe)info.koyta++;
    if(info.bachbe)info.bachbe=0;
    else info.bachbe=1;
    return info;
}
int main ()
{
    int n,m,test,t=1,i,j,ans;
    sci1(test);
    while(test--)
    {
        ans=0;
        sci2(n,m);
        for(i=1;i<=n;i++)
        {
            clr(v[i]);
            flag[i]=0;
        }
        while(m--)
        {
            sci2(i,j);
            v[i].pb(j);
            v[j].pb(i);
        }
        for(i=1;i<=n;i++)
        {
            if(!flag[i])
            ans+=dfs(i).koyta;
        }
        printf("Case %d: %d\n",t++,ans);
    }
    return 0;
}

