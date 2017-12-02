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
#define SZ(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
using namespace std;

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}


//double dur(int x1,int y1,int x2,int y2)
//{
//    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//}
//template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll B,ll P,ll M){ll R=1;while(P>0){if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}return R;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};
//int X[]={1,1,2,2,-1,-1,-2,-2};//knight move//
//int Y[]={2,-2,1,-1,2,-2,1,-1};//knight move//

#define mt 85
#define mod

int dp[85][3300];

struct tt
{
    int par, child[128], dep;
    vector<int>str;
    set<int>kemilche;
};

tt T[1510]; // size = total number of pattern stings * length per string
char words[110][20];
int sz1;
char str[85]; // main string

void init(int lim)
{
    for(int i=0;i<=lim;i++)
    {
        T[i].par=0;
        T[i].dep=0;
        memset(T[i].child, 0, sizeof T[i].child);
        T[i].str.clear();
//        T[i].kemilche.clear();
    }
    sz1=1;
    return;
}

void build(int n)
{
//    deb("hola");
    int i, j, last, len;
    char ch1;
    int ch;
    for(i=0;i<n;i++)
    {
        last=0;
        len = strlen(words[i]);
        for(j=0;j<len;j++)
        {
            ch1 = words[i][j];
            ch=(int)ch1;
//            deb((int)ch);
            if(T[last].child[ch]==0)
                T[last].child[ch]=sz1++;
            T[T[last].child[ch]].dep = T[last].dep + 1;
            last = T[last].child[ch];
        }
        T[last].str.pb(i);
//        deb(last,i);
    }

    queue<int>Q;
    for(i=0;i<128;i++)
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
        u = Q.front(); Q.pop();
        for(i=0;i<128;i++)
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

//    deb("hola");

    return;
}

int freq[1510];
vec_<pii>kajkam;
map<pii,bool>kajkammap;
void search() // this function will take a string as main input and find the frequency of pattern strings in this string
{
    clr(kajkam);
    clr(kajkammap);
    int i, j, k, len, u, v;
    char ch1;
    int ch;
    len = strlen(str);
//    puts(str);
    int cur=0;
    memset(freq, 0, sizeof freq);
    for(i=0;i<len;i++)
    {
        ch1 = str[i];
        ch=(int)ch1;
        if(T[cur].child[ch]==0)
        {
            k = T[cur].par;
            while(k>0 && T[k].child[ch]==0)
                k = T[k].par;
            cur = T[k].child[ch];
        }
        else
            cur = T[cur].child[ch];
        freq[cur]++;
//        deb(cur,i);
        T[cur].kemilche.insert(i);
    }
    vector<pii>store;
    for(i=0;i<sz1;i++)
        store.pb(mp(T[i].dep, i));
    sort(store.rbegin(), store.rend());
    for(i=0;i<sz1;i++)
    {
        v = store[i].second;
        freq[T[v].par]+=freq[v];
        if(freq[T[v].par])
            T[T[v].par].kemilche.insert(all(T[v].kemilche));
    }

//    deb("hola");
    int ind;
    pii tpair;

    for(i=1;i<sz1;i++)
    {
        if(sz(T[i].str) && sz(T[i].kemilche) && freq[i])
        {
            for(set<int>::iterator j=T[i].kemilche.begin();j !=T[i].kemilche.end();j++)
            {
                for(int k=0;k<sz(T[i].str);k++)
                {
                    ind=T[i].str[k];
                    tpair=mp((*j)-strlen(words[ind])+1,(*j));
                    if(kajkammap.find(tpair) == kajkammap.end())
                    {
//                        deb(tpair.fs,tpair.sc);
                        kajkam.pb(tpair);
                        kajkammap[tpair]=1;
                    }

//                    deb(T[i].kemilche[j]-strlen(words[ind])+1,T[i].kemilche[j]);
//                    deb(T[i].kemilche[j],T[i].str[k]);
                }
            }
        }
        clr(T[i].kemilche);
    }
}

int mlen;

int solve(int pos,int ind)
{
    if(ind>=sz(kajkam))
        return 0;
    if(pos >= mlen)
        return inf;
//    deb("hola");

    int &ret=dp[pos][ind];
    if(ret != -1)
        return ret;

    ret=inf;
    ret=solve(pos+1,ind);
    int tind=ind;
    while(ind<sz(kajkam) && pos >= kajkam[ind].fs && pos<=kajkam[ind].sc)
        ind++;
    if(ind > tind)
    ret=min(ret,1+solve(pos+1,ind));

    return ret;
}

bool comp(pii a,pii b)
{
    if(a.sc == b.sc)
        return a.fs<b.fs;
    return a.sc<b.sc;
}

int main ()
{
//    fop;
    int i,j,n,m,ans;
    sz1=1;
    while(sci2(n,m)==2)
    {
        if(n==0 && m==0)
            break;

        init(sz1);
        for(i=0;i<n;i++)
            scanf(" %s",words[i]);
        getchar();
        build(n);
        ans=0;
        while(m--)
        {
            gets(str);
//            puts(str);
            search();
            mlen=strlen(str);
            if(mlen)
            {
//                deb("hola");
                ms(dp,-1);
                sort(all(kajkam),comp);
//                for(i=0;i<sz(kajkam);i++)
//                    deb(kajkam[i].fs,kajkam[i].sc);
//                deb("hola");
                ans+=solve(0,0);
            }
        }
        printf("%d\n",ans);

    }

    return 0;
}

/*

4 6
:-)
:-(
(-:
)-:
(-:-)(-:-)(-:-)(-:-) :-) (-: :-)
Hello uncle John! :-) :-D
I am sad or happy? (-:-(?
I feel so happy, my head spins
but then sadness comes :-(
Loves you, Joanna :-)))))
3 1
:)
):
))
:):)):)):)):(:((:(((:):)

*/
