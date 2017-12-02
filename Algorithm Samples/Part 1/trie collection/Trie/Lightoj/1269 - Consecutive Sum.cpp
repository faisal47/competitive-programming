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
//*************************************1269*********************************************************
#define mo           50010
struct trie{
  int adj[3];
  int no;
  trie()
  {
      mem(adj,-1);
      no=1;
  }
};
int nodeindx;
trie node[mo*33];
int arr[mo];
LL mi,ma;

void maketrie(int nodeno,int in,int num)
{
    if(in==-1)
       return;

    int tem=min(1,num&(1<<in));

    if(node[nodeno].adj[tem]!=-1){
        node[node[nodeno].adj[tem]].no++;
        return maketrie(node[nodeno].adj[tem],in-1,num);
    }

    node[nodeno].adj[tem]=nodeindx;
    node[nodeindx]=trie();
    return maketrie(nodeindx++,in-1,num);
}

int search2(int nodeno,int in,int num,int ret)
{
   if(in==-1)
      return ret;

    int tem=min(1,num&(1<<in));

    if(node[nodeno].adj[tem]!=-1)
        return search2(node[nodeno].adj[tem],in-1,num,ret|(tem<<in));

    tem=(tem+1)%2;
    if(node[nodeno].adj[tem]==-1)
      return 0;
    return search2(node[nodeno].adj[tem],in-1,num,ret|(tem<<in));
}

int search1(int nodeno,int in,int num,int ret,bool gone)
{
   //printf("search1 ");
   //print1(ret);
   if(in==-1)
      return ret;

    int tem=min(1,num&(1<<in));

    if(node[nodeno].adj[tem]!=-1&&(node[node[nodeno].adj[tem]].no>1||gone))
        return search1(node[nodeno].adj[tem],in-1,num,ret|(tem<<in),gone);

    tem=(tem+1)%2;
    if(node[nodeno].adj[tem]==-1)
      return 0;
    return search1(node[nodeno].adj[tem],in-1,num,ret|(tem<<in),true);
}


int main()
{
   int t,cas=0;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       int i;
       nodeindx=0;
       node[nodeindx++]=trie();
       arr[0]=0;
       fr(i,1,n)
       {
        scanf("%d",&arr[i]);
        arr[i]^=arr[i-1];
        //print1(arr[i]);
        maketrie(0,30,arr[i]);
       }

       mi=1LL<<45;
       ma=-10;
       fr(i,1,n)
       {
          mi=min(mi,(LL)arr[i]);
          mi=min(mi,(LL)arr[i]^search1(0,30,arr[i],0,false));
          //print1(search1(0,30,arr[i],0,false));
          ma=max(ma,(LL)arr[i]);
          int num=~arr[i];
          num|=(1<<31);
          //print2(arr[i],num);
          ma=max(ma,(LL)arr[i]^search2(0,30,num,0));
       }

       printf("Case %d: ",++cas);
       print2(ma,mi);
   }
   return 0;
}
