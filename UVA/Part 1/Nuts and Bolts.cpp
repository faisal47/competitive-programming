#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <math.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define ll long long
#define sz 510
using namespace std;
vector<int>v[sz];
bool color[sz];
int n,par[sz],ans,i,j,m;
bool dfs(int node)
{
    int asi;
    for(int p=0; p<v[node].size(); p++)
    {
        asi=v[node][p];
        if(color[asi]==0)
        {
            color[asi]=1;
            if(par[asi]==-1 || dfs(par[asi]))
            {
                par[asi]=node;
                return true;
            }
        }
    }
    return false;
}
int bpm()
{
    ans=0;
    for(i=0; i<n; i++)
    {
        for(j=0;j<m;j++)
        color[j]=0;
        if(dfs(i))
            ans++;
    }
    return ans;
}
int main ()
{
    bool a;
    int i,j,t=1,test;
    cin>>test;
    while(test--)
    {
        cin>>n>>m;
        for(i=0; i<n; i++)
        {
            v[i].clear();
            for(j=0; j<m; j++)
            {
                par[j]=-1;
                cin>>a;
                if(a)
                    v[i].push_back(j);
            }
        }
        printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n",t++,bpm());
    }
    return 0;
}
