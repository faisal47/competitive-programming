#include <bits/stdc++.h>
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define sz(a) a.size()
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sort_m(a) sort(a.begin(),a.end(),sign)
#define mt 100010
using namespace std;
int data[3*mt],n,indx,maan,change,ans[50010];
struct uq1
{
    int l,r,c,s;
};
map<int,int>ma;
vec_<uq1>uq;
bool sign(uq1 a,uq1 b)
{
     if(a.r == b.r) return a.c < b.c;
    return a.r < b.r;
}
void build(int l,int r,int node)
{
    if(l<1 || r>n || l>r)
        return;
    int mid=(l+r)>>1;
    if(l==r)
    {
        data[node]=0;
        return;
    }
    data[node]=0;
    node<<=1;
    build(l,mid,node);
    build(mid+1,r,node+1);
}
void update(int l,int r,int node)
{
    if(indx>r || indx<l || l>r)
    return;
    if(indx==l && l==r)
    {
        data[node]+=change;
        return;
    }
    if(l==r)
    return;
    int mid=(l+r)>>1;
    node<<=1;
    update(l,mid,node);
    update(mid+1,r,node+1);
    data[node>>1]=data[node]+data[node+1];
}
int query(int l,int r,int node)
{
    if(l>indx || r<maan || l>r)
    return 0;
    if(l>=maan && r<=indx)
    return data[node];
    if(l==r)
    return 0;
    int mid=(l+r)>>1;
    node<<=1;
    return query(l,mid,node)+query(mid+1,r,node+1);
}
int main ()
{
    int i,j,test,t=1,q,c;
    sci1(test);
    while(test--)
    {
        sci2(n,q);
        clr(uq);
        clr(ma);
        build(1,n,1);
        c=1;
        for(i=1; i<=n; i++)
            sci1(j),uq.pb( {j,i,c,0});
        c=2;
        change=1;
        while(change<=q)
        {
            sci2(i,j);
            if(i>j)swap(i,j);
            uq.pb( {i,j,c,change++});
        }
        sort_m(uq);
        for(i=0; i<sz(uq); i++)
        {
            if(uq[i].c==2)
                {
                    maan=uq[i].l;
                    indx=uq[i].r;
                    ans[uq[i].s]=query(1,n,1);
                }
            else
            {
                indx=uq[i].r;
                maan=uq[i].l;
                change=1;
                update(1,n,1);
                if(ma.find(maan)!=ma.end())
                    {
                        change=-1;
                        indx=ma[maan];
                        update(1,n,1);
                    }
                ma[maan]=uq[i].r;
            }
        }
        printf("Case %d:\n",t++);
        for(i=1;i<=q;i++)
        printf("%d\n",ans[i]);
    }
    return 0;
}

