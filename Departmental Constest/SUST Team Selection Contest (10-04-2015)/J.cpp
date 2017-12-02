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
#define inf 1<<28
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
using namespace std;

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}


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
#define mt 100010
#define mod

vec_<int>adj[mt];
int dist1[mt];
queue<int>q;

void bfs1(int s)
{
    int v,u,i;
    while(!q.empty())q.pop();
    q.push(s);
    ms(dist1,61);
    dist1[s]=0;
    while(!q.empty())
    {
        u=q.front();q.pop();
        for(i=0;i<sz(adj[u]);i++)
        {
            v=adj[u][i];
            if(dist1[v] > dist1[u]+1)
            {
                q.push(v);
                dist1[v] = dist1[u]+1;
            }
        }
    }
    while(!q.empty())q.pop();
}

int dist2[mt],ans[mt];

int bfs2(int s,int b)
{
    q.push(s);
    int u,v,i;
    ms(dist2,61);
    dist2[s]=0;
    ms(ans,-1);
    ans[s]=dist1[s];

    while(!q.empty())
    {
        u=q.front();q.pop();
        for(i=0;i<sz(adj[u]);i++)
        {
            v=adj[u][i];
            if(dist2[v] > dist2[u]+1)
            {
                q.push(v);
                dist2[v] = dist2[u]+1;
                ans[v]=min(dist1[v],max(ans[v],ans[u]));
            }
            else if(dist2[v] == dist2[u]+1)
                ans[v]=min(dist1[v],max(ans[v],ans[u]));
        }
    }
    return ans[b];
}

int main ()
{
    cffi;
    int i,j,n,m,a,b,c;

    cin>>n>>m;
    while(m--)
    {
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    cin>>a>>b>>c;

    bfs1(c);

    deb(bfs2(a,b));

    return 0;
}

