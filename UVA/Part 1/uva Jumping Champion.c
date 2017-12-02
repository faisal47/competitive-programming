#include <stdio.h>
unsigned long long arr1[1000010],arrprime[79000],arr2[79000],arr3[100000000];
int main ()
{
    unsigned long long i,j,k,l,a,b,c,d,flag,flag1,d1,f,g,e,max;
    c=0;
    arrprime[c++]=2;
    arr1[2]=1;
    for(i=3; i<1000010; i+=2)
    {
        if(arr1[i]==0)
        {
            arrprime[c++]=i;
            for(j=i+i; j<1000010; j+=i)
                arr1[j]=3;
        }
    }
    d=c;
    scanf("%llu",&l);
    for(k=0; k<l; k++)
    {
        flag=flag1=c=0;
        scanf("%llu %llu",&a,&b);
        for(i=0; i<d; i++)
        {
            if(arrprime[i]>=a)
                flag=1;
            if(arrprime[i]>b)
                break;
                if(flag==1)
                arr2[c++]=arrprime[i];
        }
        d1=c;
        if(d1==0||d1==1)
        {
            printf("No jumping champion\n");
            continue;
        }
        max=flag=f=0;
        for(i=1; i<d1; i++)
        {
            e=arr2[i]-arr2[i-1];
            ++arr3[e];
            if(max<e)
                max=e;
            if(f<arr3[e])
            {
                f=arr3[e];
                g=e;
            }
        }
        for(i=0; i<=max; i++)
        {
            if(arr3[i]==f)
                flag+=1;
            arr3[i]=0;
        }
        if(flag>1)
            printf("No jumping champion\n");
        else
            printf("The jumping champion is %llu\n",g);
        for(i=0;i<78991;i++)
        arr2[i]=0;
    }
    return 0;
}
