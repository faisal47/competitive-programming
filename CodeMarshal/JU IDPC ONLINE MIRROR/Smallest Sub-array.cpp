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
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);
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


#define mt
#define MAX 50010
#define mod
#define sci1(a) scanf(" %d",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define sci3(a,b,c) scanf(" %d %d %d",&a,&b,&c)
#define fop freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int text[MAX];
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
//void buildLCP(int n)
//{
//    int len = 0;
//    for(int i = 0 ; i<n ; i++)
//        revSA[SA[i]] = i;
//    for(int i =0 ; i< n ; i++)
//    {
//        int k = revSA[i];
//        if(k==0)
//        {
//            lcp[k] = 0;
//            continue;
//        }
//        int j = SA[k-1];
//        while(text[i+len]==text[j+len]) len++;
//        lcp[k] = len;
//        if(len) len--;
//    }
//}

int arr[MAX],seg[4*MAX];

void printSA(int n)
{
    for(int i=0; i<n; i++) printf("%d %d %d %d\n", i, SA[i],
                                             revSA[SA[i]], text[SA[i]]);
    puts("");
// for(int i=1;i<SZ(text);i++) printf("%d ",lcp[i]);
    puts("");
}

void pre(int n)
{
    int i;
    rep(i,n)
    arr[SA[i]]=i;
}

void build(int node,int l,int r)
{
    if(l==r)
    {
        seg[node]=arr[l];
        return;
    }
    int mid=(l+r)>>1,b=node<<1;
    build(b,l,mid);
    build(b|1,mid+1,r);
    seg[node]=min(seg[b],seg[b|1]);
}
int lm,rm;

int solve(int node,int l,int r)
{
    if(r<lm || l>rm)
        return inf;
    if(l>=lm && r<=rm)
        return seg[node];
    int mid=(l+r)>>1,b=node<<1;
    return min(solve(b,l,mid),solve(b|1,mid+1,r));
}

int main ()
{
//    cffi;
    int i,j,test,n,t=1,q;
    sci1(test);
    while(test--)
    {
        sci2(n,q);
        rep(i,n)
        sci1(text[i]);
        buildSA(n);
//        printSA(n);
        pre(n);
        build(1,0,n-1);
        printf("Case %d:\n",t++);
        while(q--)
        {
            sci2(lm,rm);
            lm--;
            rm--;
            printf("%d\n",SA[solve(1,0,n-1)]+1);
        }
    }
    return 0;
}










