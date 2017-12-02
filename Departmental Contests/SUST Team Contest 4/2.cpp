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
#define scd1(a) scanf("%lf",&a)
#define scd2(a,b) scanf("%lf %lf",&a,&b)
#define scd3(a,b,c) scanf("%lf %lf %lf",&a,&b,&c)
#define sz(a) a.size()
using namespace std;
vec_<int>v1,v2;
bool flag[55];
int main ()
{
    int a,b,c,d,e,f,g,h,i,j;
    bool flag1;
    while(cin>>a>>b>>c>>d>>e)
    {
        if(a==0 && b==0 && c==0 && d==0 && e==0)break;
        ms(flag,0);
        flag1=0;
        g=h=0;
        clr(v1);
        clr(v2);
        v1.pb(a);
        v1.pb(b);
        v1.pb(c);
        v2.pb(d);
        v2.pb(e);
        sort(v1.begin(),v1.end());
        sort(v2.rbegin(),v2.rend());
        for(i=0;i<2;i++)
        {
            for(j=0;j<3;j++)
            {
                if(v2[i]<v1[j] && !flag[v1[j]])
                {
                    g++;
                    flag[v2[i]]=flag[v1[j]]=1;
                    break;
                }
            }
        }
        if(g==2)
        {
            cout<<-1<<endl;
            continue;
        }
        else if(g==0)
        {
            for(i=0;i<3;i++)
            flag[v1[i]]=1;
            for(i=1;i<2;i++)
            flag[v2[i]]=1;
            for(i=1;i<=52;i++)
            {
                if(!flag[i])
                {
                    cout<<i<<endl;
                    break;
                }
            }
            continue;
        }
        a=-1;
        for(i=0;i<3;i++)
        {
            if(!flag[v1[i]])
            {
                a=max(a,v1[i]);
            }
        }
        for(i=0;i<2;i++)
        flag[v2[i]]=1;
        for(i=0;i<3;i++)
        flag[v1[i]]=1;
        for(i=a+1;i<=52;i++)
        {
            if(!flag[i])
            {
                flag1=1;
                cout<<i<<endl;
                break;
            }
        }
        if(!flag1)
        cout<<-1<<endl;
    }
    return 0;
}

