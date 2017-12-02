#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main ()
{
    vector<int>v;
    vector<int>s;
    bool flag,eflag,flag1[1010];
    int n,i,a,j;
    while(cin>>n)
    {
        if(n==0)
        break;
        eflag=0;
        while(1)
        {
            v.clear();
            s.clear();
            flag=0;
            for(i=0;i<n;i++)
            {
              cin>>a;
              if(a==0&&i==0)
              {
                  eflag=1;
                  break;
              }
              v.push_back(a); flag1[a]=0;
            }
            if(eflag==1)
            break;
            for(i=0;i<n;i++)
            {
                if(s.size()==0)
                {
                    for(j=1;j<v[i];j++)
                    if(flag1[j]==0)
                    {
                        flag1[j]=1;
                        s.push_back(j);
                    }
                }
                else if(s[s.size()-1]==v[i])
                {
                    s.pop_back();
                }
                else if(flag1[v[i]]==0)
                {
                    for(j=1;j<v[i];j++)
                    if(flag1[j]==0)
                    {
                        flag1[j]=1;
                        s.push_back(j);
                    }
                }
                else
                {
                    flag=1;
                    break;
                }
                flag1[v[i]]=1;
            }
            if(flag==1)
            cout<<"No"<<endl;
            else
            cout<<"Yes"<<endl;
        }
        cout<<endl;
    }
    return 0;
}
