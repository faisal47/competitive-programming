#include <bits/stdc++.h>
#define mt 10010
using namespace std;
int main ()
{
    int i,n,n1,n2,n3,n4,n6,a;
    n1=n2=n3=n4=n6=0;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>a;
        if(a==1)n1++;
        else if(a==2)
            n2++;
        else if(a==3)
            n3++;
        else if(a==4)
            n4++;
        else if(a==6)
            n6++;
    }
    if(n1==n/3 && (n2+n3)==n/3 && (n4+n6)==n/3 && n3<=n6)
    {
        n/=3;
        while(n--)
        {
            cout<<1<<" ";
            if(n2)
            {
                cout<<2<<" ";
                n2--;
            }
            else if(n3)
            {
                cout<<3<<" ";n3--;
            }
            if(n4)
            {
                cout<<4<<endl;
                n4--;
            }
            else if(n6)
            {
                cout<<6<<endl;
                n6--;
            }
        }
        return 0;
    }
    cout<<-1;
    return 0;
}