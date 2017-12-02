#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
char arr[205][205],z;
bool color[205][205],sflag;
int n,x[]= {-1,-1,0,0,1,1},y[]= {-1,0,-1,1,0,1};
void bfs(int i,int j)
{
    int a,b,k;
     z=arr[i][j];
    queue<int>q;
    q.push(i);
    q.push(j);
    color[i][j]=1;
    while(!q.empty())
    {
        a=q.front();
        q.pop();
        b=q.front();
        q.pop();
        for(k=0; k<6; k++)
        {
            i=a+x[k];
            j=b+y[k];
            if(color[i][j]==0&&arr[i][j]=='b'&&i>-1&&j>-1&&i<n&&j<n)
            {
                color[i][j]=1;
                q.push(i);q.push(j);
                if(i==(n-1))
                {
                    sflag=1;
                    break;
                }
            }
        }
        if(sflag==1)
            break;
    }
    return;
}
int main ()
{
    int i,test=1;
    while((scanf("%d%c",&n,&z))==2)
    {
        if(n==0)
            break;
        sflag=0;
        memset(color,0,sizeof(color));
        for(i=0; i<n; i++)
            gets(arr[i]);
        for(i=0; i<n; i++)
            if(color[0][i]==0&&arr[0][i]=='b')
            {
                bfs(0,i);
                if(sflag==1)
                    break;
            }
        if(sflag==1)
        printf("%d B\n",test++);
        else
        printf("%d W\n",test++);
    }
    return 0;
}
