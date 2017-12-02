#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int arr[100005],pro;
struct seg
{
    int s,e,p;
};
seg segment[300015];
vector<char>out;
void maketree(int s,int e,int nod)
{
    segment[nod].s=s;
    segment[nod].e=e;
    if(s==e)
    {
        segment[nod].p=arr[s];
        return;
    }
    int mid=(s+e)/2;
    maketree(s,mid,nod*2);
    maketree(mid+1,e,(nod*2)+1);
    segment[nod].p=(segment[nod*2].p)*(segment[(nod*2)+1].p);
}
void change(int pos,int val,int nod)
{
    if(segment[nod].s==segment[nod].e)
    {
        segment[nod].p=val;
        return;
    }
    else if(pos>segment[nod].e||pos<segment[nod].s)
    {
        return;
    }
    int mid=(segment[nod].s+segment[nod].e)/2;
    if(pos<=mid)
    change(pos,val,nod*2);
    else
    change(pos,val,(nod*2)+1);
    segment[nod].p=(segment[nod*2].p)*(segment[(nod*2)+1].p);
}
void findp(int s,int e,int nod)
{
    if(segment[nod].s>=s&&segment[nod].e<=e)
    {
        pro*=segment[nod].p;
        return;
    }
    else if(segment[nod].e<s||segment[nod].s>e)
    {
        return;
    }
    else
    {
        findp(s,e,nod*2);
        findp(s,e,(nod*2)+1);
    }
}
int main ()
{
    int n,i,a,m,b;
    char c;
    while(cin>>n>>m)
    {
        //scanf("%c",&c);
        out.clear();
        for(i=1; i<=n; i++)
        {
//            scanf("%d",&a,&c);
            cin>>a;
            if(a<0)
                arr[i]=-1;
            else if(a>0)
                arr[i]=1;
            else
                arr[i]=0;
        }
       // scanf("%c",&c);
        maketree(1,n,1);
        for(i=1; i<=m; i++)
        {
//            scanf("%c %d %d",&c,&a,&b);
            cin>>c>>a>>b;
            if(c=='C')
            {
                if(b<0)
                    b=-1;
                else if(b>0)
                    b=1;
                else
                    b=0;
                    change(a,b,1);
//                arr[a]=b;
//                maketree(1,n,1);
            }
            else
            {
                pro=1;
                findp(a,b,1);
                //cout<<pro<<endl;
                if(pro<0)
                out.push_back('-');
                else if(pro>0)
                out.push_back('+');
                else
                out.push_back('0');
            }
        }
        for(i=0;i<out.size();i++)
        cout<<out[i];
        cout<<endl;
    }
    return 0;
}
