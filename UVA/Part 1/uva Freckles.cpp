#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
struct inp
{
    double x,y;
};
struct dis
{
  int start,end;
  double cost;
};
vector<dis>distanc;
double result;
int parent[105];
bool sign (dis a, dis b)
{
    return a.cost<b.cost;
}
int find_parent(int i)
{
    if(parent[i]==i)
    return i;
    else
    return parent[i]=find_parent(parent[i]);
}
void make_parent(int i)
{
    int u=find_parent(distanc[i].start);
    int v=find_parent(distanc[i].end);
    if(u==v)
    return;
    parent[u]=v;
    result+=distanc[i].cost;
}
int main ()
{
    vector<inp>input;
    dis distance1;
    inp input1;
    int test,n,i,j,flag=0;
    cin>>test;
    while(test--)
    {
        if(flag)
        cout<<endl;
        flag=1;
        input.clear();
        distanc.clear();
        cin>>n;
        for(i=0;i<n;i++)
        {
            parent[i]=i;
            cin>>input1.x>>input1.y;
            input.push_back(input1);
        }
        for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
        {
            distance1.start=i;
            distance1.end=j;
            distance1.cost=sqrt(pow((input[i].x-input[j].x),2.)+pow((input[i].y-input[j].y),2.));
            distanc.push_back(distance1);
        }
        sort(distanc.begin(),distanc.end(),sign);
        result=0;
        for(i=0;i<distanc.size();i++)
        make_parent(i);
        printf("%.2lf\n",result);
    }
    return 0;
}
