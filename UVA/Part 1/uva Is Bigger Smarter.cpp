#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct d
{
    int ind,w,iq;
};
bool sign(d a, d b)
{
    if(a.w==b.w)
    return a.iq>b.iq;
    return a.w<b.w;
}
int lis[1010];
int main ()
{
    vector<d>data;
    vector<int>ans;
    d d1;
    lis[0]=1;
    int i=1,iq,w,j,LIS=1;
    while(cin>>w>>iq)
    {
        d1.ind=i;d1.w=w;d1.iq=iq;
        data.push_back(d1);
        lis[i++]=1;
    }
    sort(data.begin(),data.end(),sign);
//    for(i=0;i<data.size();i++)
//    cout<<data[i].ind<<" "<<data[i].w<<" "<<data[i].iq<<endl;
    for(i=0;i<data.size();i++)
    for(j=i+1;j<data.size();j++)
    {
        if(data[j].iq<data[i].iq && data[j].w>data[i].w)
        {
            if(lis[j]<lis[i]+1)
            {
                lis[j]=lis[i]+1;
                LIS=max(LIS,lis[j]);
            }
        }
    }
    int flag=0;
    for(i=data.size()-1;i>=0;i--)
    {
        if(lis[i]==LIS && flag==0)
        {
            j=i;
            flag=1;
            ans.push_back(data[i].ind);
            LIS--;
        }
        else if(lis[i]==LIS && flag==1 && data[j].w>data[i].w)
        {
            j=i;
            ans.push_back(data[i].ind);
            LIS--;
        }
        if(!LIS)
        break;
    }
    cout<<ans.size()<<endl;
    for(i=ans.size()-1;i>=0;i--)
    cout<<ans[i]<<endl;
    return 0;
}
