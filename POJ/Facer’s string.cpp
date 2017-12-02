/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <assert.h>
#include <utility>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define mp make_pair
#define pii pair<int,int>
#define fs first
#define sc second
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define sf scanf
#define pf printf
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
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
#define deb1(a) cout<<a<<endl;
#define deb2(a,b) cout<<a<<" "<<b<<endl
#define deb3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
using namespace std;
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};

/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

#define mt 100010
#define mod

int N,n;

struct SAdata{
    pii val;
    int pos;
    SAdata() {}
    SAdata(pii x, int y)
    {
        val=x;pos=y;
    }
}SADT[mt];/// temporary Data Structure for building SA
bool comSA(SAdata a, SAdata b)
{
    return a.val<b.val;
}

int input_text[mt];/// Input String for SA to build
int SA[mt],revSA[mt];      /// Found SA and reverse SA
int lcp[mt]; /// longest common prfix array for adjacent suffixes found in SA


/// SA returns the start positions  of the suffixes which are stored in lexicographical order
/// revSA returns for every suffix starting at 0 its position in SA

void buildSA()
{
    for(int i=0;i<N;i++) revSA[i]=input_text[i];
    int prv_rank;

    for(int cnt=1;cnt<N;cnt*=2)
    {
        for(int i=0;i<N;i++)
        {
            SADT[i].pos=i;
            SADT[i].val.fs=revSA[i];
            SADT[i].val.sc= (i+cnt<N) ? revSA[i+cnt] : -1;
        }
        sort(SADT,SADT+N,comSA);

        for(int i=0;i<N;i++)
        {
            revSA[ SADT[i].pos ]= (i-1>=0 && SADT[i].val==SADT[i-1].val) ? prv_rank : i ;
            prv_rank=revSA[ SADT[i].pos ];
        }
    }
    for(int i=0;i<N;i++) SA[revSA[i]]=i;
}

void buildLCP()
{
    int mx_mtch=0,SApos,j;
    for(int i=0;i<N;i++)
    {

        SApos=revSA[i];
        if(SApos==0) continue;
        if(mx_mtch>0) mx_mtch--;

        j=SA[SApos-1];

        while( (i+mx_mtch)<N && (j+mx_mtch)<N && input_text[i+mx_mtch]==input_text[j+mx_mtch]  )
            mx_mtch++;

        lcp[SApos]=mx_mtch;
    }
    lcp[0]=0;

    return ;
}

int solve(int len)
{
    int i=0,l,r,j,c,c1=0;
    bool flag;

    while(i<N)
    {
       // puts("hello");
        flag=false;
        c=0;
        l=i;
        while(l<N && lcp[l]<len)l++;

        r=l;

        while(r<N && lcp[r]>=len)r++;

        i=r;

        for(j=l-1;j<r;j++)
        {
            if(SA[j]<n)c++;
            else if(SA[j]>n)
                flag=true;
        }

        if(flag)
            c1+=c;
    }

    return c1;
}

int main ()
{

    int m,k,i;

    while(scanf("%d %d %d",&n,&m,&k) == 3)
    {
        N=n+m+1;

        for(i=0;i<n;i++)
            scanf("%d",&input_text[i]);

        input_text[n]=10010;

        for(i=n+1;i<N;i++)
            scanf("%d",&input_text[i]);


        buildSA();
        buildLCP();

        int ans=solve(k);
        ans-=solve(k+1);

        printf("%d\n",ans);
    }

    return 0;
}
