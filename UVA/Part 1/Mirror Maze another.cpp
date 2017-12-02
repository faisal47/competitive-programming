#include <bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define pii pair<int,int>
#define fs first
#define sc second
#define scch(a) scanf(" %c",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define mt 55
using namespace std;
int flag[mt][mt][4],n,m;
char arr[mt][mt];
pii s,e;
int X[]={-1,0,1,0};
int Y[]={0,1,0,-1};
bool dfs(int x,int y,int dik)
{
    if(x<1 || x>n || y<1 || y>m)return 0;
    if(mp(x,y)==e)return 1;
    int &ret=flag[x][y][dik];
    if(ret)return 0;
    ret=1;
    if(arr[x][y]=='*')return 0;
    if(arr[x][y]=='.')
       return dfs(x+X[dik],y+Y[dik],dik);
    char ch='/';
    int new_dik;
    if(dik==0)new_dik=1;
    else if(dik==1)new_dik=0;
    else if(dik==2)new_dik=3;
    else new_dik=2;
    bool sign=dfs(x+X[new_dik],y+Y[new_dik],new_dik);
    if(sign)
    {
        arr[x][y]=ch;
        return 1;
    }
    ch='\\';
    arr[x][y]=ch;
    if(dik==0)new_dik=3;
    else if(dik==3)new_dik=0;
    else if(dik==1)new_dik=2;
    else new_dik=1;
    return dfs(x+X[new_dik],y+Y[new_dik],new_dik);
}
int main ()
{
    int t=0,i,j;
    while(sci2(m,n)==2 && m!=-1 && n!=-1)
    {
        if(t++)printf("\n");
        s=mp(-1,-1);
    e=mp(-1,-1);
        for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            scch(arr[i][j]);
            if(arr[i][j]=='.' && (i==1 || i==n || j==1 || j==m))
            {
                if(s.fs==-1)
                s=mp(i,j);
                else
                e=mp(i,j);
            }
        }
        ms(flag,0);
        if(s.fs==1)
        dfs(s.fs,s.sc,2);
        else if(s.fs==n)
        dfs(s.fs,s.sc,0);
        else if(s.sc==1)
        dfs(s.fs,s.sc,1);
        else
        dfs(s.fs,s.sc,3);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            printf("%c",arr[i][j]);
            printf("\n");
        }
    }
    return 0;
}

