#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
struct seg
{
    int s,e,c;
};
seg segment[300030];
void maketree(int s,int e,int nod)
{
    int mid=(s+e)/2;
    segment[nod].s=s;
    segment[nod].e=e;
    segment[nod].c=0;
    if(s==e)
    return;
    maketree(s,mid,nod*2);
    maketree(mid+1,e,2*nod+1);
}
void update(int s,int e,int nod)
{
    if(segment[nod].e<s||segment[nod].s>e)
    return;
    if(segment[nod].s==segment[nod].e)
    {
        segment[nod].c++;
        return;
    }
    if(s<=segment[nod].s&&e>=segment[nod].e)
    {
        segment[nod].c++;
    }
    update(s,e,2*nod);
    update(s,e,2*nod+1);
}
int q(int pos,int nod)
{
    if(segment[nod].s==segment[nod].e)
    return segment[nod].c;
    int mid=(segment[nod].s+segment[nod].e)/2;
    if(pos<=mid)
    q(pos,nod*2);
    else
    q(pos,2*nod+1);
}
int main ()
{
    char arr[100010],z;
    int test,t,t1,a,b,len;
    scanf("%d",&test);
    scanf("%c",&z);
    for(t=1;t<=test;t++)
    {
        printf("Case %d:\n",t);
        gets(arr);
        len=strlen(arr);
        maketree(0,len-1,1);
        cin>>t1;
        while(t1--)
        {
            cin>>z;
            if(z=='I')
            {
                cin>>a>>b;
                update(a-1,b-1,1);
            }
            else
            {
                cin>>a;
                b=q(a-1,1);
                if(b%2==0)
                cout<<arr[a-1]<<endl;
                else
                {
                    if(arr[a-1]=='1')
                    cout<<'0'<<endl;
                    else
                    cout<<'1'<<endl;
                }
            }
        }
        scanf("%c",&z);
    }
    return 0;
}
