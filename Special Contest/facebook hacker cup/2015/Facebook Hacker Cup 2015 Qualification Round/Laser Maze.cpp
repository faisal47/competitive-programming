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
#define fop   freopen("3.txt","r",stdin);freopen("3output.txt","w",stdout);
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

int X[]={-1,0,1,0};
int Y[]={0,1,0,-1};

#define mt 110
#define mod

bool blocked[mt][mt][4];
int dist[mt][mt],n,m,ms1,ms2,me1,me2;
string arr[mt];

bool okay(int s,int e)
{
    return s>=0 && s<n && e>=0 && e<m && (arr[s][e]=='S' || arr[s][e]=='G' || arr[s][e]=='.');
}

void dir1(int i,int j,int ind)
{
    i--;
    while(okay(i,j))
    {
        blocked[i][j][ind]=1;
        i--;
    }
}
void dir2(int i,int j,int ind)
{
    j++;
    while(okay(i,j))
    {
        blocked[i][j][ind]=1;
        j++;
    }
}
void dir3(int i,int j,int ind)
{
    i++;
    while(okay(i,j))
    {
        blocked[i][j][ind]=1;
        i++;
    }
}
void dir4(int i,int j,int ind)
{
    j--;
    while(okay(i,j))
    {
        blocked[i][j][ind]=1;
        j--;
    }
}

void go1(int s,int e)
{
    int i,j;
    if(arr[s][e]=='^')
    {
        dir1(s,e,0);
        dir2(s,e,1);
        dir3(s,e,2);
        dir4(s,e,3);
    }
    else if(arr[s][e]=='>')
    {
        dir2(s,e,0);
        dir3(s,e,1);
        dir4(s,e,2);
        dir1(s,e,3);
    }
    else if(arr[s][e]=='v')
    {
        dir3(s,e,0);
        dir4(s,e,1);
        dir1(s,e,2);
        dir2(s,e,3);
    }
    else
    {
        dir4(s,e,0);
        dir1(s,e,1);
        dir2(s,e,2);
        dir3(s,e,3);
    }
}

void pre()
{
    ms(blocked,0);
    int i,j;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
        {
            if(arr[i][j]!='S' && arr[i][j]!='G' && arr[i][j]!='#' && arr[i][j]!='.')
                go1(i,j);
            if(arr[i][j]=='S')
            {
                ms1=i;
                ms2=j;
            }
            if(arr[i][j]=='G')
            {
                me1=i;
                me2=j;
            }
            dist[i][j]=inf;
        }
    dist[ms1][ms2]=0;
}

int bfs(int s,int e)
{
    int s1,e1,i,j,vs1,vs2,vs3,d,s2,e2;
    queue<int>q;
    q.push(s);
    q.push(e);

    while(!q.empty())
    {
        s=q.front();q.pop();
        e=q.front();q.pop();
        for(i=0;i<4;i++)
        {
            s1=s+X[i];
            e1=e+Y[i];
            if(okay(s1,e1))
            {
                d=1+dist[s][e];
                vs1=d%4;
                if(!blocked[s1][e1][vs1] && dist[s1][e1]>d)
                {
                    dist[s1][e1]=d;
                    q.push(s1);
                    q.push(e1);
                }
                d=dist[s][e];
                d++;vs1=d%4;
                d++;vs2=d%4;
                d++;vs3=d%4;
                for(j=0;j<4;j++)
                {
                    s2=s+X[j];
                    e2=e+Y[j];
                    if(okay(s2,e2) && !blocked[s2][e2][vs1] && !blocked[s][e][vs2] && !blocked[s1][e1][vs3] && dist[s1][e1]>d)
                    {
                        dist[s1][e1]=d;
                        q.push(s1);
                        q.push(e1);
                    }
                }
            }
        }
    }
    return dist[me1][me2];
}

int main ()
{
//    cffi;
    fop;
    int i,j,test,t=1,ans;
    cin>>test;
    while(test--)
    {
        cin>>n>>m;

        for(i=0; i<n; i++)
            cin>>arr[i];
        pre();
        ans=bfs(ms1,ms2);
        printf("Case #%d: ",t++);
        if(ans >= inf)
            puts("impossible");
        else
            printf("%d\n",ans);
    }
    return 0;
}


