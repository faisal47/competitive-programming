#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

struct e
{
    int u,v,w;
};

vector<e>vi;
int n,inf=123456789,d[1010];
bool flag;
void bf()
{
    // cout<<"jihs"<<endl;
    int i,j;
    for(i=0; i<n; i++)
        d[i]=inf;
    d[n]=0;
    // cout<<"jihs"<<endl;
    for(i=0; i<n; i++)
    {
        for(j=0; j<vi.size(); j++)
        {
            if((d[vi[j].u]+vi[j].w)<d[vi[j].v])
                d[vi[j].v]=(d[vi[j].u]+vi[j].w);
        }
    }
    for(i=0; i<vi.size(); i++)
    {
       // cout<<d[i]<<endl;
        if(d[vi[i].v]>(d[vi[i].u]+vi[i].w))
        {
           //cout<<d[vi[i].v]<<" "<<d[vi[i].u]<<" "<<vi[i].w<<endl;
            flag=1;
            break;
        }
    }
    return;
}
int main ()
{
    int test,i,m;
    e ed;
    cin>>test;
    while(test--)
    {
        vi.clear();
        cin>>n>>m;
        while(m--)
        {
            cin>>ed.u>>ed.v>>ed.w;
            vi.push_back(ed);
        }
        for(i=0; i<n; i++)
        {
            ed.u=n;
            ed.v=i;
            ed.w=0;
            vi.push_back(ed);
        }
        flag=0;
        bf();
        if(flag==0)
            cout<<"not possible"<<endl;
        else
            cout<<"possible"<<endl;
    }
    return 0;
}
