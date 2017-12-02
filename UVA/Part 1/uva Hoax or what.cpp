#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main ()
{
    vector<int>v1;
    vector<int>v2;
   long long int i,a,k,n,cost;bool flag;
    while(cin>>n)
    {
        if(n==0)
        break;
        v1.clear();
        v2.clear();
        flag=0;
        cost=0;
        while(n--)
        {
          cin>>k;
          if(flag==0)
          {
              while(k>0)
              {
                  k--;
                  cin>>a;
                  v1.push_back(a);
              }
              sort(v1.begin(),v1.end());
              cost+=(v1[v1.size()-1]-v1[0]);
              for(i=1;i<v1.size()-1;i++)
              v2.push_back(v1[i]);v1.clear();
              flag=1;
          }
          else
          {
              while(k>0)
              {
                  k--;
                  cin>>a;
                  v2.push_back(a);
              }
              sort(v2.begin(),v2.end());
              cost+=(v2[v2.size()-1]-v2[0]);
              for(i=1;i<v2.size()-1;i++)
              v1.push_back(v2[i]);v2.clear();
              flag=0;
          }
        }
        cout<<cost<<endl;
    }
    return 0;
}
