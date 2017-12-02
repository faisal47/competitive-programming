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
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define scch(a) scanf(" %c",&a)
#define sci1(a) scanf(" %d",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define sz(a) a.size()
#define mt 210
using namespace std;
int X[]= {-1,0,1,0};
int Y[]= {0,1,0,-1};
int n,m,i,j;
char arr[mt][mt];
int dist[mt][mt];
int flag[mt][mt];
queue<int>q;
int s,e,s1,e1;
bool valid(int x,int y)
{
    return x>=1 && y>=1 && x<=n && y<=m && arr[x][y]!='#';
}
bool side(int x,int y)
{
    return x==1 || y==1 || x==n || y==m;
}
int bfs()
{
    q.push(s);
    q.push(e);
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        e=q.front();
        q.pop();
        if(flag[s][e]==2 && arr[s][e]!='J')
        {
            for(i=0; i<4; i++)
            {
                s1=s+X[i];
                e1=e+Y[i];
                if(valid(s1,e1) && flag[s1][e1]!=2)
                {
                    flag[s1][e1]=2;
                    q.push(s1);
                    q.push(e1);
                }
            }
        }
        else if(arr[s][e]=='J')
        {
            arr[s][e]='.';
            for(i=0; i<4; i++)
            {
                s1=s+X[i];
                e1=e+Y[i];
                if(valid(s1,e1) && !flag[s1][e1] && arr[s1][e1]=='.')
                {
                    //cout<<"s1== e1== "<<s1<<" "<<e1<<endl;
                    flag[s1][e1]=1;
                    arr[s1][e1]='J';
                    q.push(s1);
                    q.push(e1);
                    dist[s1][e1]=dist[s][e]+1;
                    if(side(s1,e1))return dist[s1][e1];
                }
            }
        }
    }
    return -1;
}
int main ()
{
    int test,t=1,ans;
    sci1(test);
    while(test--)
    {
        sci2(n,m);
        while(!q.empty())q.pop();
        for(i=1; i<=n; i++)
            for(j=1; j<=m; j++)
            {
                scch(arr[i][j]);
                flag[i][j]=0;
                if(arr[i][j]=='F')
                {
                    flag[i][j]=2;
                    q.push(i);
                    q.push(j);
                }
                else if(arr[i][j]=='J')
                {
                    dist[i][j]=0;
                    flag[i][j]=1;
                    s=i;
                    e=j;
                }
            }
        ans=bfs();
        printf("Case %d: ",t++);
        if(ans==-1)
            cout<<"IMPOSSIBLE\n";
        else
            printf("%d\n",ans+1);
    }
    return 0;
}

