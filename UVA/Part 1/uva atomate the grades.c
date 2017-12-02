#include <stdio.h>
int main ()
{
    int arr[1000],a,i,d,c,k,b,j,n;
    char arr1[1000];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {d=0;
    c=0;
        for(j=0;j<7;j++)
        {
            scanf("%d",&arr[j]);
        }
        if((arr[4]>=arr[5])&&(arr[4]>=arr[6]))
        {
            a=arr[4];
            if(arr[5]>=arr[6])
            {
                b=arr[5];
            }
            if(arr[5]<=arr[6])
            {
                b=arr[6];
            }
        }
        if((arr[5]>=arr[4])&&(arr[5]>=arr[6]))
        {
            a=arr[5];
            if(arr[4]>=arr[6])
            {
                b=arr[4];
            }
            if(arr[4]<=arr[6])
            {
                b=arr[6];
            }
        }
        if((arr[6]>=arr[4])&&(arr[6]>=arr[5]))
        {
            a=arr[6];
            if(arr[4]>=arr[5])
            {
                b=arr[4];
            }
            if(arr[4]<=arr[5])
            {
                b=arr[5];
            }
        }
        c=((a+b)/2);
        arr[4]=c;
        for(k=0;k<5;k++)
        {
            d=d+arr[k];
        }
        if(d>=90)
        {
            arr1[i]='A';
        }
        if(d<90 && d>=80)
        {
            arr1[i]='B';
        }
         if(d<80 && d>=70)
        {
            arr1[i]='C';
        }
         if(d<70 && d>=60)
        {
            arr1[i]='D';
        }
         if(d<60)
        {
            arr1[i]='F';
        }
        printf("Case %d: %c\n",i,arr1[i]);
    }
    return 0;
}
