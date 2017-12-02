#include <bits/stdc++.h>
#define mt 30100
#define mp make_pair
#define fs first
#define sc second
#define pi pair<int,int>
using namespace std;
int arr[mt],pivots[3*mt][2],ans,n,s,e;
void init(int node,int l,int r)
{
    if(l==r)
    {
        pivots[node][0]=arr[l];
        pivots[node][1]=l;
        return;
    }
    int mid=(l+r)>>1;
    init(node<<1,l,mid);
    init((node<<1)+1,mid+1,r);
    if(pivots[node<<1][0]<=pivots[(node<<1)+1][0])
    {
        pivots[node][0]=pivots[node<<1][0];
        pivots[node][1]=pivots[node<<1][1];
    }
    else
    {
        pivots[node][0]=pivots[(node<<1)+1][0];
        pivots[node][1]=pivots[(node<<1)+1][1];
    }
}
pi maan_de1(int node,int l,int r)
{
    if(e<l || s>r)return mp(1<<28,mt);
    if(l>=s && r<=e)return mp(pivots[node][0],pivots[node][1]);
    node<<=1;
    int mid=(l+r)>>1;
    pi p,q;
    p=maan_de1(node,l,mid);
    q=maan_de1(node+1,mid+1,r);
    return p.fs<=q.fs?p:q;
}
int maan_de(int l,int r)
{
    if(l>r)return 0;
    if(l==r)return arr[l];
    s=l;e=r;
    pi p=maan_de1(1,1,n);
    ans=max(ans,p.fs*(r-l+1));
    ans=max(ans,maan_de(l,p.sc-1));
    ans=max(ans,maan_de(p.sc+1,r));
    return ans;
}
int main ()
{
    int t=1,test,i;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        for(i=1; i<=n; i++)scanf("%d",&arr[i]);
        ans=-1;
        init(1,1,n);
        printf("Case %d: %d\n",t++,maan_de(1,n));
    }
    return 0;
}

