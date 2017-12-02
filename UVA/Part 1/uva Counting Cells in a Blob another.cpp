#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int count;
void bfs(int arr[][26],int mpash,int mlomba,int i,int j)
{
    if(i>-1&&j>-1&&i<mlomba&&j<mpash)
    {
        if(arr[i][j]==1)
        {
            arr[i][j]=0;
            ++count;
            bfs(arr,mpash,mlomba,i,j-1);
            bfs(arr,mpash,mlomba,i-1,j-1);
            bfs(arr,mpash,mlomba,i-1,j);
            bfs(arr,mpash,mlomba,i-1,j+1);
            bfs(arr,mpash,mlomba,i,j+1);
            bfs(arr,mpash,mlomba,i+1,j+1);
            bfs(arr,mpash,mlomba,i+1,j);
            bfs(arr,mpash,mlomba,i+1,j-1);
        }
    }
    return;
}
int main ()
{
    char z,arr1[27],a;
    int arr[26][26],y,w,len,i,j,k,l,max,mpash,mlomba;
    scanf("%d",&w);
    scanf("%c",&z);
    scanf("%c",&a);
    for(y=0;y<w;y++)
    {
        if(y)
        cout<<endl;
        mpash=mlomba=i=max=0;
        while(gets(arr1))
        {
            len=strlen(arr1);
            if(len==0)
            break;
            mpash=len;
            for(i=0;i<len;i++)
            {
                arr[mlomba][i]=(arr1[i]-'0');
            }
            ++mlomba;
        }
        for(i=0;i<mlomba;i++)
        for(j=0;j<mpash;j++)
        if(arr[i][j]==1)
        {
            count=0;
            bfs(arr,mpash,mlomba,i,j);
            if(max<count)
            max=count;
        }
         cout<<max<<endl;
    }
    return 0;
}
