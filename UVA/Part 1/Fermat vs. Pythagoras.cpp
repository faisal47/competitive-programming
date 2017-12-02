#include <bits/stdc++.h>
#define scll1(a) scanf("%lld",&a)
using namespace std;
typedef long long ll;
int flag1[1000010],flag2[1000010];
double m;
int main ()
{
    ll i,j,n;
    for(i=1; i<1000005; i++)
        for(j=i+1; j<1000005; j++)
        {
            n=pow(i,2)+pow(j,2);
            m=sqrt(n);
            if(__gcd(i,j)==1 && ((j-i)&1))
                flag1[n]=1;
            flag2[n]=1;
            if((int)m==m)
            flag2[(int)m]=1;
        }
    for(i=0; i<1000005; i++)
        flag1[i+1]+=flag1[i];
    while(scll1(n)==1)
    cout<<flag1[n]<<endl;
    return 0;
}

