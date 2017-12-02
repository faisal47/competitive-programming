#include <stdio.h>
#include <math.h>
unsigned long long arrprime[80000],arr1[1000050],arr2[200000000];
int main ()
{
    unsigned long long a,b,c,i,j,z,y,d,e,f,g,h,c1;
    c1=0;
    for(i=4;i<1000000000000;i*=2)
    arr2[c1++]=i;
    for(i=3; i<1000003; i+=2)
    {
        if(arr1[i]==0)
        {
            arr1[i]=1;
            for(j=i*i;j<1000000000000;j*=i)
            arr2[c1++]=j;
            a=i+i;
            for(j=a; j<1000003; j+=i)
                arr1[j]=3;
        }
    }
/*for(i=0;i<c1-1;i++)
for(j=i+1;j<c1;j++)
{
    if(arr2[i]>arr2[j])
    {
        a=arr2[i];
        arr2[i]=arr2[j];
        arr2[j]=a;
    }
}*/
    scanf("%llu",&z);
    for(y=0; y<z; y++)
    {
        c=0;
        scanf("%llu %llu",&a,&b);
        if(a==1)
            a+=1;
            for(i=0;i<c1;i++)
            {
                if(arr2[i]>=a&&arr2[i]<=b)
                ++c;
            }
        printf("%llu\n",c);
    }
    return 0;
}

