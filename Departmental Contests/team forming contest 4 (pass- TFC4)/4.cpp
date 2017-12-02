#include <string.h>
#include <string>
#include <stdio.h>
#include <iostream>
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
#define scch(a) scanf("%c",&a)
#define scll1(a) scanf("%I64d",&a)
#define scll2(a,b) scanf("%I64d %I64d",&a,&b)
#define scll3(a,b,c) scanf("%I64d %I64d %I64d",&a,&b,&c)
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define scd1(a) scanf("%lf",&a)
#define scd2(a,b) scanf("%lf %lf",&a,&b)
#define scd3(a,b,c) scanf("%lf %lf %lf",&a,&b,&c)
#define sz(a) a.size()
#define mt
using namespace std;

string a,b;
int c[1100][1100];
int lcsf()
{
    int i,j;
    for(i=0;i<sz(a);i++)
    {
        for(j=0;j<sz(b);j++)
        {
            if(a[i]==b[j])
                c[i+1][j+1]=c[i][j]+1;
            else
                c[i+1][j+1]=max(c[i+1][j],c[i][j+1]);
        }
    }
    return c[sz(a)][sz(b)];
}
int main ()
{
    int lcs,ans;
    while(cin>>a)
    {
        if(sz(a)==1 && a[0]=='#')break;
        cin>>b;
        ms(c,0);
        lcs=lcsf();
        ans=((sz(a)-lcs)*15)+((sz(b)-lcs)*30);
        cout<<ans<<endl;
    }
    return 0;
}

