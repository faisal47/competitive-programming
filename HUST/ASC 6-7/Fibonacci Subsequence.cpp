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
#define fop freopen("fibsubseq.in","r",stdin);freopen("fibsubseq.out","w",stdout);
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


#define mt 3002
#define mod

int dp[mt][mt],n,arr[mt];
map<int,int>ma;
set<int>ss[3010];

int solve(int pre1,int pre2)
{
    int &ret=dp[pre1][pre2];
    if(ret != -1)
        return ret;
    ret=0;
    ll tval=arr[pre1]+arr[pre2];
    if(tval > 1e9 || ma.find((int)tval)==ma.end())
        return ret;
    int mav=ma[(int)tval];
    if(ss[mav].upper_bound(pre2)==ss[mav].end())
        return ret;
    ret=max(ret,1+solve(pre2,*ss[mav].upper_bound(pre2)));
    return ret;
}

vec_<int>ans_arr;


void solve2(int pre1,int pre2)
{
    int ret=dp[pre1][pre2];
    ll tval=arr[pre1]+arr[pre2];
    if(abs(tval) > 1e9 || ma.find((int)tval)==ma.end())
        return;
    int mav=ma[(int)tval];
    if(ss[mav].upper_bound(pre2)==ss[mav].end())
        return;
    if(1+solve(pre2,*ss[mav].upper_bound(pre2)) == ret)
    {
        ans_arr.pb(arr[*ss[mav].upper_bound(pre2)]);
        solve2(pre2,*ss[mav].upper_bound(pre2));
    }
    return;
}

int main ()
{
    cffi;
    fop;
    int i,j,test,t=1;
    cin>>n;
    rep1(i,n)
    {
        cin>>arr[i];
        if(ma.find(arr[i])==ma.end())
            ma[arr[i]]=i;
        ss[ma[arr[i]]].insert(i);
    }
    if(n==1)
    {
        deb(1);
        deb(arr[1]);
        return 0;
    }
    rep(i,n+1)
    rep(j,n+1)
    dp[i][j]=-1;
    int ans=2;

    rep1(i,n)
    for(j=i+1; j<=n; j++)
        ans=max(ans,2+solve(i,j));
    rep1(i,n)
    {
        for(j=i+1; j<=n; j++)
            if(ans == 2+solve(i,j))
            {
                ans_arr.pb(arr[i]);
                ans_arr.pb(arr[j]);
                solve2(i,j);
                break;
            }
        if(j<=n)
            break;
    }
    deb(ans);
    repa(b,ans_arr)
    cout<<b<<" ";

    return 0;
}










