#include <bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define FOR_0(i,n) for(i=0;i<n;i++)
#define FOR_1(i,n) for(i=1;i<=n;i++)
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define eps 1E-7
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
#define pll pair<ll,ll>
#define pii pair<int,int>
#define sz(a) a.size()
using namespace std;
typedef long long ll;

ll i,j,k,l,m,n;
pll p;
map<pll,ll>m_pair;
map<ll,ll>m2;
map<ll,ll>m3;
vec_<ll>v1,v2;
ll n1=8;
bool check(int a,int b)
{
    p=mp(v1[a],v2[b]);
    //cout<<p.first<<" "<<p.second<<endl;
    if(m_pair.find(p)==m_pair.end())
        return 0;
    else
        return 1;
}
int main ()
{
    while(n1--)
    {
        cin>>i>>j;
        p=mp(i,j);
        m_pair[p]=1;
        if(m2.find(i)==m2.end())
        {
            m2[i]=1;
            v1.pb(i);
        }
        if(m3.find(j)==m3.end())
        {
            m3[j]=1;
            v2.pb(j);

        }
    }
    //cout<<sz(v1)<<" "<<sz(v2)<<endl;
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    for(i=0; i<sz(v1); i++)
        for(j=i+1; j<sz(v1); j++)
            for(k=j+1; k<sz(v1); k++)
                for(l=0; l<sz(v2); l++)
                    for(m=l+1; m<sz(v2); m++)
                        for(n=m+1; n<sz(v2); n++)
                        {
                            if(check(i,l) && check(i,m) && check(i,n) && check(j,l) && !check(j,m) && check(j,n) && check(k,l) && check(k,m) && check(k,n))
                            {
                                cout<<"respectable";
                                return 0;
                            }
                        }
    cout<<"ugly";
    return 0;
}