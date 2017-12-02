#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    unsigned long long i,n,res,num;
    int test,t,c;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        cin>>n;
        c=0;
        for(i=1;i<n;i++)
        {
          num=res=i;
            num++;
            while(1)
            {
                res+=num++;
                if(res==n)
                {
                    c++;break;
                }
                else if(res>n)
                break;
            }
        }
        printf("Case %d: %d\n",t,c);
    }
    return 0;

}
