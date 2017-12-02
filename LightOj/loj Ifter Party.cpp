#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int main ()
{
    vector<int>v;
    int test,t,m,n,end,i;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        cin>>m>>n;
        m-=n;
        v.clear();
        end=sqrt(m);
        printf("Case %d:",t);
        for(i=1;i<=end;i++)
        {
            if(m%i==0)
            {
                if(i>n)
                v.push_back(i);
                if((m/i)>n&&((m/i)!=i))
                v.push_back(m/i);
            }
        }
        if(v.size()==0)
        cout<<" impossible"<<endl;
        else
        {
            sort(v.begin(),v.end());
            for(i=0;i<v.size();i++)
            cout<<" "<<v[i];
            cout<<endl;
        }
    }
    return 0;
}
