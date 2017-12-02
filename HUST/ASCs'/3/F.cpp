#include <bits/stdc++.h>

#define ms(a,b) memset(a,b,sizeof(a))
#define inf (1 << 30)
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


#define mt 2010
#define mod

#define fop freopen("dissim.in","r",stdin);freopen("dissim.out","w",stdout);

int arr[210][210];
int mini1[210],mini2[210];
map<char,int>ma;
string arr1,arr2,mst;
int dp[2005][2005];
int cum1[mt];
int cum2[mt];

void pre()
{
    int i,p1,p2;
    rep(i,sz(arr1))
    {
        p1=ma[arr1[i]];
        p2=mini1[p1];
        cum1[i]=arr[p1][p2];
    }
    for(i=sz(arr1)-2;i>=0;i--)
        cum1[i]+=cum1[i+1];
    rep(i,sz(arr2))
    {
        p2=ma[arr2[i]];
        p1=mini2[p2];
        cum2[i]=arr[p1][p2];
    }
    for(i=sz(arr2)-2;i>=0;i--)
        cum2[i]+=cum2[i+1];

}

int solve(int pos1,int pos2)
{
    if(pos1>=sz(arr1) && pos2>=sz(arr2))
        return 0;
    if(pos1>=sz(arr1))
    return cum2[pos2];

    if(pos2>=sz(arr2))
    return cum1[pos1];

    int &ret=dp[pos1][pos2];
    if(ret != -1)
        return ret;
    ret=inf;
    int p1=ma[arr1[pos1]];
    int p2=ma[arr2[pos2]];
    ret=min(ret,solve(pos1+1,pos2+1)+arr[p1][p2]);

    p2=mini1[p1];
    ret=min(ret,solve(pos1+1,pos2)+arr[p1][p2]);

    p2=ma[arr2[pos2]];
    p1=mini2[p2];
    ret=min(ret,solve(pos1,pos2+1)+arr[p1][p2]);

    return ret;
}

string ans1,ans2;

void solve2(int pos1,int pos2)
{
    if(pos1>=sz(arr1) && pos2>=sz(arr2))
        return;
    if(pos1>=sz(arr1))
    {
        int ret=0,i;
        int p2;
        int p1;
        for(i=pos2; i<sz(arr2); i++)
        {
            p2=ma[arr2[i]];
            p1=mini2[p2];
            ans1+=mst[mini2[p2]];
            ans2+=arr2[i];
        }
        return;
    }
    if(pos2>=sz(arr2))
    {
        int ret=0,i,p2,p1;
        for(i=pos1; i<sz(arr1); i++)
        {
            p1=ma[arr1[i]];
            p2=mini1[p1];
            ans1+=arr1[i];
            ans2+=mst[mini1[p1]];
        }
        return;
    }
    int ret=dp[pos1][pos2];

    int p1=ma[arr1[pos1]];
    int p2=ma[arr2[pos2]];
    if(ret == solve(pos1+1,pos2+1)+arr[p1][p2])
    {
        ans1+=arr1[pos1];
        ans2+=arr2[pos2];
        solve2(pos1+1,pos2+1);
        return;
    }

    p2=mini1[p1];

    if(ret == solve(pos1+1,pos2)+arr[p1][p2])
    {
        ans1+=arr1[pos1];
        ans2+=mst[mini1[p1]];
        solve2(pos1+1,pos2);
        return;
    }
    p2=ma[arr2[pos2]];
    p1=mini2[p2];
    ans1+=mst[mini2[p2]];
    ans2+=arr2[pos2];
    solve2(pos1,pos2+1);
}


int main ()
{
    cffi;
    fop;
    int i,j;
    cin>>mst>>arr1>>arr2;
    rep(i,sz(mst))
    ma[mst[i]]=i;
    rep(i,sz(mst))
    rep(j,sz(mst))
    cin>>arr[i][j];
    ms(dp,-1);
    int mini;
    rep(i,sz(mst))
    {
        mini=inf;
        rep(j,sz(mst))
        if(mini > arr[i][j])
        {
            mini1[i]=j;
            mini=arr[i][j];
        }
//        deb(mini1[mst[i]]);
    }

    rep(j,sz(mst))
    {
        mini=inf;
        rep(i,sz(mst))
        {
            if(mini > arr[i][j])
            {
                mini2[j]=i;
                mini=arr[i][j];
            }
        }
//        deb(mini2[mst[j]]);
    }
    pre();
    deb(solve(0,0));
    solve2(0,0);
    deb(ans1);
    deb(ans2);

    return 0;
}










