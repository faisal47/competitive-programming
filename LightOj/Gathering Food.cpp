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
#define mp make_pair
#define pii pair<int,int>
#define fs first
#define sc second
#define scch(a) scanf(" %c",&a)
#define sci1(a) scanf(" %d",&a)
#define mt 15
using namespace std;
char arr[mt][mt];
bool col[mt][mt];
int X[]= {-1,0,1,0},Y[]= {0,1,0,-1},n,l,s1,e1,dist[mt][mt],s,e;
char s_sign;
bool bfs()
{
    queue<int>q;
    q.push(s);
    q.push(e);
    col[s][e]=1;
    dist[s][e]=0;
    while(!q.empty())
    {
        s=q.front();q.pop();
        e=q.front();q.pop();
        for(l=0;l<4;l++)
        {
            s1=X[l]+s;
            e1=Y[l]+e;
            if(s1>=1 && s1<=n && e1>=1 && e1<=n && !col[s1][e1] && arr[s1][e1]=='.')
            {
                dist[s1][e1]=dist[s][e]+1;
                col[s1][e1]=1;
                q.push(s1);
                q.push(e1);
            }
            else if(s1>=1 && s1<=n && e1>=1 && e1<=n && arr[s1][e1]==s_sign)
            {
                dist[s1][e1]=dist[s][e]+1;
                return true;
            }
        }
    }
    return false;
}
int main ()
{
    pii a[30];
    int test,t=1,k,i,j,ans;
    bool flag;
    sci1(test);
    while(test--)
    {
        sci1(n);
        k=ans=0;
        flag=1;
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
            {
                scch(arr[i][j]);
                if(arr[i][j]>='A' && arr[i][j]<='Z')
                {
                    a[arr[i][j]-'A']=mp(i,j);
                    k++;
                }
            }
        k--;
        for(i=0; i<k; i++)
        {
            s_sign='A'+i+1;
            ms(col,0);
            s=a[i].fs;
            e=a[i].sc;
            arr[s][e]='.';
            if(!bfs())
            {
                flag=0;
                break;
            }
            ans+=dist[s1][e1];
        }
        printf("Case %d: ",t++);
        if(!flag)
        cout<<"Impossible\n";
        else
        printf("%d\n",ans);
    }
    return 0;
}

