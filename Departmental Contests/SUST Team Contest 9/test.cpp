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
#define mt
using namespace std;

struct info
{
    ll month,day,hour,minute;
    ll id;
    char c;
}arr[1010];

ll bair_kor(int b,int a)
{
    //cout<<((arr[b].hour*60)+arr[b].minute)-((arr[a].hour*60)+arr[a].minute)<<endl;
    return ((arr[b].hour*60)+arr[b].minute)-((arr[a].hour*60)+arr[a].minute);
}

int main ()
{
    ll n, i, month, day, hour, minute, id, cnt;
    ll length[1010];
    char c;
    map <ll, ll> m;
    while(cin >> n && n)
    {
        clr(m);
        ms(length, 0LL);
        m[0LL] = 0LL;
        cnt = 1;
        for(int i = 0; i < n; i++)
        {
            scanf(" %lld/%lld %lld:%lld %c %lld", &arr[i].month, &arr[i].day, &arr[i].hour, &arr[i].minute, &arr[i].c, &id);

            if(m.find(id) == m.end())
            {
               // cout<<id<<endl;
                //cout<<"hello";
                m[id] = cnt++;
            }

            arr[i].id = m[id];
           // cout<<arr[i].month<<arr[i].day<<arr[i].hour<<arr[i].minute<<arr[i].c<<arr[i].id<<endl;
        }

        int a = -1, b = -1;

        for(i = 0; i < n; i++)
        {

        }
        ll ans = 0;
            for(int i = 1; i < cnt; i++)
                ans = max(length[i], ans);
            cout << ans << endl;
    }
    return 0;
}


