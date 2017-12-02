#include <bits/stdc++.h>
#define inf 1<<30
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define make_flush  cout << flush; //    fflush(stdout);
using namespace std;

#define mt 1002
#define mod

int dp[mt][mt],n,gc;
bool visit[mt][mt];
int arr1[mt];
int arr2[mt];
bool col[mt];

vector<int>adj[mt];
vector<int>grc[mt];
queue<int>q;

void bfs(int node)
{
    while(!q.empty())q.pop();
    q.push(node);
    col[node]=1;
    gc++;
    int u;
    grc[gc].push_back(node);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(auto v:adj[u])
        {
            if(col[v])
                continue;
            col[v]=1;
            q.push(v);
            grc[gc].push_back(v);
        }
    }
}

int solve(int ind,int w)
{
    if(ind >gc)
        return 0;
    int &ret=dp[ind][w];
    bool &ret2=visit[ind][w];
    if(ret2)
        return ret;
    ret2=1;
    ret=-inf;
    int mot1,mot2;
    mot1=mot2=0;

    for(auto b:grc[ind])
    {
        mot1+=arr1[b];
        mot2+=arr2[b];
        if(arr1[b]<=w)
            ret=max(ret,arr2[b]+solve(ind+1,w-arr1[b]));
    }

    if(mot1 <= w)
        ret=max(ret,mot2+solve(ind+1,w-mot1));

    ret=max(ret,solve(ind+1,w));

    return ret;
}

int main ()
{
    cffi;
    int m,w,a,b;
    cin>>n>>m>>w;

    for(int i=1; i<=n; i++)
        cin>>arr1[i];

    for(int i=1; i<=n; i++)
        cin>>arr2[i];

    while(m--)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1; i<=n; i++)
        if(!col[i])
            bfs(i);

    cout<<solve(1,w);

    return 0;
}