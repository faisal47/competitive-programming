#include <iostream>
#include <stdio.h>
#include <string.h>
int count=0;
void dfs(char arr[][100],int i,int j,int x,int y,char a)
{
    if(i>-1&&j>-1&&i<x&&j<y)
    {
        if(arr[i][j]==a)
        {
            count++;
            arr[i][j]='.';
            dfs(arr,i,j-1,x,y,a);
            dfs(arr,i,j+1,x,y,a);
            dfs(arr,i-1,j,x,y,a);
            dfs(arr,i+1,j,x,y,a);
        }
    }
    return;
}
int main ()
{
    char arr[100][100],a,arr2[3000];
    int arr1[3000],i,j,x,y,n,temp,test=1;
    while((scanf("%d %d%c",&x,&y,&a))==3)
    {
        if(x==0&&y==0)
            break;
        n=0;
        for(i=0; i<x; i++)
            gets(arr[i]);
        for(i=0; i<x; i++)
            for(j=0; j<y; j++)
                if(arr[i][j]!='.')
                {
                    arr2[n]=arr[i][j];
                    count=0;
                    a=arr[i][j];
                    dfs(arr,i,j,x,y,a);
                    arr1[n]=count;
                    ++n;
                }
        for(i=0; i<n-1; i++)
            for(j=i+1; j<n; j++)
            {
                if(arr1[i]<arr1[j])
                {
                    temp=arr1[i];
                    arr1[i]=arr1[j];
                    arr1[j]=temp;
                    a=arr2[i];
                    arr2[i]=arr2[j];
                    arr2[j]=a;
                }
                else if(arr1[i]==arr1[j]&&arr2[i]>arr2[j])
                {
                    a=arr2[i];
                    arr2[i]=arr2[j];
                    arr2[j]=a;
                }
            }
        printf("Problem %d:\n",test++);
        for(i=0; i<n; i++)
            printf("%c %d\n",arr2[i],arr1[i]);
    }
    return 0;
}
