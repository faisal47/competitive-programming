#include <bits/stdc++.h>
#define mt 1000100
using namespace std;
int lp[3*mt],com,s,e,cou[3*mt][3],majhe1,majhe2,majhe3;
void push_down(int node,int a)
{
    majhe1=cou[node][0];
    majhe2=cou[node][1];
    majhe3=cou[node][2];
    if(a==1)
    {
        cou[node][1]=majhe1;
        cou[node][2]=majhe2;
        cou[node][0]=majhe3;
    }
    else if(a==2)
    {
        cou[node][2]=majhe1;
        cou[node][0]=majhe2;
        cou[node][1]=majhe3;
    }
    node<<=1;
    lp[node]=(lp[node]+a)%3;
    lp[node+1]=(lp[node+1]+a)%3;
    lp[node>>1]=0;
}
void push_up(int node)
{
    cou[node][0]=cou[node<<1][0]+cou[(node<<1)+1][0];
    cou[node][1]=cou[node<<1][1]+cou[(node<<1)+1][1];
    cou[node][2]=cou[node<<1][2]+cou[(node<<1)+1][2];
}
void init(int node,int l,int r)
{
    if(l>r)return;
    lp[node]=0;
    push_down(node,0);
    if(l==r)
    {
        cou[node][1]=cou[node][2]=0;
        cou[node][0]=1;
        return;
    }
    int mid=(l+r)>>1;
    init(node<<1,l,mid);
    init((node<<1)+1,mid+1,r);
    push_up(node);
}
int maan_de(int node,int l,int r)
{
    push_down(node,lp[node]);
    if(l>e || r<s)return 0;
    if(l>=s && r<=e)
        return cou[node][0];
    node<<=1;
    int mid=(l+r)>>1;
    return maan_de(node,l,mid)+maan_de(node+1,mid+1,r);
}
void update(int node,int l,int r)
{
    push_down(node,lp[node]);
    if(l>e || r<s)return;
    if(l>=s && r<=e)
    {
        push_down(node,1);
        return;
    }
    int mid=(l+r)>>1;
    update(node<<1,l,mid);
    update((node<<1)+1,mid+1,r);
    push_up(node);
}
int main ()
{
    int t=1,test,q,n;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&q);
        n--;
        init(1,0,n);
        printf("Case %d:\n",t++);
        while(q--)
        {
            scanf("%d %d %d",&com,&s,&e);
            if(com)
                printf("%d\n",maan_de(1,0,n));
            else
                update(1,0,n);
        }
    }
    return 0;
}
