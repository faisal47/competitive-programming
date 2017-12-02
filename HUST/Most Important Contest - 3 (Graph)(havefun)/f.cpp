#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

typedef long long ll;
#define mt 50010

vector<ll>mst;

struct d
{
    int s,e;
    ll dis;
};
vector<d>dist;

ll durotto(ll x1,ll y1,ll x2,ll y2)
{
    return ((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2));
}

ll par[mt];

ll find_par(ll i)
{
    if(par[i]==i)
        return i;
    return par[i]=find_par(par[i]);
}
void make_par(ll i)
{
    ll u=find_par(dist[i].s);
    ll v=find_par(dist[i].e);
    if(u==v)
        return;
    par[u]=v;
    mst.push_back(dist[i].dis);
}
bool sign(d a, d b)
{
    return a.dis<b.dis;
}
int main ()
{
    ll t,arr[mt][2],n,p,i,j;
    d d1;
    cin>>t;
    while(t--)
    {
        dist.clear();
        cin>>n;
        p=0;
        while(cin>>i)
        {
            if(i==-1)
                break;
            p++;
            arr[p][0]=i;
            cin>>arr[p][1];
            par[p]=p;
        }
        for(i=1; i<=p; i++)
            for(j=i+1; j<=p; j++)
            {
                d1.s=i;
                d1.e=j;
                d1.dis=durotto(arr[i][0],arr[i][1],arr[j][0],arr[j][1]);
                dist.push_back(d1);
            }

        mst.clear();
        sort(dist.begin(),dist.end(),sign);
        for(i=0; i<dist.size(); i++)
            make_par(i);

        ll res=mst[mst.size()-n];
        i=sqrt(res);
        if(i*i < res)
            i++;
res=i;
        printf("%lld\n",res);
    }
    return 0;
}
