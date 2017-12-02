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
#define scll1(a) scanf("%lld",&a)
#define scll2(a,b) scanf("%lld %lld",&a,&b)
#define scll3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
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
vec_<int>v[mt];
bool flag[mt];
int n,i,j,s,dist[mt];
void bfs()
{
    s=0;
    flag[0]=1;dist[0]=0;
    queue<int>q;
    q.push(0);
    while(!q.empty())
    {
        s=q.front();q.pop();
        for(i=0;i<sz(v[s]);i++)
        {
            j=v[s][i];
            if(!flag[j])
            {
                flag[j]=1;
                dist[j]=dist[s]+1;
                q.push(j);
            }
        }
    }
}
int main ()
{
    int p,t;
    sci1(t);
    while(t--)
    {
        sci2(n,p);
       for(i=0;i<n;i++)
       clr(v[i]),flag[i]=false;
        while(p--)
        {
         sci2(i,j);
         v[i].pb(j);
         v[j].pb(i);
        }
        bfs();
        for(i=1;i<n;i++)
        cout<<dist[i]<<endl;
        if(t)
        cout<<endl;
    }
    return 0;
}

