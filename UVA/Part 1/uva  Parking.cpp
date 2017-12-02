#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main ()
{
    int a,i,test,n,d;
    vector<int>v;
    cin>>test;
    while(test--)
    {
        cin>>n;
        v.clear();
        while(n--)
        {
            cin>>a;
            v.push_back(a);
        }
        d=0;
        sort(v.begin(),v.end());
        for(i=0;i<v.size()-1;i++)
        d+=(v[i+1]-v[i]);
        d*=2;
        cout<<d<<endl;
    }
    return 0;
}
