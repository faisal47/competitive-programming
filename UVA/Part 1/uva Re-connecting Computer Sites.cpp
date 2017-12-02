#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct connections
{
    int start,end,cost;
};
vector<connections>con;
connections con1;
int parents[1000010],late_total;
int find_parents(int i)
{
   if(parents[i]==i)
   return i;
   else
   return parents[i]=find_parents(parents[i]);
}
void make_parents(int i)
{
    int u=find_parents(con[i].start);
    int v=find_parents(con[i].end);
    if(u==v)
    return;
    parents[u]=v;
    late_total+=con[i].cost;
}
bool sign(connections a,connections b)
{
    return a.cost<b.cost;
}
int main ()
{
    int pre_total,a,b,c,n,i,m,flag=0;
    while(cin>>m)
    {
        if(flag)
        cout<<endl;
        flag=1;
        for(i=1;i<=m;i++)
        parents[i]=i;
        n=m;n--;
        con.clear();
        pre_total=0;
        while(n--)
        {
            cin>>a>>b>>c;
            pre_total+=c;
        }
        cin>>n;
        while(n--)
        {
            cin>>con1.start>>con1.end>>con1.cost;
            con.push_back(con1);
        }
        cin>>n;
        while(n--)
        {
            cin>>con1.start>>con1.end>>con1.cost;
            con.push_back(con1);
        }
        sort(con.begin(),con.end(),sign);
        late_total=0;
        for(a=0;a<con.size();a++)
        make_parents(a);
        cout<<pre_total<<endl<<late_total<<endl;
    }
    return 0;
}
