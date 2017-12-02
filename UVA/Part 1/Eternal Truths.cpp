#include <bits/stdc++.h>
#define inf 1<<28
#define scch(a) scanf("%c",&a)
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define mt 310
using namespace std;
int X[]= {-1,0,1,0},Y[]= {0,1,0,-1},r,c,dist[mt][mt][4],s1,s2,e1,e2;
int i,a1,b1,a2,b2,a3,b3,j,k;
char arr[mt][mt];
struct data
{
    int x,y,step;
};
void bfs()
{
    queue<data>q;
    data u,v;
    u.x=s1;u.y=s2;u.step=3;dist[s1][s2][3]=0;
    q.push(u);
    while(!q.empty())
    {
        u=q.front();q.pop();
        for(i=0;i<4;i++)
        {
            a1=u.x+X[i];
            a2=u.x+X[i]*2;
            a3=u.x+X[i]*3;
            b1=u.y+Y[i];
            b2=u.y+Y[i]*2;
            b3=u.y+Y[i]*3;
            if(u.step==1)
            {
                if(arr[a2][b2]!='#' && arr[a1][b1]!='#' && dist[a2][b2][2]==-1 && a2>=0 && b2>=0 && a2<r && b2<c)
                {
                    dist[a2][b2][2]=dist[u.x][u.y][1]+1;
                    v.x=a2;
                    v.y=b2;
                    v.step=2;
                    q.push(v);
                }
            }
            else if(u.step==2)
            {
                if(arr[a2][b2]!='#' && arr[a1][b1]!='#' && arr[a3][b3]!='#' && dist[a3][b3][3]==-1 && a3>=0 && b3>=0 && a3<r && b3<c)
                {
                    dist[a3][b3][3]=dist[u.x][u.y][2]+1;
                    v.x=a3;
                    v.y=b3;
                    v.step=3;
                    q.push(v);
                }
            }
            else
            {
                if(arr[a1][b1]!='#' && dist[a1][b1][1]==-1 && a1>=0 && b1>=0 && a1<r && b1<c)
                {
                    dist[a1][b1][1]=dist[u.x][u.y][3]+1;
                    v.x=a1;
                    v.y=b1;
                    v.step=1;
                    q.push(v);
                }
            }
        }
    }
}
int main ()
{
    int t,ans;
    char z;
    sci1(t);
    while(t--)
    {
        sci2(r,c);
        sci1(z);
        for(i=0; i<r; i++)
        {
            gets(arr[i]);
            for(j=0; j<c; j++)
            {
                if(arr[i][j]=='S')
                {
                    s1=i;
                    s2=j;
                }
                if(arr[i][j]=='E')
                {
                    e1=i;
                    e2=j;
                }
                for(k=1; k<=3; k++)
                dist[i][j][k]=-1;
            }
        }
        bfs();
        ans=inf;
        if(dist[e1][e2][1]>0)
        ans=min(ans,dist[e1][e2][1]);
        if(dist[e1][e2][2]>0)
        ans=min(ans,dist[e1][e2][2]);
        if(dist[e1][e2][3]>0)
        ans=min(ans,dist[e1][e2][3]);
        if(ans==inf)
        cout<<"NO\n";
        else
        cout<<ans<<endl;
    }
    return 0;
}

