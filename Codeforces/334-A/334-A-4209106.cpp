#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int n,i,j;
    cin>>n;
    int s=1,e=pow(n,2),n1=n/2;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n1;j++)
        cout<<s++<<" "<<e--<<" ";
        cout<<endl;
    }
    return 0;
}