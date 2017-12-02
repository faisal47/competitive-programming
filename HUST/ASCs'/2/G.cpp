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
using namespace std;

template<class T1> void deb(T1 e)
{
    cout<<e<<" ";
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

#define fop freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int arr[mt],arr2[mt];
int dp[mt][10005],m,y,n;

int solve(int i,int baki)
{
    if(i > n)
    {
        if(baki > 0)
            return inf;
        return 0;
    }

    int &ret=dp[i][baki];
    if(ret != -1)
        return ret;
    ret=solve(i+1,baki)+abs(arr[i] * y - arr2[i]*m);
    if(baki > 0)
        ret=min(ret,solve(i+1,baki-1)+abs((arr[i]+1) * y - arr2[i]*m));

    return ret;
}

void solve2(int i,int baki)
{
    if(i > n)
        return;
    int &ret=dp[i][baki];
    int ret1,ret2=inf;
    ret1=solve(i+1,baki)+abs(arr[i] * y - arr2[i]*m);
    if(baki > 0)
        ret2=solve(i+1,baki-1)+abs((arr[i]+1) * y - arr2[i]*m);
    if(ret == ret1)
    {
        deb(arr[i]);
        solve2(i+1,baki);
        return;
    }
    deb(arr[i]+1);
    solve2(i+1,baki-1);
    return;
}

int main ()
{
    cffi;
    fop;
    int i,j;

    cin>>n>>m>>y;
    rep1(i,n)
    {
        cin>>arr2[i];
        arr[i]=arr2[i] *m /y ;
    }
    int baki=0;
    rep1(i,n)
    baki+=arr[i];
    baki=m-baki;
    ms(dp,-1);
    solve(1,baki);
    solve2(1,baki);

    return 0;
}










