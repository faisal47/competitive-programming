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
#define mt
using namespace std;
int main ()
{
    int a=0,b=0,c=0,n,d,e;
    bool flag=0;
    cin>>n;
    while(n--)
    {
        cin>>d;
        if(d==25)a++;
        else if(d==50)b++;
        else
        c++;
        e=d-25;
        if(e==0)continue;
        else if(e==25)a--;
        else if(e==75)
        {
            if(b>0)
            {
                b--;a--;
            }
            else
            {
                a-=3;
            }
        }
        if((a<0 || b<0 || c<0) && !flag)
        {
            cout<<"NO";
            flag=1;
        }
    }
    if(!flag)
    cout<<"YES";
    return 0;
}