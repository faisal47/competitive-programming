#include <bits/stdc++.h>
#define scll2(a,b) scanf("%lld %lld",&a,&b)
#define scll1(a) scanf("%lld",&a)
using namespace std;
typedef long long ll;
int main ()
{
    ll i,j,t;scll1(t);
    while(t--)
    {
        scll2(i,j);
        if(!(j%i))
        cout<<i<<" "<<j<<endl;
        else
        cout<<-1<<endl;
    }
    return 0;
}

