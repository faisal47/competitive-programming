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
#define sz 40
using namespace std;
int par[sz];
int test,i,j,n,m,k,ans;
vector<int>v[sz];
bool color[sz];
bool dfs(int node)
{
    int p,u;
    for(p=0; p<v[node].size(); p++)
    {
        u=v[node][p];
        if(color[u]==0)
        {
            color[u]=1;
            if(par[u]==-1 || dfs(par[u]))
            {
                par[u]=node;
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
        for(j=0; j<m; j++)
            color[j]=0;
        if(dfs(i))
            ans++;
    }
    return ans;
}
int main ()
{
    string a[]= {"XXL","XL","L","M","S","XS"},b,c;
    cin>>test;
    while(test--)
    {
        cin>>n>>m;
        for(i=0; i<n; i++)
        {
            v[i].clear();
        }
        for(i=0; i<m; i++)
        {
            par[i]=-1;
            cin>>b>>c;
            for(j=0; j<6; j++)
            {
                if(b==a[j])
                {
                    for(k=j; k<n; k+=6)
                        v[k].push_back(i);
                }
                else if(c==a[j])
                {
                    for(k=j; k<n; k+=6)
                        v[k].push_back(i);
                }
            }
        }
        if(bpm()>=m)
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }
    return 0;
}
