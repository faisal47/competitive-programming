#include <stdio.h>
#include <iostream>
using namespace std;
void bfs(char arr[][200],int i,int j,int m)
{
    if(i>-1&&j>-1&&i<m&&j<m)
    {
        if(arr[i][j]!='.')
        {
           arr[i][j]='.';
            bfs(arr,i-1,j,m);
            bfs(arr,i+1,j,m);
            bfs(arr,i,j-1,m);
            bfs(arr,i,j+1,m);
        }
    }
    return;
}
int main ()
{
    int y,z,m,i,j,count;
    char arr[200][200],a;
    cin>>z;
    for(y=1;y<=z;y++)
    {
        scanf("%d",&m);
        scanf("%c",&a);
        count=0;
        for(i=0;i<m;i++)
        gets(arr[i]);
        for(i=0;i<m;i++)
        for(j=0;j<m;j++)
        {
            if(arr[i][j]=='x')
            {
                count++;
                bfs(arr,i,j,m);
            }
        }
        printf("Case %d: %d\n",y,count);
    }
}
