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
#define pii pair<int,int>
#define fs first
#define sc second
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define sf scanf
#define pf printf
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
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
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
using namespace std;

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


struct tt
{
    int par, child[130], dep;
    vector<int>str;
};

tt T[360010]; // size = total number of pattern stings * length per string
string words;
int sz1;
string str; // main string

void init(int lim)
{
    for(int i=0; i<=lim; i++)
    {
        T[i].par=0;
        T[i].dep=0;
        memset(T[i].child, 0, sizeof T[i].child);
        T[i].str.clear();
    }
    sz1=1;
    return;
}

void build1(int i)
{
    int j, last, len;
    char ch;
    last=0;
    len = sz(words);
    for(j=0; j<len; j++)
    {
        ch = words[j];
        if(T[last].child[ch]==0)
            T[last].child[ch]=sz1++;
        T[T[last].child[ch]].dep = T[last].dep + 1;
        last = T[last].child[ch];
    }
    T[last].str.pb(i);
}

void build2()
{
    int i, j;
    char ch;
    queue<int>Q;
    for(i=0; i<128; i++)
    {
        if(T[0].child[i])
        {
            Q.push(T[0].child[i]);
            T[T[0].child[i]].par = 0;
        }
    }
    int u, v, k;
    while(!Q.empty())  // implementing kmp in the trie tree with kind of bfs
    {
        u = Q.front();
        Q.pop();
        for(i=0; i<128; i++)
        {
            if(T[u].child[i])
            {
                v = T[u].child[i];
                k = T[u].par;
                while(k>0 && T[k].child[i]==0)
                    k = T[k].par;
                T[v].par = T[k].child[i];
                Q.push(v);
            }
        }
    }
    return;
}

int freq[360010], ans[60010],arrl[360010];

void search1(int ln) // this function will take a string as main input and find the frequency of pattern strings in this string
{
    int i, j, k, len, u, v;
    char ch;
    len = sz(str);
    int cur=0;
    for(i=0; i<len; i++)
    {
        ch = str[i];
        if(T[cur].child[ch]==0)
        {
            k = T[cur].par;
            while(k>0 && T[k].child[ch]==0)
                k = T[k].par;
            cur = T[k].child[ch];
        }
        else
            cur = T[cur].child[ch];
        if(arrl[cur] != ln)
        {
            arrl[cur] = ln;
            freq[cur]++;
        }
    }

}

void search2()
{
    int i, j, k, len, u, v;
    vector<pii>store;
    for(i=0; i<sz1; i++)
        store.pb(mp(T[i].dep, i));
    sort(store.rbegin(), store.rend());

    for(i=0; i<sz1; i++)
    {
        v = store[i].second;
        freq[T[v].par]+=freq[v]; // parent gulake cummulatively frequency gula die dea
    }

    for(i=1; i<sz1; i++)
    {
        if(sz(T[i].str))
        {
            for(j=0; j<sz(T[i].str); j++)
            {
                ans[T[i].str[j]] = freq[i];
            }
        }
    }
}

char arr[360010];
string temp[10010];

int main ()
{
    int i,j,n,m,len;
    char z;
    sz1=1;
    scanf("%d %d%c",&n,&m,&z);

    init(sz1);
    for(i=1; i<=n; i++)
    {
        gets(arr);
        temp[i]=arr;

    }

    for(i=0; i<m; i++)
    {
        gets(arr);
        words=arr;
        build1(i);
    }
    build2();

    for(i=1; i<=n; i++)
    {
        str=temp[i];
        search1(i);
    }

    search2();

    for(i=0; i<m; i++)
        printf("%d\n",ans[i]);

    return 0;
}

