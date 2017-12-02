#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sz 1010
using namespace std;
vec_<int>v[sz];
int flag[sz],flag_main,jaite_pare[sz];
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    int i,j;
    jaite_pare[s]++;
    flag[s]=flag_main;
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        for(i=0; i<v[s].size(); i++)
        {
            j=v[s][i];
            if(flag[j]!=flag_main)
            {
                jaite_pare[j]++;
                flag[j]=flag_main;
                q.push(j);
            }
        }
    }
}
int main ()
{
    int i,j,arr[110],n,test,t=1,m,k,ans;
    sci1(test);
    while(test--)
    {
        ans=0;
        sci3(k,n,m);
        for(i=0; i<k; i++)
            sci1(arr[i]);
        for(i=1; i<=n; i++)
        {
            jaite_pare[i]=0;
            flag[i]=0;
            clr(v[i]);
        }
        while(m--)
        {
            sci2(i,j);
            v[i].pb(j);
        }
        flag_main=0;
        for(i=0; i<k; i++)
        {
            flag_main++;
            bfs(arr[i]);
        }
        for(i=1; i<=n; i++)
            if(jaite_pare[i]==k)
                ans++;
        printf("Case %d: %d\n",t++,ans);
    }
    return 0;
}

