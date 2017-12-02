
#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
char arr[25][25];
int m,n,d[25][25],flag[25][25];
int bfs(int x,int y)
{
    int i,x1[]= {-1,0,1,0},y1[]= {0,-1,0,1},s1,s2,ef=0,s3,s4;
    queue<int>q;
    q.push(x);
    q.push(y);
    flag[x][y]=1;
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        y=q.front();
        q.pop();
        for(i=0; i<4; i++)
        {
            s1=x+x1[i];
            s2=y+y1[i];
            if(s1>=0&&s2>=0&&s1<m&&s2<n)
            {
                if(flag[s1][s2]==0)
                {
                    flag[s1][s2]=1;
                    if(arr[s1][s2]!='#'&&arr[s1][s2]!='m')
                    {
                        d[s1][s2]=d[x][y]+1;
                        q.push(s1);
                        q.push(s2);
                        if(arr[s1][s2]=='h')
                        {
                            s3=s1;
                            s4=s2;
                        }
                    }
                }
//                else if(arr[s1][s2]=='h')
//                {
//                    s3=s1;
//                    s4=s2;
//                    d[s1][s2]=d[x][y]+1;
//                   // ef=1;break;
//                   // cout<<d[s1][s2]<<endl;
//                }
            }
        }
//        if(ef==1)
//        break;
    }
    return d[s3][s4];
}
int main ()
{
    int test,t,i,j,res,res1;
    char z;
    scanf("%d",&test);
    for(t=1; t<=test; t++)
    {
        res=0;
        scanf("%d %d",&m,&n);
        scanf("%c",&z);
        for(i=0; i<m; i++)
            gets(arr[i]);
        for(i=0; i<m; i++)
            for(j=0; j<n; j++)
                if(arr[i][j]=='a'||arr[i][j]=='b'||arr[i][j]=='c')
                {
                    memset(d,0,sizeof(d));
                    memset(flag,0,sizeof(flag));
                    res1=bfs(i,j);
                    res=max(res,res1);
                }
        printf("Case %d: %d\n",t,res);
    }
    return 0;
}
