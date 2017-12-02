#include <string.h>
#include <string>
#include <stdio.h>
#include <iostream>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define mp make_pair
#define pii pair<int,int>
#define fs first
#define sc second
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define sort_n(a) sort(a.begin(),a.end())
#define sort_m(a) sort(a.begin(),a.end(),comp)
#define fop freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sz(a) a.size()
#define mt 1000010
using namespace std;
int jog[4*mt][2],lp[4*mt],n,a,b;
void build(int s,int e,int node)
{
    if(s==e)
    {
        lp[node]=0;
        jog[node][0]=(e-s)+1;
        jog[node][1]=0;
        return;
    }
    lp[node]=0;
    jog[node][0]=(e-s)+1;
    jog[node][1]=0;
    node<<=1;
    int mid=(s+e)>>1;
    build(s,mid,node);
    build(mid+1,e,node+1);
}
int change(int s,int e,int node)
{
    if(e<a || s>b)return jog[node][1];
    if(s>=a && e<=b)
    {
        lp[node]=(lp[node]+1)&1;
        int c=1<<node;
        lp[c]=(lp[node]+lp[c])&1;
        lp[c+1]=(lp[node]+lp[c+1])&1;
        if(lp[node])
            swap(jog[node][0],jog[node][1]);
        return jog[node][1];
    }
   int c=1<<node;
    int mid=(s+e)>>1;
    lp[c]=(lp[node]+lp[c])&1;
    lp[c+1]=(lp[node]+lp[c+1])&1;
    if(lp[node])
        swap(jog[node][0],jog[node][1]);
    lp[node]=0;
    return jog[node][1]= change(s,mid,c)+change(mid+1,e,c+1);

}
int maan_de(int s,int e,int node)
{
    if(e<a || s>b)return 0;
    if(s>=a && e<=b)
    {
        int c=1<<node;
        lp[c]=(lp[node]+lp[c])&1;
        lp[c+1]=(lp[node]+lp[c+1])&1;
        if(lp[node])
            swap(jog[node][0],jog[node][1]);
        return jog[node][1];
    }
    int c=1<<node;
    int mid=(s+e)>>1;
    lp[c]=(lp[node]+lp[c])&1;
    lp[c+1]=(lp[node]+lp[c+1])&1;
    if(lp[node])
        swap(jog[node][0],jog[node][1]);
    lp[node]=0;
    return jog[node][1]= change(s,mid,c)+change(mid+1,e,c+1);
}
int main ()
{
    int m,c;
    while(sci2(n,m))
    {
        build(1,n,1);
        while(m--)
        {
            sci3(c,a,b);
            if(!c)
            {
                change(1,n,1);
            }
            else
            {
                printf("%d\n",maan_de(1,n,1));
            }
        }
    }
    return 0;
}

