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
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sz(a) a.size()
#define mt 100010
using namespace std;
int jog[mt<<2][2],lp[mt<<2];
void init(int node,int s,int e)
{
    if(s==e)
    {
        lp[node]=jog[node][1]=0;
        jog[node][0]=1;
        return;
    }
    lp[node]=0;
    int c=node<<1,mid=(s+e)>>1;
    init(c,s,mid);
    init(c+1,mid+1,e);
    jog[node][0]=jog[c][0]+jog[c+1][0];
    jog[node][1]=jog[c][1]+jog[c+1][1];
}
int a,b;
void refresh(int node,int s,int e)
{
    if(lp[node]%2)
        swap(jog[node][0],jog[node][1]);
    if(s!=e)
    {
        int c=node<<1;
        lp[c]+=lp[node];
        lp[c+1]+=lp[node];
    }
    lp[node]=0;
}
void update(int node,int s,int e)
{
    refresh(node,s,e);
    if(s>=a && e<=b)
    {
        lp[node]++;
        refresh(node,s,e);
        return;
    }
    if(e<a || s>b)return;
    int c=node<<1;
    int mid=(s+e)>>1;
    update(c,s,mid);
    update(c+1,mid+1,e);
    jog[node][0]=jog[c][0]+jog[c+1][0];
    jog[node][1]=jog[c][1]+jog[c+1][1];
}
int maan_de(int node,int s,int e)
{
    refresh(node,s,e);
    if(s>=a && e<=b)
    return jog[node][1];
    if(e<a || s>b)return 0;
    int c=node<<1;
    int mid=(s+e)>>1;
    return maan_de(c,s,mid)+maan_de(c+1,mid+1,e);
}
int main ()
{
    int n,i,j,s,m;
    while(sci2(n,m)==2)
    {
        init(1,1,n);
        while(m--)
        {
            sci3(s,a,b);
            if(s)
            printf("%d\n",maan_de(1,1,n));
            else
            update(1,1,n);
        }
    }
    return 0;
}

