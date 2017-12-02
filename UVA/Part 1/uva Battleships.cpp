#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int count=0;
void bfs(char arr[][200],int i,int j,int m)
{
    if(i>-1&&j>-1&&i<m&&j<m)
    {
        if(arr[i][j]!='.')
        {
            count++;
            arr[i][j]='.';
            bfs(arr,i,j-1,m);
            bfs(arr,i,j+1,m);
            bfs(arr,i-1,j,m);
            bfs(arr,i+1,j,m);
        }
    }
    return;
}
int main ()
{
    int test,m,i,j,y,c;
    char arr[200][200],a;
    cin>>test;
    for(y=1;y<=test;y++)
    {
        scanf("%d",&m);
        scanf("%c",&a);
        count=c=0;
        for(i=0;i<m;i++)
        gets(arr[i]);
        for(i=0;i<m;i++)
        for(j=0;j<m;j++)
        {
            if(arr[i][j]!='.')
            {
                bfs(arr,i,j,m);
                if(count==1)
                c++;
                count=0;
            }
        }
        printf("Case %d: %d\n",y,c);
    }
    return 0;
}
