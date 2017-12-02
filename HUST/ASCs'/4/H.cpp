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

int X[]= {-1,0,1,0};
int Y[]= {0,1,0,-1};


#define mt 810
#define mod

#define fop freopen("straight.in","r",stdin);freopen("straight.out","w",stdout);

char arr[mt][mt];
int n,m;

int dist2[mt][mt];

queue<int>q;

void pre2()
{
    int i,j;
    rep(i,n)
    rep(j,m)
    dist2[i][j]=inf;
    dist2[0][m-1]=0;
}

bool okay2(int x,int y)
{
    return x>=0 && y>=0 && x<n && y<m && arr[x][y]!=' ';
}

string ans;

void bfs2()
{
    pre2();
    int x,y,i,u,v;
    q.push(0);
    q.push(m-1);
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        y=q.front();
        q.pop();
        rep(i,4)
        {
            u=X[i]+x;
            v=Y[i]+y;
            if(!okay2(u,v))
                continue;
            if(dist2[u][v] > dist2[x][y]+1)
            {
                dist2[u][v] = dist2[x][y]+1;
//                deb(u,v,dist2[u][v]);
                q.push(u);
                q.push(v);
            }
        }
    }
}

void go()
{
    int i;
    int x,y,nd,u,v,nds=0,dif;
    x=n-1,y=0,nd=-1;
    bool paisi;
    while(1)
    {
        if(x==0 && y==m-1)
            break;
        paisi=0;
        rep(i,4)
        {
            if(i==nd)
            {
                u=X[i]+x;
                v=Y[i]+y;
                if(!okay2(u,v))
                    break;
                if(dist2[u][v]+1+nds == dist2[n-1][0])
                {
//                    deb("hola");
                    nds++;
                    paisi=1;
                    if(arr[x][y] == '+')
                        ans+='F';
                    x=u;
                    y=v;
                }
            }
        }
        if(paisi)
            continue;
        rep(i,4)
        {
            u=X[i]+x;
            v=Y[i]+y;
            if(!okay2(u,v))
                continue;
            if(dist2[u][v]+1+nds == dist2[n-1][0])
            {
//                deb("hola");
                if(sz(ans) ==0)
                {
                    if(i ==0)
                        ans+='N';
                    else
                        ans+='E';
                }
                nds++;
                if(arr[x][y] == '+')
                {
                    if(nd !=-1)
                    {
                        dif=nd-i;
                        if(dif == 1 || dif==-3)
                            ans+='L';
                        else
                            ans+='R';
                    }
                }
                x=u;
                y=v;
                nd=i;
                break;
            }
        }
    }
}


int main ()
{
    cffi;
    fop;
    int i,j,test,t=1;
    char z;
    scanf(" %d %d%c",&n,&m,&z);
    n=2*n-1;
    m=2*m-1;
    rep(i,n)
    gets(arr[i]);
    bfs2();
    go();

    deb(ans[0]);
    deb(ans.substr(1));

    return 0;
}










