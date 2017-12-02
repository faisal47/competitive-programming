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
#define inf 1<<28
#define mp make_pair
#define pii pair<int,int>
#define fs first
#define sc second
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define mt 100010
using namespace std;
int info[4*mt][2],arr[mt],a,b;
void build(int s,int e,int node)
{
    if(s==e)
    {
        info[node][0]=info[node][1]=arr[s];
        return;
    }
    int c=node<<1,mid=(s+e)>>1;
    build(s,mid,c);
    build(mid+1,e,c+1);
    info[node][0]=max(info[c][0],info[c+1][0]);
    info[node][1]=min(info[c][1],info[c+1][1]);
}
pii maan_de(int s,int e,int node)
{
    if(b<s || a>e)return mp(-1,inf);
    if(s>=a && e<=b)
            return mp(info[node][0],info[node][1]);
    int c=node<<1,mid=(s+e)>>1;
    pii a1,b1;
    a1=maan_de(s,mid,c);
    b1=maan_de(mid+1,e,c+1);
    return mp(max(a1.fs,b1.fs),min(a1.sc,b1.sc));
}
int main ()
{
    int test,t=1,d,n,i,ans;
    pii ans1;
    sci1(test);
    while(test--)
    {
        sci2(n,d);
        ans=-1;
        for(i=1;i<=n;i++)
        sci1(arr[i]);
        if(d==1)
        {
            printf("Case %d: 0\n",t++);continue;
        }
        build(1,n,1);
        d--;
        a=1,b=1+d;
        while(b<=n)
        {
            ans1=maan_de(1,n,1);
            ans=max(ans,ans1.fs-ans1.sc);
            a++,b++;
        }
        printf("Case %d: %d\n",t++,ans);
    }
    return 0;
}

