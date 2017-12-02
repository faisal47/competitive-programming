#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <utility>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define scch(a) scanf(" %c",&a)
#define sci1(a) scanf(" %d",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define mt 30
using namespace std;
int X[]= {1,-1,1,-1,2,2,-2,-2};
int Y[]= {2,2,-2,-2,1,-1,1,-1};
int n,m,col[mt][mt],mot,mot1,ans1,s,e,s1,e1,dist[mt][mt];
char arr[mt][mt];
bool bfs()
{
    queue<int>q;
    int i,j;
    q.push(s);
    q.push(e);
    ans1=0;
    col[s][e]=1;
    dist[s][e]=0;
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        e=q.front();
        q.pop();
        for(i=0; i<8; i++)
        {
            s1=s+X[i];
            e1=e+Y[i];
            if(s1>=1 && s1<=n && e1>=1 && e1<=m)
            {
                if(!col[s1][e1])
                {
                    col[s1][e1]=1;
                    q.push(s1);
                    q.push(e1);
                    dist[s1][e1]=1+dist[s][e];
                    if(arr[s1][e1]!='.')
                    {
                        mot1++;
                        j=arr[s1][e1]-'0';
                        ans1+=dist[s1][e1]/j;
                        if(dist[s1][e1]%j)
                            ans1+=1;
                        if(mot1==mot)return true;
                    }
                }
            }
        }
    }
    return false;
}


int main ()
{
    int test,t=1,ans,i,j;
    sci1(test);
    while(test--)
    {
        sci2(n,m);
        ans=inf;
        mot=0;
        for(i=1; i<=n; i++)
            for(j=1; j<=m; j++)
            {
                scch(arr[i][j]);
                if(arr[i][j]!='.')mot++;
            }
        for(i=1; i<=n; i++)
            for(j=1; j<=m; j++)
            {
                if(arr[i][j]!='.')mot1=1;
                else mot1=0;
                ms(col,0);
                s=i;
                e=j;
                if(bfs())
                    ans=min(ans,ans1);
            }
        if(mot<=1)ans=0;
        printf("Case %d: ",t++);
        if(ans==inf)
            cout<<-1<<endl;
        else
            printf("%d\n",ans);
    }
    return 0;
}

