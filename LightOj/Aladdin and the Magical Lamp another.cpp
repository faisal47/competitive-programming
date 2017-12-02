/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <math.h>
#include <limits.h>
#include <limits>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <set>
#include <ctime>
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
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
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
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};

/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

#define mt 3*5010
#define mod


struct SAdata
{
    pii val;
    int pos;
    SAdata() {}
    SAdata(pii x, int y)
    {
        val=x;
        pos=y;
    }
} SADT[mt]; /// temporary Data Structure for building SA
bool comSA(SAdata a, SAdata b)
{
    return a.val<b.val;
}

string input_text;/// Input String for SA to build
int SA[mt],revSA[mt];      /// Found SA and reverse SA
int lcp[mt]; /// longest common prfix array for adjacent suffixes found in SA


/// SA returns the start positions  of the suffixes which are stored in lexicographical order
/// revSA returns for every suffix starting at 0 its position in SA

void buildSA()
{
    for(int i=0; i<sz(input_text); i++) revSA[i]=input_text[i];
    int prv_rank;

    for(int cnt=1; cnt<sz(input_text); cnt*=2)
    {
        for(int i=0; i<sz(input_text); i++)
        {
            SADT[i].pos=i;
            SADT[i].val.fs=revSA[i];
            SADT[i].val.sc= (i+cnt<sz(input_text)) ? revSA[i+cnt] : -1;
        }
        sort(SADT,SADT+sz(input_text),comSA);

        for(int i=0; i<sz(input_text); i++)
        {
            revSA[ SADT[i].pos ]= (i-1>=0 && SADT[i].val==SADT[i-1].val) ? prv_rank : i ;
            prv_rank=revSA[ SADT[i].pos ];
        }
    }
    for(int i=0; i<sz(input_text); i++) SA[revSA[i]]=i;
}

void buildLCP()
{
    int mx_mtch=0,SApos,j;
    for(int i=0; i<sz(input_text); i++)
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

void printSA()
{
    cout<<"SA: ";
    for(int i=0; i<sz(input_text); i++) printf("%d ",SA[i]);
    puts("");
    cout<<"lcp: ";
    for(int i=1; i<sz(input_text); i++) printf("%d ",lcp[i]);
    puts("");
    return ;
}

int len1,len2,len3;

int check(int a)
{
    if(input_text[a]=='#')
        return 0;

    if(a<len1)
        return 1;
    if(a<len2)
        return 2;
    return 3;
}

bool solve(int len)
{
    bool flag1,flag2,flag3;
    flag1=flag2=flag3=false;
    int l=1,r,i,cr;
    // deb("hello ",len);
    while(l<sz(input_text))
    {
        // deb(l);
        while(l<sz(input_text) && lcp[l]<len)l++;

        r=l;
        flag1=flag2=flag3=false;

        cr=check(SA[l-1]);

            if(cr == 1)
            {
                flag1=true;
            }
            else if(cr == 2)
            {
                flag2=true;
            }
            else if(cr == 3)
            {
                flag3=true;
            }

        while(r<sz(input_text) && lcp[r]>=len)
        {
            cr=check(SA[r]);

            if(cr == 1)
            {
                flag1=true;
            }
            else if(cr == 2)
            {
                flag2=true;
            }
            else if(cr == 3)
            {
                flag3=true;
            }

            if(flag1 && flag2 && flag3)
                return 1;
            r++;
        }

//        for(i=l-1; i<r; i++)
//        {
//            cr=check(SA[i]);
//
//            if(cr == 1)
//            {
//                flag1=true;
//            }
//            else if(cr == 2)
//            {
//                flag2=true;
//            }
//            else if(cr == 3)
//            {
//                flag3=true;
//            }
//
//            if(flag1 && flag2 && flag3)
//                return 1;
//        }
        l=r;
    }

    return 0;
}

int bs(int h)
{
    int l=1,mid;
    int ans=0;
    while(l<=h)
    {
        mid=(l+h)>>1;
        if(solve(mid))
        {
            ans=max(ans,mid);
            l=mid+1;
        }
        else
            h=mid-1;
    }
    return ans;
}

int main()
{
    char arr[mt];
    char z;
    int cas,t=1,i,max_len,len;
    scanf(" %d",&cas);
    scanf("%c",&z);
    while(cas--)
    {
        gets(arr);
        max_len=-1;
        gets(arr);
        len=strlen(arr);
        max_len=max(max_len,len);
        input_text="";
        input_text=input_text+arr+'#';
        len1=sz(input_text);
        //deb("1 = ",arr);
        gets(arr);
        //deb("2 = ",arr);
        len=strlen(arr);
        max_len=max(max_len,len);
        input_text=input_text+ arr+'#';
        len2=sz(input_text);
        gets(arr);
        // deb("3 = ",arr);
        len=strlen(arr);
        max_len=max(max_len,len);
        input_text=input_text + arr;
        len3=sz(input_text);

        //deb(input_text);
        buildSA();
        buildLCP();
//      printSA();

        printf("Case %d: %d\n",t++,bs(max_len));

    }

    return 0;
}

