#include <stdio.h>
#include <math.h>
int arrprime[80000],arr1[1000050];
int main ()
{
    long long int a,b,c,i,j,z,y,d,e,f,g,h,c1;
    double p;
    arrprime[0]=2;
    c=1;
    for(i=3; i<1000003; i+=2)
    {
        if(arr1[i]==0)
        {
            arr1[i]=1;
            arrprime[c++]=i;
            a=i+i;
            for(j=a; j<1000003; j+=i)
                arr1[j]=3;
        }
    }
    d=c;
    scanf("%lld",&z);
    for(y=0; y<z; y++)
    {
        c1=c=0;
        scanf("%lld %lld",&a,&b);
        if(a==1)
            a+=1;
        e=arrprime[c++];
        f=sqrt(b);
        while(1)
        {
            if(e>f)
                break;
            p=(double)e;
            g=pow(a,(1/p));
            h=pow(e,g);
            if(h<a||h==e)
                h*=e;
            while(1)
            {
                if(h>b)
                    break;
                ++c1;
                h*=e;
            }
            e=arrprime[c++];
        }
        printf("%lld\n",c1);
    }
    return 0;
}
