#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map>
#include <ctype.h>
#include <string>
#include <stdlib.h>
#include <algorithm>
#define inf 123456789
using namespace std;
int main ()
{
    int m,n,t,t1,c2,flag,r1,r2,r3,fr1,fr2,fr3;
    while(cin>>m>>n>>t)
    {
        if(m>n)
        swap(m,n);
        if(t<m)
        {
            cout<<0<<" "<<t<<endl;
            continue;
        }
        if((m<=n)&&((t%m)==0))
        {
            cout<<t/m<<endl;
            continue;
        }
        flag=0;
        t1=t;
        fr3=123456789;r2=0;
        while(1)
        {
            if(t1<n)
            break;
            t1-=n;
            r2++;
            if((t1%m)==0)
            {
                flag=1;
                cout<<r2+(t1/m)<<endl;
                break;
            }
            r3=t1%m;
            if(fr3>r3)
            {
                fr1=t1/m;fr2=r2;fr3=r3;
            }
            else if(fr3==r3&&((t1/m)+r2)>(fr1+fr2))
            {
                fr1=t1/m;fr2=r2;
            }
        }
        r2=0;t1=t;
        if(flag==1)
        continue;
        while(1)
        {
            if(t1<m)
            break;
            t1-=m;
            r2++;
            if((t1%n)==0)
            {
                flag=1;
                cout<<r2+(t1/n)<<endl;
                break;
            }
            r3=t1%n;
            if(fr3>r3)
            {
                fr1=t1/n;fr2=r2;fr3=r3;
            }
            else if(fr3==r3&&((t1/n)+r2)>(fr1+fr2))
            {
                fr1=t1/n;fr2=r2;
            }
        }
        if(flag==0)
        cout<<fr1+fr2<<" "<<fr3<<endl;
    }
    return 0;
}

