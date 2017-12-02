
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
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
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


#define mt 52
#define mt2 10010
#define mod 21092013

ll cnt[mt],L[mt2],R[mt2],pre_gc[mt][mt],cnt2[10010][mt],dp[10010][mt];
vec_<int>adj[mt2];

void pre1()
{
    rep1(i,50)
    rep1(j,50)
    pre_gc[i][j]=__gcd(i,j);
}

void pre2(int n)
{
    rep1(i,50)
    cnt[i]=0;
    rep1(i,n)
    {
        clr(adj[i]);
        rep1(j,50)
        dp[i][j]=0,cnt2[i][j]=0;
    }
}

void pre3(int n)
{
    rep1(i,n)
    for(int j=L[i];j<=R[i];j++)
        {
            cnt[j]++;
            cnt2[i][j]++;
        }
}

void solve(int node,int par)
{
    int gc;
    repa(b,adj[node])
    {
        if(b == par)
            continue;
        solve(b,node);
        rep1(i,50)
        rep1(j,50)
        {
           gc=pre_gc[i][j];
           dp[node][gc]=(dp[node][gc] + ((cnt2[node][i]*cnt2[b][j])%mod))%mod;
        }
        for(int i=L[node];i<=R[node];i++)
        rep1(j,50)
        {
            gc=pre_gc[i][j];
            cnt2[node][gc]=(cnt2[node][gc]+cnt2[b][j])%mod;
        }
    }
}

int main ()
{
    cffi;
    pre1();
    int i,j,test,n,t=1,a,b;
    ll ans;
    cin>>test;
    while(test--)
    {
        cin>>n;
        pre2(n);
        rep1(i,n-1)
        {
            cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        rep1(i,n)
            cin>>L[i];
        rep1(i,n)
            cin>>R[i];
        cout<<"Case "<<t++<<":"<<endl;
        pre3(n);
        solve(1,-1);
        rep1(i,50)
        {
            ans=cnt[i];
            rep1(j,n)
            ans=(ans + dp[j][i])%mod;
            cout<<i<<": "<<ans<<endl;
        }
    }

    return 0;
}









