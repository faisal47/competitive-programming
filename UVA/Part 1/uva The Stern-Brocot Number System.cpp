#include <iostream>
#include <stdio.h>
using namespace std;
int main ()
{
    char arr[1000000];
    double a1,a2,b1,b2,c1,c2,m,n,m1,n1;int s,i;
    double a,b,c,r;
    while((scanf("%lf %lf",&m1,&n1))==2)
    {
        if(m1==1&&n1==1)
        break;
        s=0;arr[s++]='R';
        if(m1<n1)
        {
            m=n1;n=m1;
        }
        else
        {
            m=m1;n=n1;
        }
        r=m/n;
        b1=2;b2=1;a1=1;a2=1;c1=1;c2=0;
        while(1)
        {
            if(m==b1&&n==b2)
            break;
            b=b1/b2;
            if(r<b)
            {
                arr[s++]='L';
                c1=b1;c2=b2;
                b1=a1+c1;b2=a2+c2;
            }
            else
            {
                arr[s++]='R';
                a1=b1;a2=b2;
                b1=a1+c1;b2=a2+c2;
            }
        }
        if(m1<n1)
        {
            for(i=0;i<s;i++)
            {
                if(arr[i]=='L')
                cout<<"R";
                else
                cout<<"L";
            }
            cout<<endl;
        }
        else
        {
            arr[s]='\0';
            cout<<arr<<endl;
        }
    }
    return 0;
}
