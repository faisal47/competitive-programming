#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct data
{
    int node,dist;
    bool operator <
};
vector<int>node[15],cost[15];
int n,dist[15],par[15];
void dj(int start)
{

    return;
}
int main ()
{
    int test=1,a,b,i,c;
    while(cin>>n)
    {
        if(n==0)
        break;
        for(i=1;i<=n;i++)
        {
            cin>>c;
            cost[i].clear();
            node[i].clear();
            while(c--)
            {
                cin>>a>>b;
                node[i].push_back(a);
                cost[i].push_back(b);
            }
        }
        cin>>a>>b;
        dj(a);
    }
    return 0;
}
