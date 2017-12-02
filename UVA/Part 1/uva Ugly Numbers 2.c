#include <stdio.h>
int main ()
{
    long long int a=2,b=3,c=5,arr[1550],i,j,k,d=2,e=2,f=2,a1=2,b1=3,c1=5;
    for(i=2;i<1540;i++)
    {
        if(a==b||b==c||c==a)
        {
            if(a==b||a==c)
            a=a1*arr[d++];
            else if(b==c)
            b=b1*arr[e++];
            i-=1;
        }
        else if(a<b&&a<c)
        {
            arr[i]=a;
            a=a1*arr[d++];
        }
        else if(b<c&&b<a)
        {
            arr[i]=b;
            b=b1*arr[e++];
        }
        else
        {
            arr[i]=c;
            c=c1*arr[f++];
        }
    }
    printf("The 1500'th ugly number is %lld.\n",arr[1500]);
    return 0;
}
