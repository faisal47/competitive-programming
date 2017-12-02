#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int prime[1010];
int main ()
{
    prime[2]=1;
    prime[1]=1;
    int i,j;
    vector<int>v;
    for(i=3;i<1010;i+=2)
    {
        if(prime[i]==0)
        {
            prime[i]=1;
            for(j=i+i;j<1010;j+=i)
            prime[j]=2;
        }
    }
    int n,c,d,s,e;
    while(cin>>n>>c)
    {
        v.clear();
        for(i=1;i<=n;i++)
        if(prime[i]==1)
        v.push_back(i);
        s=v.size();
        if((s%2)==0)
        d=c*2;
        else
        d=(c*2)-1;
        if(d>=s)
        {
            printf("%d %d:",n,c);
            for(i=0;i<s;i++)
            cout<<" "<<v[i];
        }
        else
        {
//            if((d%2)==0)
//            {
                j=s/2;
                e=d/2;
                j-=e;
                i=0;
                printf("%d %d:",n,c);
                while(i<d)
                {
                    i++;
                    cout<<" "<<v[j++];
                }
//            }
//            else
//            {
//
//            }
        }
        cout<<endl<<endl;;
    }
    return 0;
}
