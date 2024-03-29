#include <bits/stdc++.h>

#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define mp make_pair
#define pi acos(-1)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define fs first
#define sc second
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define sf scanf
#define pf printf
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
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
#define sz(a) (int)a.size()
#define ll long long
#define LL long long
#define ull unsigned long long
#define dd double
#define rep(i,n) for(i=0;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)
using namespace std;

#define fop freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

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
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};
//int X[]={1,1,2,2,-1,-1,-2,-2};//knight move//
//int Y[]={2,-2,1,-1,2,-2,1,-1};//knight move//



#define mt 105
#define mod
bool flag[45];
vec_<int>primes;
void pre()
{
    int i,j;
    primes.pb(2);
    for(i=3; i<=40; i+=2)
        if(!flag[i])
        {
            primes.pb(i);
            for(j=i; j<=40; j+=i)
                flag[j]=1;
        }
}

int arr[mt],dp[102][5000],n;

int solve(int ind,int mask)
{
    if(ind >= n)
        return 0;
    int &ret=dp[ind][mask];
    if(ret != -1)
        return ret;
    int i,t=1;
    ret=inf;
    ret=solve(ind+1,mask)+abs(t-arr[ind]);
    rep(i,12)
    if(!(mask & (1<<i)))
    {
        t=primes[i];
        while(t <= 40)
        {
            ret=min(ret,solve(ind+1,mask|(1<<i))+abs(t-arr[ind]));
            t*=primes[i];
        }
    }
    return ret;
}

vec_<int>ans;

void solve2(int ind,int mask)
{
    if(ind >= n)
        return;
    int ret=dp[ind][mask];

    int i,t=1;
    if(ret == solve(ind+1,mask)+abs(t-arr[ind]))
    {
        ans.pb(t);
        solve2(ind+1,mask);
        return;
    }
    rep(i,12)
    if(!(mask & (1<<i)))
    {
        t=primes[i];
        while(t <= 40)
        {
            if(ret == solve(ind+1,mask|(1<<i)) + abs(t-arr[ind]))
            {
                ans.pb(t);
                solve2(ind+1,mask|(1<<i));
                return;
            }
            t*=primes[i];
        }
    }
    return;
}

int main ()
{
//    cffi;
    int i,j,t=1;
    pre();
    while(cin>>n)
    {
        if(n == 0)
            break;
        rep(i,n)
        cin>>arr[i];
        ms(dp,-1);
        solve(0,0);
//        deb(solve(0,0));
        clr(ans);
        solve2(0,0);
        printf("Case #%d:",t++);
        rep(i,sz(ans))
        printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}


