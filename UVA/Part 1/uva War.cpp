#include <stdio.h>
#include <iostream>
using namespace std;
int parents[10010],c,x,y,sign[10010];
void dj()
{
    int u=find_parents(x);
    int v=find_parents(y);
    if(u!=v)
    {

    }
}
int main ()
{
    int i;
    cin>>x;
    for(i=0;i<x;i++)
    {
        parents[i]=i;sign[i]=0;
    }
    while(cin>>c>>x>>y)
    {
        if(c==0&&x==0&&y==0)
        break;
        dj();
    }
    return 0;
}
