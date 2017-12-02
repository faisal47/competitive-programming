#include <bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define clr(a) a.clear()
#define pb push_back
#define pob pop_back
#define vec_ vector
#define eps 1E-7
#define sort_n(a) sort(a.begin(),a.end())
#define sort_m(a) sort(a.begin(),a.end(),comp)
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define scch(a) scanf("%c",&a)
#define scll1(a) scanf("%lld",&a)
#define scll2(a,b) scanf("%lld %lld",&a,&b)
#define scll3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define scd1(a) scanf("%lf",&a)
#define scd2(a,b) scanf("%lf %lf",&a,&b)
#define scd3(a,b,c) scanf("%lf %lf %lf",&a,&b,&c)
#define mp make_pair
#define sz(a) a.size()
#define mt 1010
using namespace std;
typedef long long ll;
ll i,j,arr[mt],n,m,gun[mt][mt],ans,ans_temp,k,l,ind;
int main ()
{
    while(scll2(n,m)==2)
    {
        if(n==0 && m==0)break;
        ans=ans_temp=0;
        for(i=1; i<=n; i++)
        {
            scll1(arr[i]);
            gun[i][i]=arr[i];
            ans_temp=(ans_temp+arr[i])%m;
        }
        ans=max(ans,ans_temp);
        l=n-1;
        for(k=1;k<=l;k++)
        {
            ans_temp=0;
           // ind=
            for(i=1;i<=n;i++)
            {
                ind=i+k-1;
                for(j=i+k;j<=n;j++)
                {
                   gun[i][j]=(gun[i][ind]*arr[j])%m;
                   ans_temp=(ans_temp+gun[i][j])%m;
                  //cout<<i<<" "<<j<<" "<<ind<<" gun[i][j]=== "<<gun[i][j]<<endl;
                }
            }
           // cout<<ans_temp<<endl;
             ans=max(ans,ans_temp);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

