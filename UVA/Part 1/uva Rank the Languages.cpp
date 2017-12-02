#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int count=0,arr1[300];
void dfs(char arr[][1000],int m,int n,int i,int j,char a)
{
    if(i>-1&&j>-1&&i<m&&j<n)
    {
        if(arr[i][j]==a)
        {
            arr[i][j]='.';
            dfs(arr,m,n,i,j-1,a);
            dfs(arr,m,n,i,j+1,a);
            dfs(arr,m,n,i-1,j,a);
            dfs(arr,m,n,i+1,j,a);
        }
    }
    return;
}
int main ()
{
    int y,z,i,j,k,l,m,n,arr2[300],arr3[300],temp;
    char a,arr[1000][1000];
    cin>>z;
    for(y=1;y<=z;y++)
    {
        memset(arr1,0,sizeof(arr1));
        scanf("%d %d",&m,&n);
        scanf("%c",&a);
        for(i=0;i<m;i++)
        gets(arr[i]);
        for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            if(arr[i][j]>='a'&&arr[i][j]<='z')
            {
                a=arr[i][j];
                arr1[a]++;
                dfs(arr,m,n,i,j,a);
            }
        }
        count=0;
        for(i='a';i<='z';i++)
        if(arr1[i]>0)
        {
            arr2[count]=i;
            arr3[count]=arr1[i];
            ++count;
        }
        for(i=0;i<count-1;i++)
        for(j=i+1;j<count;j++)
        {
            if(arr3[i]<arr3[j])
            {
                temp=arr3[i];
                arr3[i]=arr3[j];
                arr3[j]=temp;
                temp=arr2[i];
                arr2[i]=arr2[j];
                arr2[j]=temp;
            }
            else if(arr3[i]==arr3[j]&&arr2[i]>arr2[j])
            {
                temp=arr2[i];
                arr2[i]=arr2[j];
                arr2[j]=temp;
            }
        }
        printf("World #%d\n",y);
        for(i=0;i<count;i++)
        printf("%c: %d\n",arr2[i],arr3[i]);
    }
    return 0;
}
