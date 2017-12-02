#include <stdio.h>
int main ()
{
    int arr[15],j,n,i,a;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        a=0;
        for(j=0;j<10;j++)
        scanf("%d",&arr[j]);
        if(arr[0]<=arr[1])
        {
            for(j=0;j<9;j++)
            {
                if(arr[j]>arr[j+1])
                break;
                else
                a++;
            }
            if(i==0)
            printf("Lumberjacks:\n");
            if(a==9)
            printf("Ordered\n");
            else
            printf("Unordered\n");
        }
        else if(arr[0]>=arr[1])
        {
            for(j=0;j<9;j++)
            {
                if(arr[j]<arr[j+1])
                break;
                else
                a++;
            }
            if(i==0)
            printf("Lumberjacks:\n");
            if(a==9)
            printf("Ordered\n");
            else
            printf("Unordered\n");
        }
    }
    return 0;
}
