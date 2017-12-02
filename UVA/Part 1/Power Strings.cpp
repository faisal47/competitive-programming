#include <bits/stdc++.h>
#define sz(a) a.size()
#define clr(a) a.clear()
using namespace std;
int main ()
{
    int i,j;
    string a,b,c;
    bool flag;
    while(cin>>a)
    {
        if(sz(a)==1 && a[0]=='.')break;
        flag=0;
        clr(b);
        for(i=0; i<sz(a); i++)
        {
            if(flag)break;
            b+=a[i];
            if(sz(a)%sz(b)==0)
            {
                clr(c);
                for(j=0; sz(a)>sz(c); j+=sz(b))
                    c+=b;
                if(c==a)
                {
                    flag=1;
                    break;
                }
            }
        }
        cout<<sz(a)/sz(b)<<endl;
    }
    return 0;
}


