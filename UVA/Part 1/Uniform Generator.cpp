#include <bits/stdc++.h>
#define scll2(a,b) scanf("%lld %lld",&a,&b)
using namespace std;
typedef long long ll;
int main ()
{
    ll m,n,c,seed,j;
    while(scll2(m,n)==2)
    {
        j=0;
        seed=0;seed=(seed + m)%n;c=1;
        while(j!=seed)
        {
            seed=(seed + m)%n;c++;
        }
        printf("%10lld%10lld    ",m,n);
        if(c==n)
        cout<<"Good Choice\n\n";
        else
        cout<<"Bad Choice\n\n";
    }
    return 0;
}

