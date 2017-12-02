#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<int>v;
vector<int>prime;
map<int,int>m;
int prime_check[10000010],flag;
void bt(int n,int p)
{
    int i;
    if(p==1)
    {
        if(prime_check[n]==1)
        {
            cout<<v[0];
            for(i=1;i<3;i++)
            cout<<" "<<v[i];
            cout<<" "<<n;
            cout<<endl;
            flag=1;
        }
        return;
    }
    int start=-1;
    for(i=n-1;i>=0;i--)
    {
        if(prime_check[i]==1)
        {
            start=m[i];
            break;
        }
    }
    for(i=start;i>=0;i--)
    {
        v.push_back(prime[i]);
        bt(n-prime[i],p-1);
        if(flag==1)
        return;
        v.pop_back();
    }
}
int main ()
{
    int i,n,j,k=0;
    prime_check[2]=1;
    prime.push_back(2);m[2]=k++;
    for(i=3;i<10000005;i+=2)
    {
        if(prime_check[i]==0)
        {
            prime.push_back(i);
            prime_check[i]=1;
            m[i]=k++;
            for(j=i+i;j<10000005;j+=i)
            prime_check[j]=2;
        }
    }
    while(cin>>n)
    {
        flag=0;
        v.clear();
        if(n<8)
        cout<<"Impossible."<<endl;
        else bt(n,4);
    }
    return 0;
}
