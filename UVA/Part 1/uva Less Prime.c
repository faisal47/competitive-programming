#include <stdio.h>
int arrprime[1235],arr1[10050],arr2[1235];
int main ()
{
    int i,a,j,b,c,z,x,p,n,y;
    arr1[0]=arr1[1]=3;arr1[2]=1;
    for(i=4;i<10040;i+=2)
    arr1[3]=3;
    for(i=3;i<10040;i+=2)
    {
        if(arr1[i]==0)
        {
            arr1[i]=1;
            a=i+i;
            for(j=a;j<10050;j+=i)
            arr1[j]=3;
        }
    }
    c=0;
    for(i=0;i<=10000;i++)
    {
        if(arr1[i]==1)
        arrprime[c++]=i;
    }
    scanf("%d",&y);
    for(z=0;z<y;z++)
    {
        c=0;
        scanf("%d",&n);
        for(i=0;i<1229;i++)
        {
            if(arrprime[i]>n)
            break;
            arr2[c++]=arrprime[i];
        }
        b=0;x=0;
        for(i=0;i<c;i++)
        {
            p=n/arr2[i];
            a=(n-(p*arr2[i]));
            if(b<a)
            {
               b=a;
               x=i;
            }
        }
        printf("%d\n",arr2[x]);
    }
    return 0;
}
