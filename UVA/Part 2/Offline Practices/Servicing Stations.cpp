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
//ll bigmod(ll B,ll P,ll M){ll R=1;while(P>0){if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}return R;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};
//int X[]={1,1,2,2,-1,-1,-2,-2};//knight move//
//int Y[]={2,-2,1,-1,2,-2,1,-1};//knight move//

#define mt 40
#define mod

vec_<int>temp,adj[mt];
bool col[mt];
queue<int>q;
void get_graph_bfs(int s)
{
    clr(temp);
    while(!q.empty())
        q.pop();
    int i,v;
    q.push(s);
    col[s]=1;
    temp.pb(s);
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        for(i=0; i<sz(adj[s]); i++)
        {
            v=adj[s][i];
            if(!col[v])
            {
                temp.pb(v);
                q.push(v);
                col[v]=1;
            }
        }
    }
}

bool col2[mt],dis_col[mt];

int bfs_solve(int s)
{
    ms(col2,0);
    int c1,c2,i,v;
    c2=0;
    c1=1;
    col2[s]=1;
    dis_col[s]=1;
    while(!q.empty())q.pop();
    q.push(s);
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        for(i=0; i<sz(adj[s]); i++)
        {
            v=adj[s][i];
            if(!col2[v])
            {
                dis_col[v]=dis_col[s]^1;
                q.push(v);
                col2[v]=1;
                if(dis_col[v])c1++;
                else c2++;
            }

        }
    }
    return min(c1,c2);
}

int get_ans()
{
    int ret=inf,i;
    for(i=0; i<sz(temp); i++)
        ret=min(ret,bfs_solve(temp[i]));
    return ret;
}

int main ()
{
    int i,j,n,m,ans,b,a;

    while(sci2(n,m)==2)
    {
        if(n==0 && m==0)
            break;
        ans=0;
        for(i=1; i<=n; i++)
            clr(adj[i]);
        ms(col,0);
        while(m--)
        {
            sci2(a,b);
            adj[a].pb(b);
            adj[b].pb(a);
        }
        for(i=1; i<=n; i++)
            if(!col[i])
            {
                get_graph_bfs(i);
                ans+=get_ans();
            }
        printf("%d\n",ans);
    }

    return 0;
}

