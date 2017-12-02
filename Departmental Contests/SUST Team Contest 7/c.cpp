#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

vector <pair <int, int> > res;
pair <int, int> in;
vector <int> adj[110];

int par[110],n;
bool color[110];

bool rotation(int o, int a, int b)
{
    int rot = (res[a].first-res[o].first)*(res[b].second-res[o].second)-\
    (res[a].second-res[o].second)*(res[b].first-res[o].first);
    if(rot==0)
    return rot;
    return rot>0?1:2;
}
bool  call(int a, int b, int c, int d)
{
    int d1 = rotation(a, b, c);
    int d2 = rotation(a, b, d);
    int d3 = rotation(c, d, a);
    int d4 = rotation(c, d, b);
    if(d1 != d2 && d3 != d4)
        return true;
    return false;
}
bool check(int u,int c)
{
    int i;
    for(i = 0; i < 2*n; i++)
    {
        if(u==i|| i==c)
        continue;
        if(par[i] != -1)
        {
            if(call(par[i], i, u, c))
                return false;
        }
    }
    return true;
}
int dfs(int u)
{
   if(color[u]) return false;
   color[u] = 1;
   int s=0,e=n;
   if(u<n)
    s=n,e=n*2;
   for(int i = s; i < e; i++)
   {
       if(u==i)
       continue;
       if((par[i] == -1 && check(i, u)) || dfs(par[i]))
       {
           par[i] = u;
           par[u] =i;
           return true;
       }
   }
   return false;
}

void bpm()
{
    int ret = 0, i;
    memset(par, -1,sizeof par);
    for(i = 0; i <  n; i++)
    {
        memset(color, 0, sizeof color);
        dfs(i);
    }
}
int main()
{
    int i;
    cin>> n;
    for(i = 0; i < 2 * n; i++)
    {
        cin >> in.first >> in.second;
        res.push_back(in);
    }
    bpm();
    for(int i=0;i< n;i++)
        cout << par[i]-n+1<< endl;
    res.clear();
    return 0;
}
