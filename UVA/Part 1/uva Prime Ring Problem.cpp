#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
int prime[40],n;
bool color[20];
vector<int>v;
void bt()
{
    if(v.size()==n)
    {
        if(prime[v[n-1]+1]==1)
        {
            cout<<"1";
        for(int i=1; i<n; i++)
            printf(" %d",v[i]);
        cout<<endl;
        }
        return;
    }
    for(int i=2; i<=n; i++)
    {
        int s=v.size()-1;
        if(prime[v[s]+i]==1)
        {
            if(color[i]==0)
            {
                color[i]=1;
                v.push_back(i);
                bt();
                color[i]=0;
        v.pop_back();
            }
        }
    }
    return;
}
int main ()
{
    int i,j;
    prime[2]=1;
    for(i=3; i<40; i+=2)
    {
        if(prime[i]==0)
        {
            prime[i]=1;
            for(j=i+i; j<40; j+=i)
                prime[j]=2;
        }
    }
    i=0;
    while(cin>>n)
    {
        if(i)
            cout<<endl;
        memset(color,0,sizeof(color));
        v.clear();
        v.push_back(1);
        i++;
        printf("Case %d:\n",i);
        bt();
    }
    return 0;
}
