#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>input;
vector<int>v;
vector<int>result;
bool color[25];
int sum,s,start,rsum,flag;
void bt()
{
     flag=0;
        int z=0;
     for(int i=0;i<v.size();i++)
        z+=v[i];
        if(z>rsum&&z<=sum)
        {
            rsum=z;
            result.clear();
            z=v.size();
            result.resize(z);
            copy(v.begin(),v.begin()+z,result.begin());
        }
    for(int i=0;i<input.size();i++)
    {
        flag=0;
        if(color[i]==0)
        {
            for(int j=i+1;j<input.size();j++)
            {
                if(color[j]==1)
                {
                    i=j;
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            continue;
            color[i]=1;
            v.push_back(input[i]);
            bt();
            color[i]=0;
            v.pop_back();
        }
    }
    return;
}
int main ()
{
    int m,i,j;
    while(cin>>sum>>m)
    {
        rsum=0;
        input.clear();
        result.clear();
        v.clear();
        while(m--)
        {
            cin>>i;
            input.push_back(i);
        }
        bt();
        for(i=0;i<result.size();i++)
        printf("%d ",result[i]);
        printf("sum:%d\n",rsum);
    }
    return 0;
}
