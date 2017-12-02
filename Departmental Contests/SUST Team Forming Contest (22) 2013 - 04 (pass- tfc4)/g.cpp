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
#define sort_n(a) sort(a.begin(),a.end())
#define sort_m(a) sort(a.begin(),a.end(),comp)
#define fop freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
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
#define pri1(a) printf("%d ",a)
#define pri2(a,b) printf("%d %d ",a,b)
#define prll1(a) printf("%I64d ",a)
#define prll2(a,b) printf("%I64d %I64d ",a,b)
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define mt 100010
using namespace std;

int f[3*mt];

int kmp(string a,string b)
{
    int len1=sz(a);
    int len2=sz(b);
    a.pb('#');
    a+=b;
    int k;
    f[0]=k=0;
    int i;
    for(i=1;i<sz(a);i++)
    {
        while(k>0 && a[i]!=a[k])
            k=f[k-1];
        if(a[i]==a[k])
            k++;
        f[i]=k;
    }
    for(i=len1;i<sz(a);i++)
    if(f[i]==len1)return len1;
    return f[sz(a)-1];
}

int bana(string s1,string s2,string s3)
{
    int apl=sz(s1)+sz(s2)+sz(s3);
    string a;

    int kmp1=kmp(s2,s1);

    int i;
    a=s1;
    for(i=kmp1;i<sz(s2);i++)
    a+=s2[i];

    int kmp2=kmp(s3,a);
   // cout<<apl<<" "<<kmp1<<" "<<kmp2<<endl;
    return apl-kmp1-kmp2;
}

int main ()
{
    string s1,s2,s3;

    cin>>s1>>s2>>s3;

    int ans=inf;

    ans=min(ans,bana(s1,s2,s3));
    ans=min(ans,bana(s1,s3,s2));
    ans=min(ans,bana(s2,s1,s3));
    ans=min(ans,bana(s2,s3,s1));
    ans=min(ans,bana(s3,s1,s2));
    ans=min(ans,bana(s3,s2,s1));

    cout<<ans<<endl;
    return 0;
}

