#include <bits/stdc++.h>

#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define mp make_pair
#define pii pair<ll,int>
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
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);
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

#define mt 2010
#define mod
int n;

int arr[mt][mt];
int node_dist[mt][mt];
vec_<int>v[mt];
int par[mt];
int visit[mt],dist[mt];
queue<int>q;

bool bfs(int s)
{
    while(!q.empty())
        q.pop();

//    if(n==1987)
//    {
//        assert(0);
//    }

    int nc=s;
    q.push(s);
    int ms=s;
    dist[s]=0;
    visit[s]=nc;
    int i,u;
    while(!q.empty())
    {
        s=q.front();
        q.pop();

        for(i=0; i<sz(v[s]); i++)
        {
            u=v[s][i];
            if(visit[u] != nc)
            {
                visit[u]=nc;
                dist[u]=node_dist[s][u]+dist[s];
                if(dist[u] != arr[ms][u])
                    return 0;

                q.push(u);
            }
        }
    }
    return 1;
}

struct dists
{
    int a,b,dist;
};

vec_<dists>edges;

int find_par(int s)
{
    if(par[s] == s)
        return s;

    return par[s]=find_par(par[s]);
}

bool mst()
{
    int i,c=0,a,b;
    for(i=0; sz(edges); i++)
    {
        a=find_par(edges[i].a);
        b=find_par(edges[i].b);
//        deb(edges[i].a,edges[i].b,edges[i].dist);
        if(a != b)
        {
//            deb("int mst a,b ",a,b);
            c++;
            v[edges[i].a].pb(edges[i].b);
            v[edges[i].b].pb(edges[i].a);
            par[a]=b;
            node_dist[edges[i].a][edges[i].b]=edges[i].dist;
            node_dist[edges[i].b][edges[i].a]=edges[i].dist;

            if(c==n-1)
                return 1;
        }
    }

    return c==n-1;
}

bool comp(dists a,dists b)
{
    return a.dist<b.dist;
}

int main ()
{
    cffi;
    int i,j;
    cin>>n;

    for(i=1; i<=n; i++)
    {
        par[i]=i;
        for(j=1; j<=n; j++)
        {
            cin>>arr[i][j];
            if(i==j && arr[i][j])
            {
                deb("NO");
                return 0;
            }
            if(i>j && arr[i][j] != arr[j][i])
            {
                deb("NO");
                return 0;
            }

            if(i>j && arr[i][j]>0)
            {
//                deb(i,j,arr[i][j]);
                edges.pb({i,j,arr[i][j]});
            }
        }
    }

    sort(all(edges),comp);

    if(!mst())
    {
//        deb("hola");
        deb("NO");
        return 0;
    }

    for(i=1; i<=n; i++)
    {
        if(!bfs(i))
        {
//            deb("hola");
            deb("NO");
            return 0;
        }
    }

    deb("YES");

    return 0;
}