#include <bits/stdc++.h>

#define ms(a,b) memset(a,b,sizeof(a))
#define inf (1ll << 60)
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


#define mt
#define mod

#define fop freopen("dissim.in","r",stdin);freopen("dissim.out","w",stdout);

ll arr[132][132];
char mini1[132],mini2[132];
string arr1,arr2,mst;
ll dp[2100][2100];

ll solve(ll pos1,ll pos2)
{
    if(pos1>=sz(arr1) && pos2>=sz(arr2))
        return 0;
    if(pos1>=sz(arr1))
    {
        ll ret=0,i,j,mini;
        for(i=pos2; i<sz(arr2); i++)
        {
            mini=inf;
            rep(j,sz(mst))
            mini=min(mini,arr[mst[j]][arr2[i]]);
            ret+=mini;
        }
        return ret;
    }
    if(pos2>=sz(arr2))
    {
        ll ret=0,i,j,mini;
        for(i=pos1; i<sz(arr1); i++)
        {
            mini=inf;
            rep(j,sz(mst))
            mini=min(mini,arr[arr1[i]][mst[j]]);
            ret+=mini;
        }
        return ret;
    }
    ll &ret=dp[pos1][pos2];
    if(ret != -1ll)
        return ret;
    ret=inf;
    ll i;
    ret=min(ret,solve(pos1+1,pos2+1)+arr[arr1[pos1]][arr2[pos2]]);
    rep(i,sz(mst))
    ret=min(ret,min(solve(pos1+1,pos2)+arr[arr1[pos1]][mst[i]],solve(pos1,pos2+1)+arr[mst[i]][arr2[pos2]]));
    return ret;
}

string ans1,ans2;

void solve2(ll pos1,ll pos2)
{
    if(pos1>=sz(arr1) && pos2>=sz(arr2))
        return;
    if(pos1>=sz(arr1))
    {
        ll i,j,mini;
        string temp;
        for(i=pos2; i<sz(arr2); i++)
        {
            mini=inf;
            rep(j,sz(mst))
            {
                if(mini > arr[mst[j]][arr2[i]])
                {
                    temp=mst[j];
                    mini=arr[mst[j]][arr2[i]];
                }
            }
            ans1+=temp;
        }
        ans2+=arr2.substr(pos2);
        return;
    }
     if(pos2>=sz(arr2))
    {
        ll i,j,mini;
        string temp;
        for(i=pos1; i<sz(arr1); i++)
        {
            mini=inf;
            rep(j,sz(mst))
            {
                if(mini > arr[arr2[i]][mst[j]])
                {
                    temp=mst[j];
                    mini=arr[arr2[i]][mst[j]];
                }
            }
            ans2+=temp;
        }
        ans1+=arr1.substr(pos1);
        return;
    }
    ll ret=dp[pos1][pos2];

    ll i;
    if(ret == solve(pos1+1,pos2+1)+arr[arr1[pos1]][arr2[pos2]])
    {
        ans1+=arr1[pos1];
        ans2+=arr2[pos2];
        solve2(pos1+1,pos2+1);
        return;
    }

    rep(i,sz(mst))
    {
        if(ret == solve(pos1+1,pos2)+arr[arr1[pos1]][mst[i]])
        {
            ans1+=arr1[pos1];
            ans2+=mst[i];
            solve2(pos1+1,pos2);
            return;
        }
        if(ret == solve(pos1,pos2+1)+arr[mst[i]][arr2[pos2]])
        {
            ans1+=mst[i];
            ans2+=arr2[pos2];
            solve2(pos1,pos2+1);
            return;
        }
    }
    return;
}

int main ()
{
    cffi;
    fop;
    ll i,j,test,n,t=1;
    cin>>mst>>arr1>>arr2;
    rep(i,sz(mst))
    rep(j,sz(mst))
    cin>>arr[mst[i]][mst[j]];
    /// optimization korte hobe baiaa
    ms(dp,-1ll);

    deb(solve(0,0));
    solve2(0,0);
    deb(ans1);
    deb(ans2);

    return 0;
}










