#include <bits/stdc++.h>

#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<30
#define mp make_pair
#define pi acos(-1)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define fs first
#define sc second
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define sz(a) (int)a.size()
#define ll long long
#define ull unsigned long long
#define dd double
#define rep(i,n) for(i=0;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)
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




#define mt 65
#define mod

#define fop freopen("roads.in","r",stdin);freopen("roads.out","w",stdout);

int arr[mt][mt],en[mt][mt];
vec_<int>adj[mt];

struct maan
{
    int a,b,c;
};
vec_<maan>edges;

int par_path[mt];
queue<int>q;
bool col[mt];
void go(int s)
{
    while(!q.empty())q.pop();
    q.push(s);
    ms(col,0);
    ms(par_path,0);
    col[s]=1;
    int u;
    while(!q.empty())
    {
        u=q.front();q.pop();
        for(auto v: adj[u])
        {
            if(!col[v])
            {
                q.push(v);
                col[v]=1;
                par_path[v]=u;
            }
        }
    }
}


typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<int> VI;

VVD cost(410,vector<dd>(410));
VI L,R;
void pre(int m)
{
    cost.resize(m,vector<dd>(m));
}
int MinCostMatching(const VVD &cost, VI &Lmate, VI &Rmate) {
  int n = int(cost.size());
  // construct dual feasible solution
  VD u(n);
  VD v(n);
  for (int i = 0; i < n; i++) {
    u[i] = cost[i][0];
    for (int j = 1; j < n; j++) u[i] = min(u[i], cost[i][j]);
  }
  for (int j = 0; j < n; j++) {
    v[j] = cost[0][j] - u[0];
    for (int i = 1; i < n; i++) v[j] = min(v[j], cost[i][j] - u[i]);
  }

  // construct primal solution satisfying complementary slackness
  Lmate = VI(n, -1);
  Rmate = VI(n, -1);
  int mated = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (Rmate[j] != -1) continue;
      if (fabs(cost[i][j] - u[i] - v[j]) < 1e-10) {
	Lmate[i] = j;
	Rmate[j] = i;
	mated++;
	break;
      }
    }
  }

  VD dist(n);
  VI dad(n);
  VI seen(n);

  // repeat until primal solution is feasible
  while (mated < n) {

    // find an unmatched left node
    int s = 0;
    while (Lmate[s] != -1) s++;

    // initialize Dijkstra
    fill(dad.begin(), dad.end(), -1);
    fill(seen.begin(), seen.end(), 0);
    for (int k = 0; k < n; k++)
      dist[k] = cost[s][k] - u[s] - v[k];

    int j = 0;
    while (true) {

      // find closest
      j = -1;
      for (int k = 0; k < n; k++) {
	if (seen[k]) continue;
	if (j == -1 || dist[k] < dist[j]) j = k;
      }
      seen[j] = 1;

      // termination condition
      if (Rmate[j] == -1) break;

      // relax neighbors
      const int i = Rmate[j];
      for (int k = 0; k < n; k++) {
	if (seen[k]) continue;
	const int new_dist = dist[j] + cost[i][k] - u[i] - v[k];
	if (dist[k] > new_dist) {
	  dist[k] = new_dist;
	  dad[k] = j;
	}
      }
    }

    // update dual variables
    for (int k = 0; k < n; k++) {
      if (k == j || !seen[k]) continue;
      const int i = Rmate[k];
      v[k] += dist[k] - dist[j];
      u[i] -= dist[k] - dist[j];
    }
    u[s] += dist[j];

    // augment along path
    while (dad[j] >= 0) {
      const int d = dad[j];
      Rmate[j] = Rmate[d];
      Lmate[Rmate[j]] = j;
      j = d;
    }
    Rmate[j] = s;
    Lmate[s] = j;

    mated++;
  }

  int value = 0;
  for (int i = 0; i < n; i++)
    value += cost[i][Lmate[i]];

  return value;
}
int endh,nc,nn;

void go2(int node)
{
    if(node == endh)
        return;
    int u=par_path[node];
    if(arr[u][node] > nc)
        {
//            deb(en[u][node],nn);
//            deb(nc-arr[u][node]);
//            deb(cost[en[u][node]][nn]);
            cost[en[u][node]][nn]=min(cost[en[u][node]][nn],(dd)(nc-arr[u][node]));
//            deb(cost[en[u][node]][nn]);
        }
    go2(u);
}

int main ()
{
    cffi;
    fop;
    int i,j,test,n,t=1,m,a,b,c;
    cin>>n>>m;
    pre(m);
//    rep(i,m)
//    rep(j,m)
//    cost[i][j]=10000;
    rep(i,m)
    {
        cin>>a>>b>>c;
        if(i<n-1)
        {
            adj[a].pb(b);
            adj[b].pb(a);
            en[a][b]=en[b][a]=i;
            arr[a][b]=arr[b][a]=c;
        }

        edges.pb({a,b,c});
    }

    for(i=n-1;i<m;i++)
    {
        go(edges[i].a);
        nc=edges[i].c;
        nn=i;
        go2(edges[i].b);
    }

    MinCostMatching(cost,L,R);


    rep(i,n-1)
    if(L[i]>=n-1 && cost[i][L[i]] < 0)
        {
//            deb("hola ",L[i]);
            int half=cost[i][L[i]]/2;
            edges[L[i]].c-=(cost[i][L[i]]-half);
            edges[i].c+=half;
        }
//    deb(i,L[i]);

    rep(i,m)
    deb(edges[i].c);

    return 0;
}










