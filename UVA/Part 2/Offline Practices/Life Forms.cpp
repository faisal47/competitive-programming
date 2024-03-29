/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

#include <stdio.h>
#include <iostream>
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

#define mt 101000
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

//void printSA()
//{
//    cout<<"SA: ";
//    for(int i=0; i<sz(input_text); i++) printf("%d ",SA[i]);
//    puts("");
//    cout<<"lcp: ";
//    for(int i=1; i<sz(input_text); i++) printf("%d ",lcp[i]);
//    puts("");
//    return ;
//}

vec_<int>lengths;
vec_<string>ans;
bool col[110];
int ordhek;

void check(int l)
{
    if(input_text[l]=='#')
        return;
    //puts("in check");
    //cout<<l<<endl;
    int i;

//    for(i=0; i<sz(lengths); i++)
//        cout<<lengths[i]<<endl;
    for(i=0; i<sz(lengths); i++)
    {
        //cout<<lengths[i]<<endl;
        if(l<lengths[i])
        {
//                c=i;
            // cout<<"yes "<<i<<endl;
            col[i]=1;
            break;
        }
    }
//    cout<<c<<endl;
//    col[c]=1;
//    puts("in check");
}

void solve(int len)
{
//    puts("in solve len == ");
//    cout<<len<<endl;
    int i,l,r,j,koyta,k;
    string temp;
    i=1;
    while(i<sz(input_text))
    {
        l=i;
        while(l<sz(input_text) && lcp[l]<len)l++;
        //r=l;
        ms(col,0);
        if(l<sz(input_text) && lcp[l]>=len)
            check(SA[l-1]);

        while(l<sz(input_text) && lcp[l]>=len)
        {
            check(SA[l]);
            l++;
        }

        koyta=0;
        bool nimu;
        for(j=0; j<sz(lengths); j++)
        {
            if(col[j])koyta++;
            if(koyta>=ordhek)
            {
                temp="";
                nimu=true;
                for(k=0; k<len; k++)
                {
                    if(input_text[SA[l-1]+k] == '#')
                        {
                            nimu=false;
                            break;
                        }

                    temp+=input_text[SA[l-1]+k];
                }
                // cout<<"in solve len == "<<len<<endl;
                if(nimu)
                ans.pb(temp);
                break;
            }
        }

        i=l;
    }
}

int main ()
{
    int i,j,n,maxi,len;
    char arr[mt];
    bool flag,flag1=false;

    while(sci1(n)==1 && n)
    {
        maxi=-1;
        input_text="";
        clr(lengths);
        clr(ans);

        ordhek=(n>>1)+1;

//        cout<<ordhek<<endl;
        if(flag1)
            puts("");
        flag1=true;
        if(n==1)
        {
            scanf("%s",arr);
            input_text=arr;
            cout<<input_text<<endl;
            continue;
        }

        while(n--)
        {
            scanf("%s",arr);
            len=strlen(arr);
            maxi=max(maxi,len);
//            if(n)
                input_text=input_text+arr+'#';
//            else
//                input_text=input_text+arr;

            lengths.pb(sz(input_text));
        }

//        puts("in main");
//        cout<<sz(lengths)<<endl;
        // cout<<input_text<<endl;
        buildSA();
        buildLCP();
        flag=false;
        for(i=maxi; i>=1; i--)
        {
            solve(i);
            if(sz(ans))
            {
                flag=false;//ans ashole ache ki nai eta janar flag
                for(j=0; j<sz(ans); j++)
                {
                    if(ans[j][0]=='#')
                        continue;
                    flag=true;
                    cout<<ans[j]<<endl;
                }
                //ekhane ans print korte hobe
                break;
            }
        }
        if(!flag)
            puts("?");
    }
    return 0;
}
