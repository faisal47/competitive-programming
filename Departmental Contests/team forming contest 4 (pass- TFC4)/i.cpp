#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <utility>
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define sort_n(a) sort(a.begin(),a.end())
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sz(a) a.size()
#define mt 110
using namespace std;
struct data
{
    int v;
    data(){}
    data(int v):v(v){}
    bool operator < (const data &x)const
    {
        return v > x.v;
    }
};
vec_<int>adj[mt],res;
int main ()
{
    int n,m,i,ind[mt],u,v,p;
    priority_queue<data>q;
    while(sci2(n,m)==2)
    {
        clr(res);
        for(i=1;i<=n;i++)
        {
            ind[i]=0;
            clr(adj[i]);
        }
        while(m--)
        {
            sci2(v,p);
            while(p--)
            {
                sci1(u);
                adj[u].pb(v);
                ind[v]++;
            }
        }
        while(!q.empty())q.pop();
        for(i=1;i<=n;i++)
        {
            sort_n(adj[i]);
            if(!ind[i])q.push(i);
        }
        while(!q.empty())
        {
            u=q.top().v;
            q.pop();
            res.pb(u);
            for(i=0;i<sz(adj[u]);i++)
            {
                v=adj[u][i];
                ind[v]--;
                if(!ind[v])q.push(v);
            }
        }
        for(i=0;i<sz(res);i++)
        {
            if(i)cout<<" ";
            cout<<res[i];
        }
        cout<<endl;
    }
    return 0;
}
