#include <bits/stdc++.h>

#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<30
#define mp make_pair
#define pi acos(-1)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define fs first
#define sc second
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define sz(a) (int)a.size()
#define ll long long
#define ull unsigned long long
#define dd double
#define rep(i,n) for(i=0;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)
#define repa(i,n) for(auto i: n)
#define fop freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
using namespace std;

template<class T1> void deb(T1 e)
{
    cout<<e<<endl;
}
template<class T1,class T2> void deb(T1 e1,T2 e2)
{
    cout<<e1<<" "<<e2<<endl;
}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3)
{
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;
}

int X[]={-1,0,1,0};
int Y[]={0,1,0,-1};


#define mt 105
#define mod

int dist[mt][mt][10];
int arr[mt][mt],n,m;
bool col[mt][mt];

queue<int>q;

void pre()
{
    int i,j,k;
    while(!q.empty())q.pop();
    rep(i,n)
    rep(j,m)
    {
        col[i][j]=0;
        rep(k,10)
        dist[i][j][k]=inf;
        arr[i][j]=0;
    }
}

string st;
int ex,ey;

bool ok(int x,int y)
{
    return x>=0 && x<n && y>=0 && y<m && ((x==ex && y==ey) || arr[x][y]>0);
}

void bfs(int sx,int sy)
{
    int i,st=0,tx,ty,tt,td,nd;
    q.push(sx);
    q.push(sy);
    q.push(st);
    col[sx][sy]=1;
    dist[sx][sy][0]=0;
    while(!q.empty())
    {
        sx=q.front();q.pop();
        sy=q.front();q.pop();
        st=q.front();q.pop();
        nd=dist[sx][sy][st];
        rep(i,4)
        {
            tx=sx+X[i];
            ty=sy+Y[i];
            if(!ok(tx,ty))
                continue;
            tt=max(st,arr[tx][ty]);
            td=arr[tx][ty]+nd;
            if(td< dist[tx][ty][tt])
            {
                dist[tx][ty][tt]=td;
                if(!col[tx][ty])
                {
                    q.push(tx);
                    q.push(ty);
                    q.push(tt);
                    col[tx][ty]=1;
                }
            }
        }
        col[sx][sy]=0;
    }
}

int main ()
{
    cffi;
    int i,j,test,t=1,sx,sy,ans,sum;
    cin>>test;
    while(test--)
    {
        cin>>n>>m;
        sum=0;
        pre();
        rep(i,n)
        {
          cin>>st;
          rep(j,m)
          {
              if(st[j]=='A')
              {
                  sx=i;
                  sy=j;
              }
              else if(st[j]=='B')
              {
                  ex=i;
                  ey=j;
              }
              else
                {
                    arr[i][j]=st[j]-'0';
                    sum+=arr[i][j];
                }
          }
        }
        bfs(sx,sy);
        ans=inf;
        rep1(i,9)
        if(dist[ex][ey][i]<inf)
        ans=min(ans,dist[ex][ey][i]-i);
        if(ans>=inf)
            ans=0;
        else
            ans=sum-ans;
        cout<<"Case #"<<t++<<": "<<ans<<endl;

    }
    return 0;
}









