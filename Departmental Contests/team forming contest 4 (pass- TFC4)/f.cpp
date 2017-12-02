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
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define scch(a) scanf("%c",&a)
#define scll1(a) scanf("%I64d",&a)
#define scll2(a,b) scanf("%I64d %I64d",&a,&b)
#define scll3(a,b,c) scanf("%I64d %I64d %I64d",&a,&b,&c)
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sz(a) a.size()
#define mt 100010
using namespace std;
int main ()
{
    int i,j,t=0,test,n,s,e,maxi,sum,ans,m,maxis,maxie,st;
    sci1(test);
    while(test--)
    {
        if(t++)cout<<endl;
        sci1(n);
        s=1,st=1;
        maxi=-1010;
        sum=ans=0;
        for(i=1;i<=n;i++)
        {
            sci1(m);
            if(m>maxi)
            {
                maxi=m;maxis=i;maxie=i;
            }
            sum+=m;
            if(sum<0)
            {
                st=i+1;sum=0;continue;
            }
            if(sum>ans && st!=s)
            s=st;
            if(sum>ans)
            {
                ans=sum;
                e=i;
            }
        }
        printf("Case %d:\n",t);
        if(maxi<0)
        cout<<maxi<<" "<<maxis<<" "<<maxie<<endl;
        else
        cout<<ans<<" "<<s<<" "<<e<<endl;
    }
    return 0;
}
