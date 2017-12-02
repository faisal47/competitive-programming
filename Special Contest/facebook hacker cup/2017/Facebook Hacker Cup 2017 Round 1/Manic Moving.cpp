#include <bits/stdc++.h>


#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1ll << 50
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
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
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
//template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll B,ll P,ll M){ll R=1;while(P>0){if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}return R;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};


#define mt 103
#define mod

int n,k;
ll dist[mt][mt],dp[5003][2][2];
pii arr[5003];

void pre()
{
    rep1(i,n)
    rep1(j,n)
    if(i==j)
        dist[i][j]=0;
    else
        dist[i][j]=inf;
    ms(dp,-1);
}

void fw()
{
    rep1(k,n)
    rep1(i,n)
    rep1(j,n)
    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}

ll solve(int asi,bool pos,bool ea)
{
    if(asi==k && pos==1)
        return 0;

    ll &ret=dp[asi][pos][ea];
    if(ret != -1)
        return ret;
    ret=inf;
    int asin;
    int jabon1;
    int jabon2;
    if(pos == 0)
    {
        asin=arr[asi].fs;
        /// ekhon she ache shurute
        if(ea==0)
        {
            if(asi+1 <= k)
            {
                jabon1=arr[asi+1].fs;
                jabon2=arr[asi].sc;
                if(dist[asin][jabon1]<inf && dist[jabon1][jabon2]<inf)
                    ret=min(ret,solve(asi,1,1) + dist[asin][jabon1] + dist[jabon1][jabon2]);
            }
        }
        jabon1=arr[asi].sc;
        if(dist[asin][jabon1]<inf)
            ret=min(ret,solve(asi,1,ea)+dist[asin][jabon1]);
    }
    else
    {
        /// ekhon she ache sheshe
        asin=arr[asi].sc;
        if(ea ==1)
        {
            asi++;
            jabon1=arr[asi].sc;
            if(dist[asin][jabon1] < inf)
                ret=min(ret,solve(asi,1,0)+dist[asin][jabon1]);
            if(asi+1 <=k)
            {
                jabon1=arr[asi+1].fs;
                jabon2=arr[asi].sc;
                if(dist[asin][jabon1]<inf && dist[jabon1][jabon2]<inf)
                    ret=min(ret,solve(asi,1,1) + dist[asin][jabon1] + dist[jabon1][jabon2]);
            }
        }
        else
        {
            jabon1=arr[asi+1].fs;
            if(dist[asin][jabon1] < inf)
                ret=min(ret,solve(asi+1,0,0)+dist[asin][jabon1]);
        }

    }
    return ret;
}

#define fop freopen("Manic Movinginput.txt","r",stdin);freopen("Manic Movingoutput.txt","w",stdout);

int main ()
{
//    cffi;
    fop;
    int i,j,test,t=1,m,a,b;
    ll c;
    cin>>test;
    while(test--)
    {
        cin>>n>>m>>k;
        pre();
        while(m--)
        {
            cin>>a>>b>>c;
            if(dist[a][b] > c)
                dist[a][b]=dist[b][a]=c;
        }
        rep1(i,k)
        cin>>arr[i].fs>>arr[i].sc;
        fw();
        ll ans=inf;
        if(dist[1][arr[1].fs]<inf)
            ans=solve(1,0,0)+dist[1][arr[1].fs];
        if(ans >= inf)
            ans=-1;
        printf("Case #%d: %I64d\n",t++,ans);
    }
    return 0;
}










