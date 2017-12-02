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


#define mt 1010
#define mod

int dp[mt];

int solve(int num)
{
    if(num<=0)
        return 0;
    int &ret=dp[num];
    if(ret != -1)
        return ret;
    int i,l,r;
    ret=0;
    set<int>ss;
    rep1(i,num)
    {
        l=i-2;
        r=i+2;
        ss.insert(solve(l-1+1)^solve(num-r+1));
    }
    for(i=0;; i++)
        if(ss.find(i) == ss.end())
        {
            ret=i;
            break;
        }
    return ret;
}


vec_<int>arr[15];

void pre()
{
    int i,j;
    rep(i,1000)
    arr[solve(i)].pb(i);
    rep(i,10)
    {
        deb(i);
        if(sz(arr[i]))
        deb(arr[i][0]);
        rep1(j,sz(arr[i])-1)
        cout<<arr[i][j]-arr[i][j-1]<<" ";
        cout<<endl;
    }
}

int main ()
{
    cffi;
//    fop;
    int i,j,test,n,t=1;
    ms(dp,-1);
//    pre();
    cin>>test;
    while(test--)
    {
        cin>>n;
        if(n>=200)
        {
            n%=34;
            n+=102;
        }
        if(solve(n))
            cout<<"Case #"<<t++<<": "<<"UDIN"<<endl;
        else
            cout<<"Case #"<<t++<<": "<<"UCOK"<<endl;
    }
    return 0;
}










