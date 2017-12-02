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

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

#define mt 110
#define mod

int par[mt];
bool col[mt];
vector <int> adj[mt];

int n,m;

bool DFS(int u)
{
    if(col[u]) return false;
    col[u]=true;
    int i,k,v;
    k = adj[u].size();
    for(i=0; i<k; i++)
    {
        v = adj[u][i];
//        if(col[v] == 0)
//        {
//            col[v] = 1;
            if(par[v] == -1 || DFS(par[v]))
            {
                par[v] = u;
                return true;
            }
//        }
    }
    return false;
}

int BPM()
{
    int i,j,ret=0;
    ms(par,-1);
    for(i=0; i<n; i++)
    {
        ms(col,0);
        if(DFS(i)) ret++;
    }
    return ret;
}

vec_<int>v1,v2;

int main ()
{
    cffi;
    int i,j;

    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>j;
        v1.pb(j);
    }


    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>j;
        v2.pb(j);
    }

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        if(abs(v1[i]-v2[j])<2)
        adj[i].pb(j);

    deb(BPM());

    return 0;
}