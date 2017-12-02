#include <stdio.h>
int main ()
{
    int n,i,j,a,arr[100],m,k,temp;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        a=0;
        scanf("%d",&m);
        for(j=0;j<m;j++)
        scanf("%d",&arr[j]);
        for(j=0;j<m-1;j++)
        for(k=j+1;k<m;k++)
        {
            if(arr[j]>arr[k])
            {
                temp=arr[j];
                arr[j]=arr[k];
                arr[k]=temp;
                a++;
            }
        }
        printf("Optimal train swapping takes %d swaps.\n",a);
    }
    return 0;
}
