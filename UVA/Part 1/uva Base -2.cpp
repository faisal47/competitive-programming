#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    long long int flag,n,test,a,b,m,i,t;
    bool arr1[1000000];
    cin>>test;
    for(t=1;t<=test;t++)
    {
        cin>>n;
         m=0;
         if(n<0)
        // n*=(-1);
        while(1)
        {
            a=n/2;
            b=n%2;
            arr1[m]=b;
            n=a;
            if(a==0)
                break;
            m++;
        }
        flag=0;
        printf("Case #%lld: ",t);
        for(i=m; i>=0; i--)
            {
                if(arr1[i]==1)
                flag=1;
                if(flag==1)
               printf("%d",arr1[i]);
            }
        if(flag==0)
        cout<<"0"<<endl;
        else
        cout<<endl;
    }
    return 0;
}

