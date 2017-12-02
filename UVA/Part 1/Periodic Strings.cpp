#include <bits/stdc++.h>
#define sci1(a) scanf("%d",&a)
#define sz(a) a.size()
#define clr(a) a.clear()
using namespace std;
int main ()
{
    int test,i,j;
    string a,b,c;
    bool flag;
    sci1(test);
    while(test--)
    {
     cin>>a;
     flag=0;
     clr(b);
     for(i=0;i<sz(a);i++)
     {
         if(flag)break;
         b+=a[i];
         if(sz(a)%sz(b)==0)
         {
             clr(c);
             for(j=0;sz(a)>sz(c);j+=sz(b))
             c+=b;
             if(c==a)
             {
                 flag=1;break;
             }
         }
     }
     cout<<sz(b)<<endl;;
        if(test)
        cout<<endl;
    }
    return 0;
}
