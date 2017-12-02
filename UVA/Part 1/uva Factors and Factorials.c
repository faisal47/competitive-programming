#include <stdio.h>
int arr[105],arr1[105];
int main ()
{
    int i,n,a,b,c,d;
    for(i=2; i<=101; i++)
    {
        a=i+i;
        while(a<=101)
        {
            arr1[a]=1;
            a+=i;
        }
    }
    while((scanf("%d",&n))==1)
    {
        if(n==0)
            break;
        for(i=2; i<=n; i++)
        {
            a=1;
            if(arr1[i]==0)
            {
                b=i;
                a=1;
                while(1)
                {
                    while(1)
                    {
                        d=b*a;
                        if(d>n)
                            break;
                        arr[i]+=1;
                        ++a;
                    }
                    a=1;
                    b*=i;
                    if(b>n)
                        break;
                }
            }
        }
        b=0;
        printf("%3d! =",n);
        for(i=2; i<=n; i++)
        {
            if(arr[i]>0)
            {
                if(b==15)
                {
                    b=0;
                    printf("\n      ");
                }
                printf("%3d",arr[i]);
                ++b;
            }
        }
        printf("\n");
        for(i=2; i<=n; i++)
            arr[i]=0;
    }
    return 0;
}
