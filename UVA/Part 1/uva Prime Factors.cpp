#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int arr[50010];
int main ()
{
    vector<int>prime;
    int i,j;
    prime.push_back(2);
    for(i=3;i<=50000;i+=2)
    {
        if(arr[i]==0)
        {
            prime.push_back(i);
            for(j=i;j<=50000;j+=i)
            {
                arr[j]=1;
            }
        }
    }
   int n,flag;
   vector<int>out;
   while(cin>>n)
   {
       if(n==0)
       break;
       flag=0;
       out.clear();
       if(n<0)
       {
           flag=1;
          out.push_back(-1);
           n*=(-1);
       }
       i=0;
       j=n;
       while(1)
       {
           if(n%prime[i]==0)
           {
               n/=prime[i];
               out.push_back(prime[i]);
           }
           else
           i++;
           if(n==1||i==prime.size())
           break;
       }
       if(flag==1)
       j*=(-1);
       printf("%d = ",j);
       if(j<0)
       j*=(-1);
       if(out.size()==1&&flag==1)
       {
           cout<<out[0];
            printf(" x %d\n",j);
            continue;
       }
       else if(out.size()==0||out.size()==1)
       {
           cout<<j<<endl;
           continue;
       }
       cout<<out[0];
       for(i=1;i<out.size();i++)
       printf(" x %d",out[i]);
       cout<<endl;
   }
    return 0;
}
