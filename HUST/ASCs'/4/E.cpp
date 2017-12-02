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
#define fop freopen("dvd.in","r",stdin);freopen("dvd.out","w",stdout);
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

char arr1[1010];
string arr;

vec_<pair<int,string>>adj[210];
string temp;
int num;
int dp[140][8][34][8];
void go()
{
    int c=0;
    temp='"';
    while(++c)
    {
        if(arr[c]=='"')
        {
            temp+=arr[c];
            c+=2;
            arr=arr.substr(c);
            break;
        }
        temp+=arr[c];
    }
    num=0;
    c=0;
    while(1)
    {
        if(arr[c]==' ')
        {
            c++;
            c=arr[c]-'0';
            break;
        }
        num=(num*10)+(arr[c]-'0');
        c++;
    }
    adj[num-1870].pb({c,temp});
}

int solve(int y,int cn,int mask,int pre)
{
    if(cn >=7)
        return -inf;
    if(y>=137)
        return 0;
    int &ret=dp[y][cn][mask][pre];
    if(ret != -1)
        return ret;
    ret=0;
    int ncn,nm,jog;
    ret=solve(y+1,cn,0,pre);
    int i,ii;
    rep1(i,5)
    {
        ii=i;
        ii--;
        if(mask&(1<<ii))
            continue;
        jog=0;
        ncn=cn;
        if(i != pre)
            ncn++;
        for(auto cins:adj[y])
            if(i == cins.fs)
            jog++;
        if(jog>0)
            ret=max(ret,solve(y,ncn,mask|(1<<ii),i)+jog);
    }
    return ret;
}

void solve2(int y,int cn,int mask,int pre)
{
    if(cn >=7)
        return;
    if(y>=137)
        return;
    int &ret=dp[y][cn][mask][pre];
    int ncn,nm,jog;
    int i,ii;
    if(ret == solve(y+1,cn,0,pre))
    {
        solve2(y+1,cn,0,pre);
        return;
    }
    rep1(i,5)
    {
        ii=i;
        ii--;
        if(mask&(1<<ii))
            continue;
        jog=0;
        ncn=cn;
        if(i != pre)
            ncn++;
        for(auto cins:adj[y])
            if(i == cins.fs)
            jog++;
        if(jog>0)
            {
                if(ret == solve(y,ncn,mask|(1<<ii),i)+jog)
                {
                    for(auto cins:adj[y])
                    if(i == cins.fs)
                        deb(cins.sc);
                    solve2(y,ncn,mask|(1<<ii),i);
                    return;
                }

            }
    }
    return;
}

int main ()
{
    cffi;
    fop;
    int i,j,test,n,t=1;
    char z;
    scanf(" %d%c",&n,&z);
    while(n--)
    {
        gets(arr1);
        arr=arr1;
        go();
    }
    ms(dp,-1);
    deb(solve(0,0,0,0));
    solve2(0,0,0,0);

    return 0;
}










