#include <bits/stdc++.h>

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <math.h>
#include <limits.h>
#include <limits>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <set>
#include <ctime>
#include <queue>
#include <vector>
#include <map>
#include <assert.h>
#include <utility>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define mp make_pair
#define pi acos(-1)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define fs first
#define sc second
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define sf scanf
#define pf printf
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
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
#define sz(a) (int)a.size()
#define ll long long
#define LL long long
#define ull unsigned long long
#define dd double
#define rep(i,n) for(i=0;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)
using namespace std;

#define fop freopen("A-large.txt","r",stdin);freopen("A-small-attempt0output.txt","w",stdout);

template<class T1> void deb(T1 e)
{
    cout<<e<<endl;
}
template<class T1,class T2> void deb(T1 e1,T2 e2)
{
    cout<<e1<<" "<<e2<<endl;
}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3)
{
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;
}





#define mt
#define mod

int cnt[132],ans[12];

int main ()
{
    fop;
//    cffi;
    int i,j,test,t=1,n;
    char z;
    string arr;
    cin>>test;
    while(test--)
    {
        cin>>arr;
        ms(cnt,0);
        ms(ans,0);
        rep(i,sz(arr))
        cnt[arr[i]]++;
        /// zero
        ans[0]+=cnt['Z'];
        cnt['E']-=cnt['Z'];
        cnt['R']-=cnt['Z'];
        cnt['O']-=cnt['Z'];
        cnt['Z']=0;
        /// two
        ans[2]+=cnt['W'];
        cnt['T']-=cnt['W'];
        cnt['O']-=cnt['W'];
        cnt['W']=0;
        /// four
        ans[4]+=cnt['U'];
        cnt['F']-=cnt['U'];
        cnt['O']-=cnt['U'];
        cnt['R']-=cnt['U'];
        cnt['U']=0;

        /// six

        ans[6]+=cnt['X'];
        cnt['S']-=cnt['X'];
        cnt['I']-=cnt['X'];
        cnt['X']=0;

        /// eight
        ans[8]+=cnt['G'];
        cnt['E']-=cnt['G'];
        cnt['I']-=cnt['G'];
        cnt['H']-=cnt['G'];
        cnt['T']-=cnt['G'];
        cnt['G']=0;

        /// three

        ans[3]+=cnt['H'];
        cnt['T']-=cnt['H'];
        cnt['R']-=cnt['H'];
        cnt['E']-=(2*cnt['H']);
        cnt['H']=0;

        /// five

        ans[5]+=cnt['F'];
        cnt['I']-=cnt['F'];
        cnt['V']-=cnt['F'];
        cnt['E']-=cnt['F'];
        cnt['F']=0;

        /// seven

        ans[7]+=cnt['V'];
        cnt['S']-=cnt['V'];
        cnt['E']-=(2*cnt['V']);
        cnt['N']-=cnt['V'];
        cnt['V']=0;

        /// one
        ans[1]+=cnt['O'];
        cnt['N']-=cnt['O'];
        cnt['E']-=cnt['O'];
        cnt['O']=0;

        /// nine
        ans[9]=cnt['I'];

        printf("Case #%d: ",t++);
        rep(i,10)
        if(ans[i])
            while(ans[i]--)
            cout<<i;
        cout<<endl;
    }
    return 0;
}










