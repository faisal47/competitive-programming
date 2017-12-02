#include <stdio.h>
#include <iostream>
#define sc1(a) scanf("%lld",&a)
using namespace std;
int main ()
{
    long long i,a,test,t=1,j;
    string s;
    sc1(test);
    while(test--)
    {
        a=0;
        cin>>s>>j;
        if(j<0)
        j=-j;
        for(i=0;i<s.size();i++)
        {
            if(s[i]!='-')
            {
                a*=10;
                if(a>=0)
                a+=s[i]-'0';
                else
                a-=s[i]-'0';
                if(s[i-1]=='-' && i>0)
                a=-a;
                a%=j;
            }
        }
        if(!a)
        printf("Case %lld: divisible\n",t++);
        else
        printf("Case %lld: not divisible\n",t++);
    }
    return 0;
}

