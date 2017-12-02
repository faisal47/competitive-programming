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
#define make_flush  cout << flush; //    fflush(stdout);
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

int X[]= {0,0,1,-1};
int Y[]= {1,-1,0,0};

#define mt 1010
#define mod

string arr[mt];

int n,m;

pii s,t;
bool col[mt][mt];

bool check(int i,int j)
{
    return i>=0 && i<n && j>=0 && j<m && arr[i][j]!='*';
}

void fillup(int i,int j,int ind)
{
    while(check(i,j))
    {
        col[i][j]=1;
        i+=X[ind];
        j+=Y[ind];
    }
}

void solve1()
{
    ms(col,0);
    fillup(s.fs,s.sc,0);
    fillup(s.fs,s.sc,1);
    fillup(t.fs,t.sc,0);
    fillup(t.fs,t.sc,1);
    int c1,c2,r1,r2,i,j;
    r1=s.fs;
    r2=t.fs;
    c1=s.sc;
    c2=t.sc;
    if(c1>c2)
        swap(c1,c2);

    for(i=0; i<m; i++)
    {
        for(j=r1; j<=r2; j++)
        {
            if(j==r1 || j==r2)
            {
                if(col[j][i]!=1)
                    break;
            }
            else if(!check(j,i))
                break;
        }
        if(j>r2 && r1!=r2)
        {
            deb("YES");
                exit(0);
        }
    }
}


void solve2()
{
    ms(col,0);
    fillup(s.fs,s.sc,2);
    fillup(s.fs,s.sc,3);
    fillup(t.fs,t.sc,2);
    fillup(t.fs,t.sc,3);
    int c1,c2,r1,r2,i,j;
    r1=s.fs;
    r2=t.fs;
    c1=s.sc;
    c2=t.sc;
    if(c1>c2)
        swap(c1,c2);

    for(i=0; i<n; i++)
    {
        for(j=c1; j<=c2; j++)
        {
            if(j==c1 || j==c2)
            {
                if(col[i][j]!=1)
                    break;
            }
            else if(!check(i,j))
                break;
        }
        if(j>c2 && c1!=c2)
        {
            deb("YES");
                exit(0);
        }
    }
}



int main ()
{
    cffi;
    int i,j;
    cin>>n>>m;

    rep(i,n)
    cin>>arr[i];

    rep(i,n)
    rep(j,m)
    {
        if(arr[i][j]=='S')
            s= {i,j};
        else if(arr[i][j]=='T')
            t= {i,j};
    }

    if(s.fs > t.fs)
        swap(s,t);

    solve1();
    solve2();

    deb("NO");

    return 0;
}