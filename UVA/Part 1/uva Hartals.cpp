#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main ()
{
    int flag[4000];
    vector<int>v;
    int n,test,i,a,c,m,j;
    cin>>test;
    while(test--)
    {
        v.clear();
        c=0;
        a;
        cin>>n;
        for(i=1; i<=n; i++)
            flag[i]=0;
        cin>>m;
        while(m--)
        {
            cin>>a;
            v.push_back(a);
        }
        for(i=0; i<v.size(); i++)
        {
            a=v[i];
            for(j=a; j<=n; j+=a)
            {
                flag[j]=1;
                //cout<<" j="<<j<<endl;
            }
        }
        for(i=6; i<=n; i+=7)
        {
            flag[i]=2;
            flag[i+1]=2;
        }
        for(i=1; i<=n; i++)
            if(flag[i]==1)
                c++;
        cout<<c<<endl;
    }
    return 0;
}
