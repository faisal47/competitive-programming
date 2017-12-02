/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

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
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
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
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};
//int X[]={1,1,2,2,-1,-1,-2,-2};//knight move//
//int Y[]={2,-2,1,-1,2,-2,1,-1};//knight move//
/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

#define mt 3*100010
#define mod

vec_<int>adj[mt];
int dist[mt],par[mt],ans_dist[mt];

int find_par(int node)
{
    if(par[node] ==  node)
        return node;
    return par[node]=find_par(par[node]);
}

void make_set(int a,int b)
{
    a=find_par(a);
    b=find_par(b);
    if(a != b)
        par[a]=b;
}

int maxi_dist;

queue<int>q;
//bool col[mt];
int tem_par[mt];

int bfs(int s)
{
//    ms(col,0);
    while(!q.empty())q.pop();
    int v,i,x;
    x=s;
    q.push(s);
    dist[s]=0;
    maxi_dist=0;
//    col[s]=1;
    tem_par[s]=s;
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        for(i=0; i<sz(adj[s]); i++)
        {
            v=adj[s][i];
            if(tem_par[s] == v)
                continue;
            tem_par[v]=s;
//            if(col[v])
//                continue;
//            col[v]=1;
////            if(v == s)
//                continue;
////            deb(s,v);
            x=v;
            q.push(v);
            dist[v]=dist[s]+1;
            maxi_dist=dist[v];
        }
    }
    return x;
}

int find_dist(int node)
{
    node=bfs(node);
//    deb("hello");
    maxi_dist=-1;
    bfs(node);
    return maxi_dist;
}

int main ()
{
    int i,j,n,m,q,a,b;

    sci3(n,m,q);
    for(i=1; i<=n; i++)
        par[i]=i;

    while(m--)
    {
        sci2(a,b);
        adj[a].pb(b);
        adj[b].pb(a);
        make_set(a,b);
    }

    ms(ans_dist,-1);

    for(i=1; i<=n; i++)
    {
        if(ans_dist[find_par(i)] == -1)
            ans_dist[find_par(i)]=find_dist(find_par(i));
    }

    int d1,d2;

    while(q--)
    {
        sci1(a);
        if(a==1)
        {
            sci1(a);
            printf("%d\n",ans_dist[find_par(a)]);
        }
        else
        {
            sci2(a,b);
            a=find_par(a);
            b=find_par(b);
            if(a==b)
                continue;
            par[a]=b;
            d1=ans_dist[a];
            d2=ans_dist[b];
            ans_dist[a]=ans_dist[b]=max(max(d1,d2),(d1+1)/2+(d2+1)/2 +1);
        }
    }

    return 0;
}