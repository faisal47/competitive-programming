#include<bits/stdc++.h>
using namespace std;

#define inf 1<<28
#define pb push_back
#define clr(a) a.clear()
#define ms(a,b) memset(a,b,sizeof(a))
#define vec_ vector
#define pob pop_back
#define all(a) a.begin(),a.end()
#define sz

int main ()
{
    int c1=0,c2=0;
    int n,m,k,a;

    cin>>n>>m>>k;

    while(n--)
    {
        cin>>a;
        if(a==1)
            c1++;
        else
            c2++;
    }

    if(c1<=m)
    {
        m-=c1;
        c1=0;
    }
    else
    {
        c1-=m;
        m=0;
    }

    c2-=(m+k);

    if(c2<0)c2=0;
    cout<<c1+c2;

    return 0;
}