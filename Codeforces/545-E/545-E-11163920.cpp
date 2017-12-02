#include <bits/stdc++.h>

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <math.h>
#include <limits.h>
#include <limits>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <set>
#include <ctime>
#include <queue>
#include <vector>
#include <map>
#include <assert.h>
#include <utility>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf (1ll<<60)
#define mp make_pair
#define pi acos(-1)
#define pii pair<int,int>
#define fs first
#define sc second
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define sf scanf
#define pf printf
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
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
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
#define rep(i,n) for(i=0;i<n;i++)
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


//double dur(int x1,int y1,int x2,int y2)
//{
//    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//}
//template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll B,ll P,ll M){ll R=1;while(P>0){if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}return R;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};
//int X[]={1,1,2,2,-1,-1,-2,-2};//knight move//
//int Y[]={2,-2,1,-1,2,-2,1,-1};//knight move//

#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define mt 300010
#define mod

struct pq
{
    ll cost;
    int node,rlx;
    bool operator<(const pq &b)const
    {
        return cost>b.cost; // Min Priority Queue(b is curret)
    }
};
ll dist[mt];
ll par_dist[mt];
vec_<pq>adj[mt];
int rlxm[mt];
map<pii,int>ma;
pq temp;
int par[mt];

void dj(int node)
{
    dist[node]=0;
    priority_queue<pq>q;
    temp.node=node;
    pq u,v;
    int i;
    temp.cost=0;
    temp.rlx=0;
    q.push(temp);
    while(!q.empty())
    {
        u=q.top();
        q.pop();
        for(i=0; i<sz(adj[u.node]); i++)
        {
            v=adj[u.node][i];
            v.cost+=u.cost;
            v.rlx=1+u.rlx;
            if(v.cost < dist[v.node])
            {
//                rlxm[v.node]=v.rlx;
                par[v.node]=u.node;
                par_dist[v.node]=adj[u.node][i].cost;
                dist[v.node]=v.cost;
                q.push(v);
            }
            else if(v.cost == dist[v.node])
            {
                int upar=par[v.node];
                if(dist[upar] < dist[u.node])
                {
//                    rlxm[v.node]=v.rlx;
                    par[v.node]=u.node;
                    par_dist[v.node]=adj[u.node][i].cost;
                    dist[v.node]=v.cost;
                    q.push(v);
                }
            }
        }
    }
}

void pre(int n)
{
    int i;
    for(i=1; i<=n; i++)
        dist[i]=(1ll<<60);
}

ll mot_cost;
vec_<int>ans;

void make_ans(int n)
{
    int i,ind,u,v;
    for(i=1; i<=n; i++)
    {
        if(par[i] != 0)
        {
            mot_cost+=par_dist[i];
            u=i;
            v=par[i];
            ans.pb(ma[mp(u,v)]);
        }
    }
}

int main ()
{
//    cffi;
    int i,j,n,m,a,b,u;
    ll cs;
    sci2(n,m);
    pre(n);
    for(i=1; i<=m; i++)
    {
        scanf("%d %d %I64d",&a,&b,&cs);
        ma[mp(a,b)]=i;
        ma[mp(b,a)]=i;
        temp.rlx=0;
        temp.node=b;
        temp.cost=cs;
        adj[a].pb(temp);
        temp.node=a;
        adj[b].pb(temp);
    }
    sci1(u);
    dj(u);

    mot_cost=0;
    make_ans(n);

    printf("%I64d\n",mot_cost);

    for(i=0; i<sz(ans); i++)
    {
        if(i)
            printf(" ");
        printf("%d",ans[i]);
    }
    printf("\n");
    return 0;
}