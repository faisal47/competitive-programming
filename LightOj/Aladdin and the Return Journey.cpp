#include <bits/stdc++.h>

#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define mp make_pair
#define pi acos(-1)
#define pii pair<int,int>
#define fs first
#define sc second

#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back


#define sci1(a) scanf(" %d",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define sci3(a,b,c) scanf(" %d %d %d",&a,&b,&c)

#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
#define rep(i,n) for(i=0;i<n;i++)
using namespace std;

#define mt 30010

#define root 0
#define LN 16 ///log2(mt)

vector <int> adj[mt];
int arr[mt], now, arr2[mt];
int chain_no, chain_indx[mt], chain_head[mt], pos_in_arr[mt];
int depth[mt], par[mt][LN], child[mt];
int segtree[mt*4];


void build(int s, int e, int cur)
{
    if(s == e)
    {
        segtree[cur] = arr[s];
        return;
    }
    int lchild = (cur << 1), rchild = lchild | 1, m = (s + e) >> 1;
    build(s, m, lchild);
    build(m+1, e, rchild);
    segtree[cur] = segtree[lchild]+ segtree[rchild];
}

void update(int s, int e, int cur, int indx, int val)
{
    segtree[cur] += val;
    if(s == e)
        return;

    int lchild = (cur << 1), rchild = lchild | 1, m = (s + e) >> 1;
    if(indx <= m)
        update(s, m, lchild, indx, val);
    else
        update(m+1, e, rchild, indx, val);
}

int query_tree(int s, int e, int cur, int L, int R)
{
    if(s > R || e < L)
        return 0;
    if(s >= L && e <= R)
        return segtree[cur];
    int lchild = (cur << 1), rchild = lchild | 1, m = (s + e) >> 1;
    return query_tree(s, m, lchild, L, R) + query_tree(m+1, e, rchild, L, R);
}

/*
 * query_up:
 * It takes two nodes u and v, condition is that v is an ancestor of u
 * We query the chain in which u is present till chain head, then move to next chain up
 * We do that way till u and v are in the same chain, we query for that part of chain and break
 */

int query_up(int u, int v)
{
    int uchain, vchain = chain_indx[v], ans = 0;
    while(true)
    {
        uchain = chain_indx[u];
        if(uchain == vchain)
        {
            ans += query_tree(0, now-1, 1, pos_in_arr[v], pos_in_arr[u]);
            break;
        }
        ans += query_tree(0, now-1, 1, pos_in_arr[chain_head[uchain]], pos_in_arr[u]);
        u = chain_head[uchain];
        u = par[u][0];
    }
    return ans;
}

void process(int n)
{
    int h, i, lev;
    h = LN-1;

    for(lev = 1; lev <= h; lev++)
    {
        for(i = 0; i < n; i++)
        {
            if(par[i][lev - 1] != -1)
                par[i][lev] = par[par[i][lev - 1]][lev - 1];
        }
    }
}

int LCA(int high, int low)
{
    if(depth[low] < depth[high]) swap(low, high);
    int h, i, diff;
    h = LN-1;
    diff = depth[low] - depth[high];
    for(i = 0; i <= h; i++)
        if(diff & (1 << i))
            low = par[low][i];
    if(low == high) return low;
    for(i = h; i >= 0; i--)
    {
        if(par[low][i] != -1 && par[low][i] != par[high][i])
        {
            low = par[low][i];
            high = par[high][i];
        }
    }
    return par[low][0];
}

int query(int u, int v)
{
    int lca = LCA(u, v);
    return query_up(u, lca)+ query_up(v, lca)-query_tree(0, now-1, 1, pos_in_arr[lca], pos_in_arr[lca]);;
}

void change(int i, int val)
{
    int temp=val-arr2[i];
    arr2[i]=val;
    int pos = pos_in_arr[i];

    update(0, now-1, 1, pos, temp);
}

void HLD(int cur_node, int prev)
{
    if(chain_head[chain_no] == -1)
        chain_head[chain_no] = cur_node;
    chain_indx[cur_node] = chain_no;
    pos_in_arr[cur_node] = now;
    arr[now++] = arr2[cur_node];
    int schild = -1, i, v;
    for(i = 0; i < sz(adj[cur_node]); i++)
    {
        v = adj[cur_node][i];
        if(v == prev) continue;
        if(schild == -1 || child[schild] < child[v])
            schild = v;
    }
    if(schild != -1)
        HLD(schild, cur_node);
    for(i = 0; i < sz(adj[cur_node]); i++)
    {
        v = adj[cur_node][i];
        if(v == prev) continue;
        if(schild != v)
        {
            chain_no++;
            HLD(v, cur_node);
        }
    }
}

void dfs(int cur, int prev, int d)
{
    par[cur][0] = prev;
    depth[cur] = d;
    child[cur] = 1;
    for(int i = 0; i < sz(adj[cur]); i++)
    {
        int v = adj[cur][i];
        if(v == prev) continue;
        dfs(v, cur, d + 1);
        child[cur] += child[v];
    }
}

void init(int n)
{
    now = chain_no = 0;
    for(int i = 0; i < n; i++)
    {
        adj[i].clear();
        chain_head[i] = -1;
        for(int j = 0; j < LN; j++)
            par[i][j] = -1;
    }
}
int main ()
{
    int n,i,j,test,t=0,u,v,q,a;
    sci1(test);
    while(test--)
    {
        t++;
        sci1(n);
        init(n);
        for(i=0;i<n;i++)
            sci1(arr2[i]);
        for(i=1;i<n;i++)
        {
            sci2(u,v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(root, -1, 0);
        HLD(root, -1);
        build(0, now-1, 1);
        process(now);
        sci1(q);
        printf("Case %d:\n",t);
        while(q--)
        {
            sci3(a,u,v);
            if(a==0)
            printf("%d\n",query(u,v));
            else
            change(u,v);
        }
    }

    return 0;
}

