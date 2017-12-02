#include <stdio.h>
int arr[100];
int main ()
{
    unsigned long long n,i;
    int age,j,flag,m;
    while((scanf("%llu",&n))==1)
    {
        if(n==0)
        break;
        m=0;flag=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&age);
            arr[age]++;
            if(age>m)
            m=age;
        }
        for(i=1;i<=m;i++)
        {
            if(arr[i]!=0)
            {
                for(j=0;j<arr[i];j++)
                {
                    if(flag!=0)
                    printf(" %d",i);
                    else
                    {
                        flag=1;
                        printf("%d",i);
                    }
                }
            }
        }
        for(i=1;i<=m;i++)
        arr[i]=0;
        printf("\n");
    }
    return 0;
}
