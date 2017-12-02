#include <stdio.h>
unsigned long long arr[20000005],arrprime[1270609],arr1[1270609][2];
int main ()
{
    unsigned long long i,j,a,c,d;
    arrprime[0]=2;c=1;
    for(i=3;i<20000002;i+=2)
    {
        if(arr[i]==0)
        {
            arrprime[c++]=i;
            for(j=i+i;j<20000002;j+=i)
            arr[j]=3;
        }
    }
    d=c;c=1;
    for(i=0;i<d;i++)
    {
        j=i+1;
        if((arrprime[j]-arrprime[i])==2)
        {
            arr1[c][0]=arrprime[i];
            arr1[c][1]=arrprime[j];
            ++c;
        }
    }
    while((scanf("%llu",&a))==1)
    printf("(%llu, %llu)\n",arr1[a][0],arr1[a][1]);
    return 0;
}
