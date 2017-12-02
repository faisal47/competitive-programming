struct maan
{
  int node,cost;
  bool operator < (const maan& p) const
  {
      return cost > p.cost;
  }
};
vec_<maan>adj[mt];
int dj(int s,int e)
{
    priority_queue<maan>q;
    maan u,v;
    int d,i,j;
    u.node=s;
    u.cost=0;
    dist[u.node]=0;
    q.push(u);
    while(!q.empty())
    {
        u=q.top();q.pop();
        d=u.cost;
        for(i=0;i<sz(adj[u.node]);i++)
        {
            v.node=adj[u.node][i].node;
            v.cost=d+adj[u.node][i].cost;
            if(v.cost < dist[v.node])
            {
                dist[v.node]=v.cost;
                q.push(v);
            }
        }
    }
    return dist[e];
}
