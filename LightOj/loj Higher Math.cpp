#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main ()
{
    vector<int>v;
    int test,t,a,i;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        i=3;
        v.clear();
        while(i--)
        {
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        if(((v[0]*v[0])+(v[1]*v[1]))==(v[2]*v[2]))
        printf("Case %d: yes\n",t);
        else
        printf("Case %d: no\n",t);
    }
    return 0;
}
