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
#define mo           50010
struct trie{
  int adj[27];
  bool end;
  bool candi;
  trie()
  {
      mem(adj,-1);
      end=false;
      candi=false;
  }
};
int nodeindx1=0,nodeindx2=0;
trie node1[mo*22],node2[mo*22];
string arr1[mo],arr2[mo];
bool col[1000];

void maketrie1(int nodeno,int in,int pos)
{
    if(pos==SZ(arr1[in])){
       node1[nodeno].end=true;
       return;
    }

    int tem=arr1[in][pos]-'a';

    if(node1[nodeno].adj[tem]!=-1){
        if(node1[node1[nodeno].adj[tem]].end){
         col[pos+1]=true;
         if();
        }
        return maketrie1(node1[nodeno].adj[tem],in,pos+1);
    }

    node1[nodeno].adj[tem]=nodeindx1;
    node1[nodeindx1]=trie();
    return maketrie1(nodeindx1++,in,pos+1);
}

bool maketrie2(int nodeno,int in,int pos,bool ret)
{
    if(pos==SZ(arr2[in])){
       node2[nodeno].end=true;
       return ret;
    }

    int tem=arr2[in][pos]-'a';

    if(node2[nodeno].adj[tem]!=-1)
    {
        if(node2[node2[nodeno].adj[tem]].end&&col[SZ(arr2[in])-pos-1])
          ret=true;
        return maketrie2(node2[nodeno].adj[tem],in,pos+1,ret);
    }

    node2[nodeno].adj[tem]=nodeindx2;
    node2[nodeindx2]=trie();
    return maketrie2(nodeindx2++,in,pos+1,ret);
}

bool comp(string a,string b)
{
   return SZ(a)<SZ(b);
}


int main()
{
   int i=0;
   nodeindx1=0;
   nodeindx2=0;
   while(getline(cin,arr1[++i]))
    if(SZ(arr1[i])==0) break;

   int n=(--i);
   sort(&arr1[1],&arr1[n+1],comp);
   fr(i,1,n){
      arr2[i]=arr1[i];
      rev(arr2[i]);
   }

   node1[nodeindx1++]=trie();
   node2[nodeindx2++]=trie();
   VS ans;
   fr(i,1,n)
   {
      mem(col,false);
      maketrie1(0,i,0);
      //print1(arr1[i]);
      if(maketrie2(0,i,0,false))
         ans.pb(arr1[i]);
   }

   sorta(ans);
   fr(i,0,SZ(ans)-1)
      print1(ans[i]);
   return 0;
}
