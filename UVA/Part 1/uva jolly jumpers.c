#include <stdio.h>
int arr[3050],arr1[3050];
int main ()
{
    int n,i,j,temp,m;
    while((scanf("%d",&n))==1)
    {
        m=1;
        for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
        for(i=0;i<n-1;i++)
        arr1[i]=abs(arr[i]-arr[i+1]);
        for(i=0;i<n-2;i++)
        for(j=i+1;j<n-1;j++)
        {
            if(arr1[i]>arr1[j])
           {temp=arr1[i];
            arr1[i]=arr1[j];
            arr1[j]=temp;}
        }
        for(i=0;i<n-1;i++)
        {
            if(arr1[i]!=m)
            break;
            m++;
        }
        if(m==n)
        {
            printf("Jolly\n");
        }
        else
        {
            printf("Not jolly\n");
        }
    }
    return 0;
}
