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
#define SZ(a) (int)a.size()
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



#define mt
#define MAX 100010
#define mod 1000000007

string text;
int revSA[MAX],SA[MAX];
int cnt[MAX] , nxt[MAX];
bool bh[MAX],b2h[MAX];
int lcp[MAX];
bool cmp(int i,int j)
{
    return text[i]<text[j];
}
void sortFirstChar(int n)
{
/// sort for the first char ...
    for(int i =0 ; i<n ; i++)
        SA[i] = i;
    sort(SA,SA+n ,cmp);
///indentify the bucket ........
    for(int i=0 ; i<n ; i++)
    {
        bh[i] = (i==0 || text[SA[i]]!=text[SA[i-1]]);
        b2h[i] = false;
    }
}
int CountBucket(int n)
{
    int bucket = 0;
    for(int i =0 ,j; i<n ; i=j)
    {
        j = i+1;
        while(j<n && bh[j]==false) j++;
        nxt[i] = j;
        bucket++;
    }
    return bucket;
}
void SetRank(int n)
{
    for(int i = 0 ; i<n ; i=nxt[i])
    {
        cnt[i] = 0;
        for(int j =i ; j<nxt[i] ; j++)
        {
            revSA[SA[j]] = i;
        }
    }
}
void findNewRank(int l,int r,int step)
{
    for(int j = l ; j<r ; j++)
    {
        int pre = SA[j] - step;
        if(pre>=0)
        {
            int head = revSA[pre];
            revSA[pre] = head+cnt[head]++;
            b2h[revSA[pre]] = true;
        }
    }
}
void findNewBucket(int l,int r,int step)
{
    for(int j = l ; j<r ; j++)
    {
        int pre = SA[j] - step;
        if(pre>=0 && b2h[revSA[pre]])
        {
            for(int k = revSA[pre]+1 ; b2h[k] && !bh[k] ; k++) b2h[k] = false;
        }
    }
}
void buildSA(int n)
{
///start sorting in logn step ...
    sortFirstChar(n);
    for(int h =1 ; h<n ; h<<=1)
    {
        if(CountBucket(n)==n) break;
        SetRank(n);
/// cause n-h suffix must be sorted
        b2h[revSA[n-h]] = true;
        cnt[revSA[n-h]]++;
        for(int i = 0 ; i<n ; i=nxt[i])
        {
            findNewRank(i,nxt[i] , h);
            findNewBucket(i , nxt[i] , h);
        }
///set the new sorted suffix array ...
        for(int i =0 ; i<n ; i++)
        {
            SA[revSA[i]] = i;
            bh[i] |= b2h[i]; ///new bucket ....
        }
    }
}
void buildLCP(int n)
{
    int len = 0;
    for(int i = 0 ; i<n ; i++)
        revSA[SA[i]] = i;
    for(int i =0 ; i< n ; i++)
    {
        int k = revSA[i];
        if(k==0)
        {
            lcp[k] = 0;
            continue;
        }
        int j = SA[k-1];
        while(text[i+len]==text[j+len]) len++;
        lcp[k] = len;
        if(len) len--;
    }
}
void printSA()
{
    for(int i=0; i<SZ(text); i++) printf("%d %d %d %d %s %d\n", i, SA[i],sz(text)-SA[i],
                                             revSA[SA[i]], text.substr(SA[i]).c_str(), lcp[i]);
    puts("");
// for(int i=1;i<SZ(text);i++) printf("%d ",lcp[i]);
    puts("");
}
int k;
ll solve()
{
    ll ret=0,tana=0,maan,nij;
    int i;
    maan=sz(text)-SA[0]-k+1;
    if(maan > 0)
    {
        tana=(((maan * (maan-1))/2)%mod)%mod;
        ret=(ret + tana)%mod;
        tana=maan;
    }
    for(i=1;i<sz(text);i++)
    {
        maan=sz(text)-SA[i]-k+1;
        if(lcp[i] < k)
            tana=0;
        if(maan > 0)
        {
//            deb(SA[i],maan);
            nij=((maan * (maan-1))/2)%mod;
            ret=(ret + nij)%mod;
            if(lcp[i] >= k)
            {
                nij=(tana * maan)%mod;
                ret=(ret+ nij)%mod;
                tana+=maan;
            }
            if(lcp[i] < k)
                tana=maan;
        }
    }
    return ret;
}

int main ()
{
//    cffi;
    int i,j,test,t=1;
    cin>>test;
    while(test--)
    {
        cin>>text>>k;
        buildSA(sz(text));
        buildLCP(sz(text));
//        printSA();
        printf("Case #%d: %lld\n",t++,solve());
    }
    return 0;
}


