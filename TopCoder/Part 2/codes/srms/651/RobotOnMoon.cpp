#include <bits/stdc++.h>
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
#define eps 1E-7
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define sz(a) (int)a.size()
#define ll long long
#define dd double
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
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//double dur(int x1,int y1,int x2,int y2)
//{
//    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
int X[]= {-1,0,1,0};
int Y[]= {0,1,0,-1};

#define mt
#define mod

vector <string>arr;
int n,m;

bool okay(int s,int e)
{
    return s>=0 && e>=0 && s<n && e<m && arr[s][e]=='.';
}

bool okay2(int s,int e)
{
    return s>=0 && e>=0 && s<n && e<m && arr[s][e]=='#';
}

int x,y;

int solve2(int i)
{
    int s1,e1,s,e;
    s=x;
    e=y;
    while(1)
    {
        s1=s+X[i];
        e1=e+Y[i];
        if(okay(s1,e1))
        {
            s=s1;
            e=e1;
        }
        else if(okay2(s1,e1))
        {
            return -1;
        }
        else
            break;
    }
    return 0;
}

int dist[55][55];

int solve3()
{
    ms(dist,-1);
    int s,e,i,s1,e1,ret=0;
    ret=0;
    queue<int>q;
    q.push(x);
    q.push(y);
    dist[x][y]=0;
    while(!q.empty())
    {
        s=q.front();q.pop();
        e=q.front();q.pop();
        for(i=0;i<4;i++)
        {
            s1=s+X[i];
            e1=e+Y[i];
            if(okay(s1,e1) && dist[s1][e1]==-1)
            {
                dist[s1][e1]=dist[s][e]+1;
                ret=max(ret,dist[s1][e1]);
                q.push(s1);
                q.push(e1);
            }
        }
    }
    return ret;
}

int solve()
{
    int i,j;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
        {
            if(arr[i][j]=='S')
            {
                x=i;
                y=j;
            }
        }
//    int ret=0;
    if(solve2(0) == -1)
        return -1;
    if(solve2(1) == -1)
        return -1;
    if(solve2(2) == -1)
        return -1;
    if(solve2(3) == -1)
        return -1;
    return n+m-2;
}

class RobotOnMoon
{
public:
    int longestSafeCommand(vector <string> board)
    {
        arr=board;
        n=sz(arr);
        m=sz(arr[0]);
        return solve();
    }
};
