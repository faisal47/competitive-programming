#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;
int arr[100000000];
int main ()
{
    int t=0,n=0,flag1=0,i;
    map<int,int>m;
    map<int,int>::iterator it;
    while(cin>>n)
    {
            if(m.find(n)==m.end())
                {
                    m[n]=1;
                    arr[t++]=n;
                }
            else
                m[n]+=1;
    }
    for(i=0;i<t;i++)
    {
        cout<<arr[i]<<" ";
        it=m.find(arr[i]);
        cout<<it->second<<endl;
    }
    return 0;
}
