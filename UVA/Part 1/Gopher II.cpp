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
#define sz
using namespace std;
int n,m,s,v1,ans,par[110];
vector<int>v[110];
bool color[110];
double dur(double x1,double x2,double y1,double y2)
{
    return sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
}
bool dfs(int i)
{
    int node,p;
    for(p=0; p<v[i].size(); p++)
    {
        node=v[i][p];
        if(color[node]==0)
        {
            color[node]=1;
            if(par[node]==-1 || dfs(par[node]))
            {
                par[node]=i;
                return true;
            }
        }
    }
    return false;
}
int bpm()
{
    int i,j;
    ans=0;
    for(i=1; i<=m; i++)
    {
       ms(color,0);
        if(dfs(i))
            ans++;
    }
    return ans;
}
int main ()
{
    int i,j;
    double arr1[110][2],arr2[110][2];
    while(cin>>n>>m>>s>>v1)
    {
        for(i=1; i<=n; i++)
            cin>>arr1[i][0]>>arr1[i][1];
        for(i=1; i<=m; i++)
        {
            v[i].clear();
            par[i]=-1;
            cin>>arr2[i][0]>>arr2[i][1];
        }
        s*=v1;
        for(i=1; i<=n; i++)
            for(j=1; j<=m; j++)
                if(dur(arr1[i][0],arr2[j][0],arr1[i][1],arr2[j][1])<s || fabs(dur(arr1[i][0],arr2[j][0],arr1[i][1],arr2[j][1])-s) < 1E-7)
                    v[j].push_back(i);
        cout<<n-bpm()<<endl;
    }
    return 0;
}
