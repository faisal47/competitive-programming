#include <stdio.h>
#include <map>
using namespace std;
int main ()
{
   long long int c,n,count,max,min,b,a,i,arr[12],j,temp,c1;
   map<long long int,long long int>ma;
    while((scanf("%lld",&n))==1)
    {
        if(n==0)
        break;
      count=c1=0;b=-2;ma.clear();
        printf("Original number was %lld\n",n);
        while(1)
        {
            c=max=min=0;
            while(1)
            {
                if(n==0)
                break;
                arr[c++]=n%10;
                n/=10;
            }
            for(i=0;i<c-1;i++)
            for(j=i+1;j<c;j++)
            {
                if(arr[i]>arr[j])
                {
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            }
            for(i=0;i<c;i++)
            min=((min*10)+arr[i]);
            for(i=c-1;i>=0;i--)
            max=((max*10)+arr[i]);
            a=max-min;
            printf("%lld - %lld = %lld\n",max,min,a);
            count++;
            if(ma.find(a)==ma.end())
            ma[a]=c1++;
            else
            break;
            n=a;

        }
        printf("Chain length %lld\n\n",count);
    }
    return 0;
}
