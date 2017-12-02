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
#define eps 1E-7
#define sort_n(a) sort(a.begin(),a.end())
#define sort_m(a) sort(a.begin(),a.end(),comp)
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
#define pri1(a) printf("%d ",a)
#define pri2(a,b) printf("%d %d ",a,b)
#define prll1(a) printf("%I64d ",a)
#define prll2(a,b) printf("%I64d %I64d ",a,b)
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define mt
using namespace std;
//struct data //for dj()
//{
//   int node,cost;
//   bool operator < (const data& p) const
//   {
//       return cost > p.cost;
//   }
//};
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};
int main ()
{
    int n,m,arr[17][17],x,y,cnt,k=1;
    string s[17],str;
    while(cin>>n>>m)
    {
        int tot=0;

        if(n==0 && m==0 )
            break;

        for(int i=0; i<16; i++)
            for(int j=0; j<16; j++)
                arr[i][j]=0;

        for(int i=0; i<n; i++)
        {
            cin>>s[i];
            for(int j=0; j<m; j++)
                if(s[i][j]=='w')
                    x=i,y=j;
                else if(s[i][j]=='+')
                {
                    arr[i][j]=1;
                    tot++;
                }
                else if(s[i][j]=='W')
                {
                    arr[i][j]=1;
                    tot++;
                    x=i,y=j;
                    s[i][j]='w';
                }
                else if(s[i][j]=='B')
                {
                    tot++;
                    arr[i][j]=1;
                    s[i][j]='b';
                }
        }
        cin>>str;
        for(int i=0; i<str.size(); i++)
        {
            if(str[i]=='L')
            {
                if(y-2>=0 && s[x][y-1]=='b' && (s[x][y-2] == '.' || arr[x][y-2]==1))
                {
                    s[x][y-1]='w';
                    s[x][y]='.';
                    s[x][y-2]='b';
                    y--;
                }
                else if(y-1>=0 && (s[x][y-1]=='.' || arr[x][y-1]==1))
                {
                    s[x][y-1]='w';
                    s[x][y]='.';
                    y--;
                }
            }
            else if(str[i]=='R')
            {
                if(y+2<m && s[x][y+1]=='b' && (s[x][y+2]=='.' || arr[x][y+2]==1))
                {
                    s[x][y+1]='w';
                    s[x][y]='.';
                    s[x][y+2]='b';
                    y++;
                }
                else if(y+1<m && (s[x][y+1]=='.' || arr[x][y+1]==1))
                {
                    s[x][y+1]='w';
                    s[x][y]='.';
                    y++;
                }
            }
            else if(str[i]=='D')
            {
                if(x+2<n && s[x+1][y]=='b' && (s[x+2][y]=='.' || arr[x+2][y]==1))
                {
                    s[x+1][y]='w';
                    s[x][y]='.';
                    s[x+2][y]='b';
                    x++;
                }
                else if(x+1<n && (s[x+1][y]=='.' || arr[x+1][y]==1))
                {
                    s[x+1][y]='w';
                    s[x][y]='.';
                    x++;
                }
            }
            else
            {
                if(x-2>=0 && s[x-1][y]=='b' &&(s[x-2][y]=='.' || arr[x-2][y]==1))
                {
                    s[x-1][y]='w';
                    s[x][y]='.';
                    s[x-2][y]='b';
                    x--;
                }
                else if(x-1>=0 && (s[x-1][y]=='.' || arr[x-1][y]==1))
                {
                    s[x-1][y]='w';
                    s[x][y]='.';
                    x--;
                }
            }
            cnt=0;
            for(int a=0; a<n; a++)
            {
                for(int b=0; b<m; b++)
                {
                    if(arr[a][b]==1 && s[a][b]=='b')
                        cnt++;
                }
            }
            if(cnt==tot)
                break;
        }
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(arr[i][j]==1 && (s[i][j]=='w' || s[i][j]=='b'))
                    s[i][j]=toupper(s[i][j]);
                else if(arr[i][j]==1 && s[i][j]=='.')
                    s[i][j]='+';
        cnt=0;
        for(int a=0; a<n; a++)
        {
            for(int b=0; b<m; b++)
            {
                if(arr[a][b]==1 && s[a][b]=='B')
                    cnt++;
            }
        }
        if(cnt!=tot)
            cout<<"Game "<<k++<<": incomplete"<<endl;
        else
            cout<<"Game "<<k++<<": complete"<<endl;
        for(int i=0; i<n; i++)
            cout<<s[i]<<endl;
    }
    return 0;
}


