#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "string"
#include "vector"
#include "math.h"
#include "map"
#include "stack"
#include "queue"
#include "algorithm"
#include "iostream"

#define inf 1<<28
#define SD(n) scanf("%d",&n)
#define SS(n) scanf("%s",n)
#define SLF(n) scanf("%lf",n)
#define FOR(i,n) for(i=0;i<n;i++)
#define FORI(i,a,n) for(i=a;i<=n;i++)
#define SZ 1010

int main()
{
    int x,y,t,i,j,k,n,pa,pb,sum1,sum2,total;
    while(SD(n) == 1)
    {
        k = n;
        sum1 = sum2 = pa = pb = 0;
        while(k--)
        {
            SD(t);
            SD(x);
            SD(y);
            if(t==1)
            {
                pa++;
                sum1 += x;
            }
            else
            {
                pb++;
                sum2 += x;
            }
        }
        total = (pa * 10);
        if((double)sum1 >= (double)total/2) printf("LIVE\n");
        else printf("DEAD\n");
        total = (pb * 10);
        if((double)sum2 >= (double)total/2) printf("LIVE\n");
        else printf("DEAD\n");

    }



    return 0;
}