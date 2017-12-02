#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map>
#include <ctype.h>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;
struct cos
{
   long long int num,c;
};
bool sign(cos a,cos b)
{
    return a.c<b.c;
}
int main ()
{
    vector<cos>cost;
    vector<long long int>cus;
    cos cos1;
    long long int n,d,a,b,x,y,test,d1,i;
    while(cin>>n>>d)
    {
        test=0;
        cin>>a>>b;
        cost.clear();
        cus.clear();
        for(i=1;i<=n;i++)
        {
            cin>>x>>y;
            x*=a;y*=b;x+=y;
            cos1.num=i;
            cos1.c=x;
            cost.push_back(cos1);
        }
        d1=0;
        sort(cost.begin(),cost.end(),sign);
        for(i=0;i<cost.size();i++)
        {
            if(d1+cost[i].c<=d)
            {
                d1+=cost[i].c;
                cus.push_back(cost[i].num);
            }
            else
            {
                break;
            }
        }
        cout<<cus.size()<<endl;
        for(i=0;i<cus.size();i++)
        {
            if(test++)
            cout<<" ";
            cout<<cus[i];
        }
        if(test)
        cout<<endl;
    }
    return 0;
}