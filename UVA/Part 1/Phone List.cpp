#include <bits/stdc++.h>
#define sz(a) a.size()
#define sci1(a) scanf("%d",&a)
using namespace std;
bool comp(string a,string b)
{
    return sz(a)<sz(b);
}
int main ()
{
    string a[10010],b;
    bool flag;
    int test,n,i,j;
    sci1(test);
    while(test--)
    {
        sci1(n);
        flag=0;
        for(i=0; i<n; i++)
            cin>>a[i];
        sort(a,a+n,comp);
        for(i=0; i<n; i++)
        {
            if(flag)break;
            for(j=i+1; j<n; j++)
            {
                b=a[j].substr(0,sz(a[i]));
                if(b==a[i])
                {
                    flag=1;break;
                }
            }
        }
        if(flag)cout<<"NO\n";
        else
        cout<<"YES\n";
    }
    return 0;
}

