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


#define mt 100001
#define MAX 100001
#define mod

int trie[MAX][26], cnt[MAX][2], last;
string str;
int ans;
void add(string &str,int jog)
{
    int i, id, cur = 0;
    for(i = 0; i<sz(str); i++)
    {
        id = str[i] - 'a';
        if(trie[cur][id] == -1)
        {
            trie[cur][id] = ++last;
            cnt[last][0]=cnt[last][1]=i+jog;
            ms(trie[last], -1);
        }
        cur = trie[cur][id];
        cnt[cur][0]=min(cnt[cur][0],i+jog);
        cnt[cur][1]=max(cnt[cur][1],i+jog);
    }
}

/// do clr(trie[0], -1) and last = 0 for every case

string arr;

void go(int node,int len)
{
    if(cnt[node][1]-cnt[node][0]>=len)
        ans++;
    int i,cur;
    rep(i,26)
    {
        cur=trie[node][i];
        if(cur != -1)
            go(cur,len+1);
    }
}

int main ()
{
    cffi;
    int i,j,test,n,t=1;
    while(cin>>arr)
    {
        if(arr[0]=='#')
            break;
        ans=0;
        ms(trie[0],-1);
        last=0;
        rep(i,sz(arr))
        {
            str=arr.substr(i);
            add(str,i);
        }
        go(0,0);
        deb(ans-1);
    }
//    fflush(stdout);
//    cout << flush;
    return 0;
}










