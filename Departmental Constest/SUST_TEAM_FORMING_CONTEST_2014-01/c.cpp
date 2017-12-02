/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <math.h>
#include <limits.h>
#include <limits>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <set>
#include <ctime>
#include <queue>
#include <vector>
#include <map>
#include <assert.h>
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
#define eps 1E-7
#define sf scanf
#define pf printf
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
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
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
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

//double dur(int x1,int y1,int x2,int y2)
//{
//    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//}
//template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
int X[]= {-1,0,1,0};
int Y[]= {0,1,0,-1};
//int X[]={1,1,2,2,-1,-1,-2,-2};//knight move//
//int Y[]={2,-2,1,-1,2,-2,1,-1};//knight move//
/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

#define mt 110
#define mod
int aguns[mt][2],n,m;
char arr[12][12];
bool flag[12][12];
queue<int>q;

bool check(int s1,int e1)
{
    return s1>=0 && s1<n && e1>=0 && e1<m && arr[s1][e1]=='#';
}

void bfs(int s,int e)
{
    while(!q.empty())
        q.pop();

    q.push(s);
    q.push(e);

    int s1,e1,i;
    flag[s][e]=1;

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
            if(check(s1,e1) && !flag[s1][e1])
            {
//                deb(s1,e1);
                flag[s1][e1]=1;
                q.push(s1);
                q.push(e1);
            }
        }
    }
}

int dis[12][12];

int bfs2(int s,int e)
{
    while(!q.empty())
        q.pop();

    ms(flag,0);

    dis[aguns[s][0]][aguns[s][1]]=0;
    dis[aguns[e][0]][aguns[e][1]]=0;

    flag[aguns[s][0]][aguns[s][1]]=1;
    flag[aguns[e][0]][aguns[e][1]]=1;

    q.push(aguns[s][0]);
    q.push(aguns[s][1]);
    q.push(aguns[e][0]);
    q.push(aguns[e][1]);
    int i,s1,e1,t=0;

    while(!q.empty())
    {
        s=q.front();
        q.pop();
        e=q.front();
        q.pop();
        for(i=0; i<4; i++)
        {
            s1=X[i]+s;
            e1=Y[i]+e;
            if(check(s1,e1) && !flag[s1][e1])
            {
                flag[s1][e1]=1;
                q.push(s1);
                q.push(e1);
                dis[s1][e1]=dis[s][e]+1;
                t=max(t,dis[s1][e1]);
            }
        }
    }

    return t;
}

int bc;

int getp_bfs(int s,int e)
{
    while(!q.empty())
        q.pop();

    q.push(s);
    q.push(e);

    int s1,e1,i;
    flag[s][e]=1;
    bc=0;
    aguns[bc][0]=s;
    aguns[bc][1]=e;
    bc++;
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
            if(check(s1,e1) && !flag[s1][e1])
            {
                flag[s1][e1]=1;
                q.push(s1);
                q.push(e1);

                aguns[bc][0]=s1;
                aguns[bc][1]=e1;
                bc++;
            }
        }
    }

}

bool flag1[12][12];

int bfs3(int s,int e)
{
//    deb("hello",s,e);
    while(!q.empty())
        q.pop();

    ms(flag1,0);

    dis[s][e]=0;
    flag1[s][e]=1;

    q.push(s);
    q.push(e);
    int i,s1,e1,t=0;

    while(!q.empty())
    {
        s=q.front();
        q.pop();
        e=q.front();
        q.pop();
        for(i=0; i<4; i++)
        {
            s1=X[i]+s;
            e1=Y[i]+e;
            if(check(s1,e1) && !flag1[s1][e1])
            {
                flag1[s1][e1]=1;
                q.push(s1);
                q.push(e1);
                dis[s1][e1]=dis[s][e]+1;
                t=max(t,dis[s1][e1]);
            }
        }
    }
    return t;
}

int main ()
{
    int i,j,test,t=1,ans,tans;
    char z;
    scanf(" %d",&test);
    while(test--)
    {
        bc=0;
        scanf(" %d %d",&n,&m);
        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
                scch(arr[i][j]);

        ms(flag,0);

        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(!flag[i][j] && arr[i][j]=='#')
                {
//                    deb("deb ",i,j);
                    bfs(i,j);
                    bc++;
                }
                if(bc > 2)
                    break;
            }
            if(bc > 2)
                break;
        }

        if(bc>2)
        {
            printf("Case %d: -1\n",t++);
            continue;
        }

        if(bc==2)
        {
            bc=0;
            ms(flag,0);
            for(i=0; i<n; i++)
            {
                for(j=0; j<m; j++)
                {
                    if(arr[i][j]=='#' && !flag[i][j])
                    {
                        getp_bfs(i,j);
                        break;
                    }
                }
                if(bc>0)
                    break;
            }
            ans=0;
            tans=inf;

//            deb("hello bc == ",bc);

            for(i=0; i<bc; i++)
                tans=min(tans,bfs3(aguns[i][0],aguns[i][1]));

            ans=tans;
            bc=0;
            for(i=0; i<n; i++)
            {
                for(j=0; j<m; j++)
                {
                    if(arr[i][j]=='#' && !flag[i][j])
                    {
                        getp_bfs(i,j);
                        break;
                    }
                }
                if(bc>0)
                    break;
            }

            tans=inf;
            for(i=0; i<bc; i++)
                tans=min(tans,bfs3(aguns[i][0],aguns[i][1]));
            ans=max(tans,ans);

            printf("Case %d: %d\n",t++,ans);

            continue;
        }

        bc=0;
        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
                if(arr[i][j]=='#')
                {
                    aguns[bc][0]=i;
                    aguns[bc][1]=j;
                    bc++;
                }

        ans=inf;

        if(bc==0)
        {
            printf("Case %d: 0\n",t++);
            continue;
        }

        if(bc==1)
        {
            printf("Case %d: 0\n",t++);
            continue;
        }

        for(i=0; i<bc; i++)
            for(j=i+1; j<bc; j++)
                ans=min(ans,bfs2(i,j));

        printf("Case %d: %d\n",t++,ans);
    }
    return 0;
}

