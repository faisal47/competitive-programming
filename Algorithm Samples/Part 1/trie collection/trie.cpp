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
//*************************************1224*********************************************************
#define lim 1000010 //total number of characters
struct trie{
  int adj[5];
  int no;
  trie()
  {
      mem(adj,-1);
      no=1;
  }
};
int nodeindx;
trie node[lim];
char st[50010][52];
int col[300];

void maketrie(int nodeno,int in,int pos)
{
    if(st[in][pos]=='\0') return;
    int tem=col[st[in][pos]];

    if(node[nodeno].adj[tem]!=-1){
        node[node[nodeno].adj[tem]].no++;
        ans=max(ans,(pos+1)*node[node[nodeno].adj[tem]].no);
        return maketrie(node[nodeno].adj[tem],in,pos+1);
    }

    node[nodeno].adj[tem]=nodeindx;
    node[nodeindx]=trie();
    ans=max(ans,pos+1);
    return maketrie(nodeindx++,in,pos+1);
}


int main()
{
   int n,t;
   cin>>t;
   while(t--)
   {
       cin>>n;
       int i;
       nodeindx=0;
       node[nodeindx++]=trie();
       ans=0;
       fr(i,1,n)
       {
        scanf(" %s",&st[i]);
        maketrie(0,i,0);
       }

       printf("Case %d: ",++cas);
       print1(ans);
   }
   return 0;
}
