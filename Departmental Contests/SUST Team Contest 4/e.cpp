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
#define PII pair<double,int>
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
#define mt 20010
using namespace std;

struct edge
{
    double s;
    double p;
};
vec_<edge>arr;
edge s1;
bool comp(edge a,edge b)
{
    if(fabs(a.s-b.s)<.0001)
        return a.p>b.p;
    return a.s<b.s;
}

double brr[mt];
int main ()
{
    int b,t,n,i,t1,cas=1;
    double a,baki[mt],sum=0,mn,B,shob;
    while(cin>>t>>n>>B)
    {
        if(t==0 && n==0 && B==0)break;
        clr(arr);
        t1=t;
        sum=0;
        shob=0;
        while(t--)
        {
            cin>>s1.s>>s1.p;
            arr.pb(s1);
        }
        sort_m(arr);
        for(i=0; i<sz(arr); i++)
            {
                baki[i]=((100.-arr[i].p)/100.)*arr[i].s;
                shob+=baki[i];
             //   cout<<arr[i].s<<" "<<arr[i].p<<" "<<baki[i]<<endl;
            }
        //cout<<"test == "<<shob/B<<endl;
//        for(int i=0; i<n; i++)
//        {
//            brr[i]=baki[i];
//        }
//        int s=n;
//
//
//        while(s<sz(arr))
//        {
//            //cout<<"heud";
//            mn=inf;
//            for(int i=0; i<n; i++)
//            {
//                mn=min(brr[i],mn);
//                cout<<brr[i]<<" "<<"mn == "<<mn<<endl;
//            }
//            for(int i=0; i<n; i++)
//            {
//                brr[i]-=mn;
//                if(brr[i]< .001 && s<sz(arr))
//                {
//                    brr[i]=baki[s++];
//                    cout<<"brr[i] == "<<brr[i]<<endl;
//                }
//            }
//           // cout<<"mn == "<<mn<<" "<<s<<endl;
//            sum+=mn;
//        }
//        mn=-1;
//        for(int i=0; i<n; i++)
//            {
//                mn=max(mn,brr[i]);
//            }
//        sum+=mn;
        printf("Case %d: %.2lf\n\n",cas++,shob/B);

    }
    return 0;
}


