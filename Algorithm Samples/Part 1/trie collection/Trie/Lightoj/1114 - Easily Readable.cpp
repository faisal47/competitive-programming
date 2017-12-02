#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
using namespace std;
#define print1(a)    cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define oo          (1<<30)
#define PI          3.141592653589793
#define pi          (2*acos(0))
#define ERR        1e-5
#define PRE        1e-8
#define SZ(s)      ((int)s.size())
#define LL           long long
#define ISS         istringstream
#define OSS        ostringstream
#define VS          vector<string>
#define VI          vector<int>
#define VD          vector<double>
#define VLL         vector<long long>
#define SII         set<int>::iterator
#define SI          set<int>
#define mem(a,b)    memset(a,b,sizeof(a))
#define fr(i,a,b)   for(i=a;i<=b;i++)
#define frn(i,a,b)  for(i=a;i>=b;i--)
#define fri(a,b)    for(i=a;i<=b;i++)
#define frin(a,b)   for(i=a;i>=b;i--)
#define frj(a,b)    for(j=a;j<=b;j++)
#define frjn(a,b)   for(j=a;j>=b;j--)
#define frk(a,b)    for(k=a;k<=b;k++)
#define frkn(a,b)   for(k=a;k>=b;k--)
#define frl(a,b)    for(l=a;l<=b;l++)
#define frln(a,b)   for(l=a;l>=b;l--)
#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a,b,c)  for(int I=0;I<b;I++)    a[I] = c
#define CROSS(a,b,c,d) ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define sqr(a)      ((a)*(a))
#define FORE(i,a)   for(typeof((a).begin())i=(a).begin();i!=(a).end();i++)
#define typing(j,b) typeof((b).begin()) j=(b).begin();
#define BE(a)       a.begin(),a.end()
#define rev(a)      reverse(BE(a));
#define sorta(a)    sort(BE(a))
#define pb          push_back
#define popb        pop_back
#define round(i,a)  i = ( a < 0 ) ? a - 0.5 : a + 0.5;
#define makeint(n,s)  istringstream(s)>>n
#define inpow(a,x,y) int i; a=x;fri(2,y)  a*=x
#define cntbit(mask) __builtin_popcount(mask)
//*************************************1114*********************************************************
struct trie{
  int adj[53];
  int no;
  trie()
  {
      mem(adj,-1);
      no=0;
  }
};
int nodeindx;
trie node[100010];
char st[10010][102];
string manquery,query;
//char query[200];
int ans;

void maketrie(int nodeno,int in,int pos)
{
    if(st[in][pos]=='\0')
    {
        node[nodeno].no++;
        return;
    }

    int tem=st[in][pos];
    if(st[in][pos]<='Z') tem-='A';
    else tem-=('a'-26);

    if(node[nodeno].adj[tem]!=-1)
         return maketrie(node[nodeno].adj[tem],in,pos+1);

    node[nodeno].adj[tem]=nodeindx;
    node[nodeindx]=trie();
    return maketrie(nodeindx++,in,pos+1);
}

int counttrie(int nodeno,int pos)
{
    //print2(nodeno,pos);
    if(SZ(query)==pos)
      return node[nodeno].no;

    int tem=query[pos];
    if(query[pos]<='Z') tem-='A';
    else tem-=('a'-26);

    if(node[nodeno].adj[tem]==-1) return 0; //no such node
    counttrie(node[nodeno].adj[tem],pos+1);
}


int main()
{
   int t,cas=0;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       int i,j;
       nodeindx=0;
       node[nodeindx++]=trie();
       int len;
       fr(i,1,n)
       {
        scanf(" %s",&st[i]);
        len=strlen(st[i]);
        if(len>1) sort(&st[i][1],&st[i][len-1]);
        maketrie(0,i,0);
       }

       int m;
       char c;

       cin>>m;
       printf("Case %d:\n",++cas);
       fr(i,0,m)
       {
           ans=1;
           getline(cin,manquery);
           fr(j,0,SZ(manquery)-1)
           {
               int in=j;
               while(isalpha(manquery[j]))
                     j++;
               query=manquery.substr(in,j-in);
               if(!SZ(query)) continue;
               if(SZ(query)>1)sort(query.begin()+1,query.end()-1);
               //print2("a"+query+"a",counttrie(0,0));
               ans*=counttrie(0,0);
           }
           if(i) print1(ans);
       }

   }
   return 0;
}
