#include <stdio.h>
#include <iostream>
using namespace std;
struct seg
{
    int s,e,mini;
};
int arr[100010],minix;
seg segment[300030];
void maketree(int s,int e,int nod)
{
    segment[nod].s=s;
    segment[nod].e=e;
    if(s==e)
    {
        segment[nod].mini=arr[s];
        return;
    }
    int mid=(s+e)/2;
    maketree(s,mid,2*nod);
    maketree(mid+1,e,2*nod+1);
    segment[nod].mini=min(segment[2*nod].mini,segment[2*nod+1].mini);
}
void q(int s,int e,int nod)
{
    if(segment[nod].e<s||segment[nod].s>e)
    return;
    else if(segment[nod].s>=s&&segment[nod].e<=e)
    {
        minix=min(minix,segment[nod].mini);
        return;
    }
    q(s,e,2*nod);
    q(s,e,2*nod+1);
}
int main ()
{
    int test,t,a,b,i,t1;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        printf("Case %d:\n",t);
        cin>>a>>t1;
        for(i=1;i<=a;i++)
        scanf("%d",&arr[i]);
        maketree(1,a,1);
        while(t1--)
        {
            scanf("%d %d",&a,&b);
            minix=100050;
            q(a,b,1);
            printf("%d\n",minix);
        }
    }
    return 0;
}
