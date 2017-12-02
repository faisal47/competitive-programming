#include <stdio.h>
int main ()
{
    unsigned long long t,a,b,arr[10005],i,j,c,taka,d,flag;
    while((scanf("%llu",&t))==1)
    {
        for(i=0;i<t;i++)
        scanf("%llu",&arr[i]);
        scanf("%llu",&taka);
       flag=0;
        for(i=0;i<t-1;i++)
        for(j=i+1;j<t;j++)
        {
            c=(arr[i]+arr[j]);
            if(c==taka)
            {
                if(flag==0)
                {
                    flag+=1;
                    if(arr[i]>=arr[j])
                    {
                        a=arr[j];
                        b=arr[i];
                        d=b-a;
                    }
                    else
                    {
                        a=arr[i];
                        b=arr[j];
                        d=b-a;
                    }
                }
              if(arr[i]>=arr[j])
              {
                  if((arr[i]-arr[j])<d)
                  {
                      a=arr[j];
                      b=arr[i];
                      d=b-a;
                  }
              }
              else
              {
                  if((arr[j]-arr[i])<d)
                  {
                      a=arr[i];
                      b=arr[j];
                      d=b-a;
                  }
              }
            }
        }
        printf("Peter should buy books whose prices are %llu and %llu.\n\n",a,b);
    }
    return 0;
}
