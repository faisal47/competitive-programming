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
#define sf scanf
#define pf printf
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);
#define scch(a) scanf(" %c",&a)
#define scll1(a) scanf(" %I64d",&a)
#define scll2(a,b) scanf(" %I64d %I64d",&a,&b)
#define scll3(a,b,c) scanf(" %I64d %I64d %I64d",&a,&b,&c)
#define sci1(a) scanf(" %d",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define sci3(a,b,c) scanf(" %d %d %d",&a,&b,&c)
#define scd1(a) scanf(" %lf",&a)
#define scd2(a,b) scanf(" %lf %lf",&a,&b)
#define scd3(a,b,c) scanf(" %lf %lf %lf",&a,&b,&c)
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


//double dur(int x1,int y1,int x2,int y2)
//{
//    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//}
//template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll B,ll P,ll M){ll R=1;while(P>0){if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}return R;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
int X[]= {-1,0,1,0};
int Y[]= {0,1,0,-1};
//int X[]={1,1,2,2,-1,-1,-2,-2};//knight move//
//int Y[]={2,-2,1,-1,2,-2,1,-1};//knight move//

#define mt 1010
#define mod

int arr[mt][mt],n,m;
int arr2[1000010];
int col[mt][mt],nc;

bool okay(int s,int e)
{
    return s>=0 && e>=0 && s<n && e<m && arr[s][e]==nc;
}

bool bfs1(int s,int e)
{
    nc=arr[s][e];
    queue<int>q;
    q.push(-1);
    q.push(-1);
    col[s][e]=1;
    q.push(s);
    q.push(e);
    int s1,e1,i,p1,p2;
    while(!q.empty())
    {
        p1=q.front();
        q.pop();
        p2=q.front();
        q.pop();
        s=q.front();
        q.pop();
        e=q.front();
        q.pop();
        for(i=0; i<4; i++)
        {
            s1=s+X[i];
            e1=e+Y[i];
            if(okay(s1,e1) && !col[s1][e1])
            {
                col[s1][e1]=1;
                q.push(s);
                q.push(e);
                q.push(s1);
                q.push(e1);
            }
            else if(okay(s1,e1) && col[s1][e1] && s1!=p1 && e1!=p2)
                return 1;
        }
    }
    return 0;
}

int dist[mt][mt],s2,e2;

int bfs2(int s,int e,int colt)
{
    nc=arr[s][e];
    queue<int>q;
    q.push(s);
    q.push(e);
    dist[s][e]=1;
    int s1,e1,i;
    col[s][e]=colt;
    int ret=1;
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        e=q.front();
        q.pop();
        for(i=0; i<4; i++)
        {
            s1=s+X[i];
            e1=e+Y[i];
            if(okay(s1,e1) && col[s1][e1]!=colt)
            {
                col[s1][e1]=colt;
                s2=s1;
                e2=e1;
                ret=dist[s1][e1]=1+dist[s][e];

                q.push(s1);
                q.push(e1);

            }
        }
    }
    return ret;
}

int main ()
{
//    cffi;
    int i,j;
    ms(col,0);
    sci2(n,m);

    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
        {
            sci1(arr[i][j]);
            arr2[arr[i][j]]++;
        }

    int ans=0;

    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
        {
            if(!col[i][j])
                if(bfs1(i,j))
                    ans=max(ans,arr2[arr[i][j]]);
        }
    ms(col,0);
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
        {
            if(!col[i][j])
            {
                bfs2(i,j,1);
                ans=max(ans,bfs2(s2,e2,2));
            }
        }
    printf("%d\n",ans);
    return 0;
}


