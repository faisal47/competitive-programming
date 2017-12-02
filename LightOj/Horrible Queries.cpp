#include <stdio.h>
#include <iostream>
#define scll1(a) scanf("%lld",&a)
#define scll2(a,b) scanf("%lld %lld",&a,&b)
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define scll3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define sz 100010
using namespace std;
typedef long long ll;
struct arr1
{
    ll sum,jog;
};
arr1 arr[3*sz];
int a,b,jog;
void build(int s,int e,int node)
{
    if(s==e)
    {
        arr[node].sum=0;
        arr[node].jog=0;
        return;
    }
    arr[node].sum=0;
    arr[node].jog=0;
    node<<=1;
    int mid=(s+e)>>1;
    build(s,mid,node);
    build(mid+1,e,node+1);
}
void change(int s,int e,int node)
{
    if(e<a || s>b)
    return;
    if(s>=a && e<=b)
    {
        arr[node].sum+=(e-s+1)*jog;
        arr[node].jog+=jog;
        return;
    }
    int c=node<<1,mid=(s+e)>>1;
    arr[c].sum+=(mid-s+1)*arr[node].jog;
    arr[c].jog+=arr[node].jog;
    arr[c+1].sum+=(e-mid)*arr[node].jog;
    arr[c+1].jog+=arr[node].jog;
    arr[node].jog=0;
    change(s,mid,c);
    change(mid+1,e,c+1);
    arr[node].sum=arr[c].sum+arr[c+1].sum;
}
ll maan_de(int s,int e,int node)
{
    if(e<a || s>b)
    return 0;
    if(s>=a && e<=b)
    {
        return arr[node].sum;
    }
    int c=node<<1,mid=(s+e)>>1;
    arr[c].sum+=(mid-s+1)*arr[node].jog;
    arr[c].jog+=arr[node].jog;
    arr[c+1].sum+=(e-mid)*arr[node].jog;
    arr[c+1].jog+=arr[node].jog;
    arr[node].jog=0;
    return maan_de(s,mid,c)+maan_de(mid+1,e,c+1);
}
int main ()
{
    int test,t=1,q,n,command;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&q);
        build(0,n-1,1);
        printf("Case %d:\n",t++);
        while(q--)
        {
            sci1(command);
            if(command)
            {
                sci2(a,b);
                printf("%lld\n",maan_de(0,n-1,1));
            }
            else
            {
                sci3(a,b,jog);
                change(0,n-1,1);
            }
        }
    }
    return 0;
}

