#include <stdio.h>
unsigned long long arr[1000007],arrprime[1000006];
int main ()
{
    unsigned long long i,j,d,a,b,c;
    arrprime[0]=2;c=1;
    for(i=3;i<1000007;i+=2)
    {
        if(arr[i]==0)
        {
            arrprime[c++]=i;
            for(j=i+i;j<1000007;j+=i)
            arr[j]=3;
        }
    }
    d=c;
    while((scanf("%llu",&a))==1)
    {
        if(a==0)
        break;
        c=0;
        for(i=0;i<d;i++)
        {
            b=arrprime[i];
            if((a%b)==0)
            ++c;
        }
        printf("%llu : %llu\n",a,c);
    }
    return 0;
}
