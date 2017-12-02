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
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define mp make_pair
#define pii pair<int,int>
#define fs first
#define sc second
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define sci4(a,b,c,d) scanf("%d %d %d %d",&a,&b,&c,&d)
#define sz(a) a.size()
#define mt
using namespace std;
struct data
{
   int x,y,cost;
   bool operator < (const data& p) const
   {
       return cost > p.cost;
   }
};
int X[]={1,-1,1,-1,2,2,-2,-2};
int Y[]={2,2,-2,-2,1,-1,1,-1};
int dist[10][10];
int a,b,c,d,i,e,j;
priority_queue<data>q;
data u,v;
int dj()
{
    while(!q.empty())q.pop();
    u.x=a;
    u.y=b;
    u.cost=0;
    for(i=0;i<8;i++)
    for(j=0;j<8;j++)
    dist[i][j]=inf;
    dist[a][b]=0;
    q.push(u);
    while(!q.empty())
    {
        u=q.top();q.pop();
        e=u.cost;
        for(i=0;i<8;i++)
        {
            v.x=u.x+X[i];
            v.y=u.y+Y[i];
            if(v.x>-1 && v.x<8 && v.y>-1 && v.y<8)
            {
                v.cost=e+(u.x*v.x + u.y*v.y);
              //  cout<<"x y == "<<v.x<<" "<<v.y<<" "<<v.cost<<endl;
                if(v.cost<dist[v.x][v.y])
                {
                    dist[v.x][v.y]=v.cost;
                    q.push(v);
                }
            }
        }
    }
    return dist[c][d];
}
int main ()
{
    while(sci4(a,b,c,d)==4)
    printf("%d\n",dj());
    return 0;
}

