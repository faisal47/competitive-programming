#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
long int arr1[100000000],I[100000000];
int l[100000000];
long int inf=123456789;
vector<int>v;
int main ()
{
    int c=1,n,i,lis=0,j,pos;
    I[0]=-inf;
    while(cin>>n)
    {
        arr1[c]=n;
        l[c]=1;
        I[c]=inf;
        c++;
    }
    int low,mid,high;
    for(i=1;i<=c;i++)
    {
        low=0;high=lis;
        while(low<=high)
        {
            mid=(high+low)/2;
            if(I[mid]<arr1[i])
            low=mid+1;
            else
            high=mid-1;
        }
        I[low]=arr1[i];
        l[i]=low;
        if(lis<low)
        {
            pos=i;
            lis=low;
        }
    }
    v.clear();
    cout<<lis<<endl;
    cout<<"-"<<endl;
    for(i=pos; i>0; i--)
    {
        if(l[i]==lis)
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

