/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
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

#define mt 3*5010
#define mod

struct SAdata{
    pii val;
    int pos;
    SAdata() {}
    SAdata(pii x, int y)
    {
        val=x;pos=y;
    }
}SADT[mt];

bool comSA(SAdata a, SAdata b)
{
    return a.val<b.val;
}

string input_text;
int SA[mt],revSA[mt];
int lcp[mt];

void buildSA()
{
    for(int i=0;i<sz(input_text);i++) revSA[i]=input_text[i];
    int prv_rank;

    for(int cnt=1;cnt<sz(input_text);cnt*=2)
    {
        for(int i=0;i<sz(input_text);i++)
        {
            SADT[i].pos=i;
            SADT[i].val.fs=revSA[i];
            SADT[i].val.sc= (i+cnt<sz(input_text)) ? revSA[i+cnt] : -1;
        }
        sort(SADT,SADT+sz(input_text),comSA);

        for(int i=0;i<sz(input_text);i++)
        {
            revSA[ SADT[i].pos ]= (i-1>=0 && SADT[i].val==SADT[i-1].val) ? prv_rank : i ;
            prv_rank=revSA[ SADT[i].pos ];
        }
    }
    for(int i=0;i<sz(input_text);i++) SA[revSA[i]]=i;
}

void buildLCP()
{
    int mx_mtch=0,SApos,j;
    for(int i=0;i<sz(input_text);i++)
    {

        SApos=revSA[i];
        if(SApos==0) continue;
        if(mx_mtch>0) mx_mtch--;

        j=SA[SApos-1];

        while( (i+mx_mtch)<sz(input_text) && (j+mx_mtch)<sz(input_text) && input_text[i+mx_mtch]==input_text[j+mx_mtch]  )
            mx_mtch++;

        lcp[SApos]=mx_mtch;
    }
    lcp[0]=0;

    return ;
}

int len1,len2,len3,ans;

int check(int pos)
{
    if(input_text[pos] == '#')
        return 4;
    if(pos<len1)
        return 1;
    if(pos<len2)
        return 2;
    return 3;
}

void printSA()
{
    cout<<"SA: ";
    for(int i=0;i<sz(input_text);i++) printf("%d ",SA[i]);
    puts("");
    cout<<"lcp: ";
    for(int i=1;i<sz(input_text);i++) printf("%d ",lcp[i]);
    puts("");
    return ;
}

void solve()
{
    ans=0;
    int s=1,i=1,j,shuru,shesh,cf;
    bool f1,f2,f3;

    while(i<sz(input_text))
    {
        //cout<<"hello";
        //deb1(i);

        for(j=i+1;j<sz(input_text);j++)
            if(lcp[j]<lcp[j-1])
                break;

        shuru=i-1;
        shesh=j-1;
        i=j;

        f1=f2=f3=false;

        for(j=shesh;j>=shuru;j--)
        {
            cf=check(SA[j]);

            if(cf==1)
                f1=1;
            else if(cf==2)
                f2=1;
            else if(cf==3)
                f3=1;

            if(f1 && f2 && f3)
               {
                    ans=max(ans,lcp[j+1]);
                    break;
               }

        }

    }
}

int main ()
{
    string arr;
    int test,t=1;
    //scanf("%d",&test);
    cin>>test;
    while(test--)
    {
        cin>>arr;
        //scanf("%s",arr);
        input_text=arr+'#';
        len1=sz(input_text);
//        cout<<input_text<<endl;

        cin>>arr;
        //scanf("%s",arr);
        input_text+=arr+'#';
        len2=sz(input_text);
//        cout<<input_text<<endl;
        //
        cin>>arr;//scanf("%s",arr);
        input_text+=arr;
        len3=sz(input_text);
//        cout<<input_text<<endl;
       // deb3(len1,len2,len3);

        buildSA();
        buildLCP();
        //printSA();
        solve();

        printf("Case %d: %d\n",t++,ans);

    }
    return 0;
}


