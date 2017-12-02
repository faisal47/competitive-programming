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

#define mt 60010
#define mod

//
//struct SAdata
//{
//    pii val;
//    int pos;
//    SAdata() {}
//    SAdata(pii x, int y)
//    {
//        val=x;
//        pos=y;
//    }
//} SADT[mt];
//
//bool comSA(SAdata a, SAdata b)
//{
//    return a.val<b.val;
//}
//
string input_text;
//int SA[mt],revSA[mt];
//
//void buildSA()
//{
//    for(int i=0; i<sz(input_text); i++) revSA[i]=input_text[i];
//    int prv_rank;
//
//    for(int cnt=1; cnt<sz(input_text); cnt*=2)
//    {
//        for(int i=0; i<sz(input_text); i++)
//        {
//            SADT[i].pos=i;
//            SADT[i].val.fs=revSA[i];
//            SADT[i].val.sc= (i+cnt<sz(input_text)) ? revSA[i+cnt] : -1;
//        }
//        sort(SADT,SADT+sz(input_text),comSA);
//
//        for(int i=0; i<sz(input_text); i++)
//        {
//            revSA[ SADT[i].pos ]= (i-1>=0 && SADT[i].val==SADT[i-1].val) ? prv_rank : i ;
//            prv_rank=revSA[ SADT[i].pos ];
//        }
//    }
//
//    for(int i=0; i<sz(input_text); i++) SA[revSA[i]]=i;
//}

int len;


int solve()
{

    int i=0, j=1, k=0, len1=sz(input_text),t;

    string s=input_text;

    while (i < len1 && j < len1 && k < len1)
    {
        t = s[(i + k) % len1] - s[(j + k) % len1];
        if (!t)
        {
            k++;
        }
        else
        {
            if (t > 0) i = i + k + 1;
            else
            {
                j = j + k + 1;
            }

            if (i == j) j++;
            k = 0;
        }
    }

//    while(i<len1 && j<len1)
//    {
//        if(input_text[i+k] == input_text[j+k])
//        {
//            k++;
//            if(k==len1) break;
//        }
//        else if(input_text[i+k] > input_text[j+k])
//        {
//            i=i+k+1;
//            if(i<=j) i=j+1;
//            k=0;
//        }
//        else
//        {
//            j=j+k+1;
//            if(j<=i) j=i+1;
//            k=0;
//        }
//
//    }

        return min(i,j)+1;

//
//    int i;
//
//    for(i=0;i<sz(input_text);i++)
//    {
//        if(SA[i]<len)
//        {
//            printf("%d\n",SA[i]+1);
//            return ;
//        }
//    }
    }


    int main ()
    {
        char arr[mt];
        int cas;
        scanf("%d",&cas);

        while(cas--)
        {
            scanf("%s",arr);
            input_text=arr;
            len=sz(input_text);

            input_text+=input_text;

            int ans=solve();

            printf("%d\n",ans>len?ans-len:ans);
        }

        return 0;
    }
