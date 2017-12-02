
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
int X[]= {-1,0,1,0};
int Y[]= {0,1,0,-1};
//int X[]={1,1,2,2,-1,-1,-2,-2};//knight move//
//int Y[]={2,-2,1,-1,2,-2,1,-1};//knight move//

#define mt
#define mod

char arr[35][35];
int dist[35][35];
bool col[35][35];

int arrd[30][110],pos[35][35];

queue<int>q;
int n;

bool check(int s,int e)
{
    return s>=0 && s<n && e>=0 && e<n && arr[s][e]!='#' && col[s][e]==0;
}

void bfs(int kc,int s,int e)
{
    ms(col,0);
    while(!q.empty())
        q.pop();
    q.push(s);
    q.push(e);
    dist[s][e]=0;
    col[s][e]=1;
    int i,u,v,km;
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        e=q.front();
        q.pop();
        for(i=0; i<4; i++)
        {
            u=X[i]+s;
            v=Y[i]+e;
            if(check(u,v))
            {
                col[u][v]=1;
                dist[u][v]=1+dist[s][e];
                q.push(u);
                q.push(v);
                if(arr[u][v]=='m')
                {
                    km=pos[u][v];
                    arrd[kc][km]=dist[u][v];
                }
            }
        }
    }
}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long L;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

const L INF = numeric_limits<L>::max() / 4;

struct MinCostMaxFlow
{
    int N;
    VVL cap, flow, cost;
    VI found;
    VL dist, pi, width;
    VPII dad;

    MinCostMaxFlow(int N) :
        N(N), cap(N, VL(N)), flow(N, VL(N)), cost(N, VL(N)),
        found(N), dist(N), pi(N), width(N), dad(N) {}

    void AddEdge(int from, int to, L cap, L cost)
    {
        this->cap[from][to] = cap;
        this->cost[from][to] = cost;
    }

    void Relax(int s, int k, L cap, L cost, int dir)
    {
        L val = dist[s] + pi[s] - pi[k] + cost;
        if (cap && val < dist[k])
        {
            dist[k] = val;
            dad[k] = make_pair(s, dir);
            width[k] = min(cap, width[s]);
        }
    }

    L Dijkstra(int s, int t)
    {
        fill(found.begin(), found.end(), false);
        fill(dist.begin(), dist.end(), INF);
        fill(width.begin(), width.end(), 0);
        dist[s] = 0;
        width[s] = INF;

        while (s != -1)
        {
            int best = -1;
            found[s] = true;
            for (int k = 0; k < N; k++)
            {
                if (found[k]) continue;
                Relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
                Relax(s, k, flow[k][s], -cost[k][s], -1);
                if (best == -1 || dist[k] < dist[best]) best = k;
            }
            s = best;
        }

        for (int k = 0; k < N; k++)
            pi[k] = min(pi[k] + dist[k], INF);
        return width[t];
    }

    pair<L, L> GetMaxFlow(int s, int t)
    {
        L totflow = 0, totcost = 0;
        while (L amt = Dijkstra(s, t))
        {
            totflow += amt;
            for (int x = t; x != s; x = dad[x].first)
            {
                if (dad[x].second == 1)
                {
                    flow[dad[x].first][x] += amt;
                    totcost += amt * cost[dad[x].first][x];
                }
                else
                {
                    flow[x][dad[x].first] -= amt;
                    totcost -= amt * cost[x][dad[x].first];
                }
            }
        }
        return make_pair(totflow, totcost);
    }
};



int main ()
{
    int i,j,test,k,m,t=1,K,kc,km;
    MinCostMaxFlow *mcmf;

    sci1(test);
    while(test--)
    {
        sci3(n,K,m);
        kc=0;
        km=0;
        ms(arrd,-1);
        for(i=0; i<n; i++)
            scanf(" %s",arr[i]);

        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                if(arr[i][j] == 'm')
                    pos[i][j]=++km;
                else if(arr[i][j]>='A' && arr[i][j]<='Z')
                    pos[i][j]=arr[i][j]-'A'+1;

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(arr[i][j]>='A' && arr[i][j]<='Z')
                {
                    kc=pos[i][j];
                    bfs(kc,i,j);
                }
            }
        }

        kc=K;
        mcmf = new MinCostMaxFlow(K+m+3);

        for(i=1; i<=kc; i++)
        {
            sci1(k);
            mcmf->AddEdge(0,i,k,0);
            for(j=1; j<=km; j++)
            {
                if(arrd[i][j] != -1)
                    {
                        mcmf->AddEdge(i,j+kc,1,arrd[i][j]);
//                        deb(i,j,arrd[i][j]);
                    }
            }
        }

        for(j=1; j<=km; j++)
            mcmf->AddEdge(j+kc,K+m+1,1,0);

        pair<ll,ll>ans=mcmf->GetMaxFlow(0,K+m+1);

        printf("Case %d: %lld\n",t++,ans.second);

    }

    return 0;
}

