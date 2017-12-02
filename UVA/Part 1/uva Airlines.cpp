#include <stdio.h>
#include <iostream>
#include <map>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
bool color[105];
int par[105];
vector<int>v[350];
struct dat
{
    double lat,longi;
};
void bfs(int start,int end)
{
    queue<int>q;
    q.push(start);
    par[start]=start;
    int a,i;
    color[start]=1;
    while(!q.empty())
    {
        a=q.front();
        q.pop();
        for(i=0; i<v[a].size(); i++)
        {
            if(color[v[a][i]]==0)
            {
                par[v[a][i]]=a;
                color[v[a][i]]=1;
                q.push(v[a][i]);
            }
        }
    }
    return;
}
int main ()
{
    dat data[105];
    int n,m,q,c,i,test=0,e,f,result,app;
    double R=6378.00,pi=3.141592653589793,lat,longi,lat2,long2,lat1,long1,app1;
    string a,b;
    map<string,int>ma;
    map<string,int>::iterator it;
    while(cin>>n>>m>>q)
    {
        if(n==0&&m==0&&q==0)
            break;
        test++;
        ma.clear();
        for(i=1; i<=m; i++)
            v[i].clear();
        for(i=1; i<=n; i++)
        {
            cin>>a>>data[i].lat>>data[i].longi;
            ma[a]=i;
        }
        for(i=1; i<=m; i++)
        {
            cin>>a>>b;
            e=ma.find(a)->second;
            f=ma.find(b)->second;
            v[e].push_back(f);
        }
        if(test)
            cout<<endl;
        printf("Case #%d\n",test);
        while(q--)
        {
            memset(color,0,sizeof(color));
            cin>>a>>b;
            e=ma.find(a)->second;
            f=ma.find(b)->second;
            bfs(e,f);
            if(color[f]==0)
                printf("no route exists\n");
            else
            {
                result=0.;
                m=f;
                n=par[f];
                while(1)
                {
                    if(m==n)
                        break;
                    lat1=data[m].lat*(pi/180.0);
                    long1=data[m].longi*(pi/180.0);
                    lat2=data[n].lat*(pi/180.0);
                    long2=data[n].longi*(pi/180.0);
                    app1=R * acos( cos(lat1) * cos(lat2) * cos(long1-long2) +
                                  sin(lat1) * sin(lat2) );
                    app=(int)(app1+.5);
                    result+=app;
                    m=par[m];
                    n=par[m];
                }
                cout<<result<<" km\n";
            }
        }
    }
    return 0;
}
