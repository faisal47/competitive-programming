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
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define mt 3*100010
using namespace std;
typedef long long ll;
int jog[mt],lp[mt],a,b,v;
void init(int s,int e,int node)
{
    lp[node]=-1;
    jog[node]=0;
    if(s==e)
        return;
    int c=node<<1,mid=(s+e)>>1;
    init(s,mid,c);
    init(mid+1,e,c+1);
}
void refresh(int s,int e,int node)
{
    if(e<s)return;
    if(lp[node]!=-1)
    {
        jog[node]=(e-s+1)*lp[node];
        if(s!=e)
        {
            int c=node<<1;
            lp[c]=lp[node];
            lp[c+1]=lp[node];
        }
        lp[node]=-1;
    }
}
void update(int s,int e,int node)
{
    refresh(s,e,node);
    if(e<a || s>b || e<s)return;
    if(s>=a && e<=b)
    {
        lp[node]=v;
        refresh(s,e,node);
        return;
    }
    int c=node<<1,mid=(s+e)>>1;
    update(s,mid,c);
    update(mid+1,e,c+1);
    jog[node]=jog[c]+jog[c+1];
}
int maan_de(int s,int e,int node)
{
    if(e<a || s>b || e<s)return 0;
    refresh(s,e,node);
    if(s>=a && e<=b)
        return jog[node];
    int c=node<<1,mid=(s+e)>>1;
    return maan_de(s,mid,c)+maan_de(mid+1,e,c+1);
}
int main ()
{
    int q,test,t=1,n,s,ans,mot,d;
    sci1(test);
    while(test--)
    {
        sci2(n,q);
        init(1,n,1);
        printf("Case %d:\n",t++);
        while(q--)
        {
            sci1(s);
            if(s==1)
            {
                sci3(a,b,v);
                a++,b++;
                update(1,n,1);
            }
            else
            {
                sci2(a,b);
                a++,b++;
                ans=maan_de(1,n,1);
                mot=b-a+1;
                d=__gcd(ans,mot);
                ans/=d;
                mot/=d;
                printf("%d",ans);
                if(mot!=1)
                    printf("/%d",mot);
                printf("\n");
            }
        }
    }
    return 0;
}

