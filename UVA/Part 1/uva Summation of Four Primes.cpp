#include <stdio.h>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
long long int prime_check[10000010];
int main ()
{
    long long int i,flag,j;
    vector<long long int>p;
    prime_check[2]=1;
    p.push_back(2);
    for(i=3; i<sqrt(10000005); i+=2)
    {
        if(prime_check[i]==0)
        {
            p.push_back(i);
            prime_check[i]=1;
            for(j=i+i; j<sqrt(10000005); j+=i)
                prime_check[j]=2;
        }
    }
    long long int n,k,l,d,e,f,g;
    while(cin>>n)
    {
        if(n<8)
        {
            cout<<"Impossible.\n";
            continue;
        }
        flag=0;
        for(i=0; i<p.size(); i++)
        {
            d=p[i];
            if(flag==1||d>n/4)
                break;
            for(j=i; j<p.size(); j++)
            {
                e=n-d;
                if(flag==1||p[j]>e/3)
                    break;
                for(k=j; k<p.size(); k++)
                {
                    f=n-(p[i]+p[j]);
                    if(flag==1||p[k]>f/2)
                        break;
                    f=p[i]+p[j]+p[k];
                    g=n-f;
                    if(prime_check[g]==1)
                    {
                        flag=1;
                        printf("%lld %lld %lld %lld\n",p[i],p[j],p[k],g);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
