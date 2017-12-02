#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int coun;
bool comp(int a,int b)
{
    if(a<b)
    {
        coun++;
        return 1;
    }
    else
    return 0;
}
int main ()
{
    vector<int>v;
    int n;
    while(cin>>n)
    {
        if(n==0)
        break;
        v.clear();
        while(n--)
        {
            cin>>coun;
            v.push_back(coun);
        }
        coun=0;
        sort(v.begin(),v.end(),comp);
//        for(int i=0;i<v.size();i++)
//        cout<<" "<<v[i]<<" "<<endl;
        cout<<coun<<endl;
    }
    return 0;
}
