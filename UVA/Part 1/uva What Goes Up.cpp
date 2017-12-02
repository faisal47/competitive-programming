#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
long int arr1[100000000];
int arr2[100000000];
vector<int>v;
int main ()
{
    int c=1,n,i,lis=1,j,pos;
    while(cin>>n)
    {
        arr1[c]=n;
        arr2[c]=1;
        c++;
    }
    for(i=1; i<c; i++)
    {
        for(j=i+1; j<c; j++)
        {
            if(arr1[j]>arr1[i])
            {
                if(arr2[j]<(arr2[i]+1))
                {
                    arr2[j]=(arr2[i]+1);
                    lis=max(lis,arr2[j]);
                    pos=j;
                }
            }
        }
    }
    v.clear();
    cout<<lis<<endl;
    cout<<"-"<<endl;
    for(i=pos; i>0; i--)
    {
        if(arr2[i]==lis)
        {
            v.push_back(arr1[i]);
            lis--;
        }
        if(lis<1)
            break;
    }
    for(i=v.size()-1; i>=0; i--)
        cout<<v[i]<<endl;
    return 0;
}
