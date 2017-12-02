#include <bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
using namespace std;
int n,m,flag[55][55];
string arr[55];
bool side_check(int x,int y)
{
    return x==0 || x==n-1 || y==0 || y==m-1;
}
char define_dik(int x,int y)
{
    if(x==0)return 'D';
    else if(x==n-1)return 'U';
    else if(y==0)return 'R';
    else return 'L';
}
bool side_check1(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=m)return 1;
    return 0;
}
int define_x(int x,int dik)
{
    if(dik=='U')return x-1;
    if(dik=='D')return x+1;
    return x;
}
int define_y(int y,int dik)
{
    if(dik=='L')return y-1;
    if(dik=='R')return y+1;
    return y;
}
int define_x1(int x,int y,char dik)
{
    if(arr[x][y]=='/')
    {
        if(dik=='R')return x-1;
        if(dik=='L')return x+1;
        return x;
    }
    if(dik=='R')return x+1;
    if(dik=='L')return x-1;
    return x;
}
int define_y1(int x,int y,char dik)
{
    if(arr[x][y]=='/')
    {
        if(dik=='U')return y+1;
        if(dik=='D')return y-1;
        return y;
    }
    if(dik=='U')return y-1;
    if(dik=='D') return y+1;
    return y;
}
char define_dik1(int x,int y,char dik)
{
    if(arr[x][y]=='/')
    {
        if(dik=='R')return 'U';
        if(dik=='L')return 'D';
        if(dik=='U')return 'R';
        if(dik=='D')return 'L';
    }
    if(dik=='R')return 'D';
        if(dik=='L')return 'U';
        if(dik=='U')return 'L';
        if(dik=='D')return 'R';
}
void change_char(int x,int y)
{
    if(arr[x][y]=='/')
        arr[x][y]=92;
    else
        arr[x][y]='/';
}
bool dfs(int x,int y,char dik)
{
    if(side_check1(x,y))return 1;
    if(arr[x][y]=='*')return 0;
    if(arr[x][y]=='.')
        return dfs(define_x(x,dik),define_y(y,dik),dik);
    flag[x][y]++;
    bool sign=dfs(define_x1(x,y,dik),define_y1(x,y,dik),define_dik1(x,y,dik));
    if(!sign)
    {
        if(flag[x][y]>1)
        {
            flag[x][y]--;
            return sign;
        }
        change_char(x,y);
        //flag[x][y]++;
        return dfs(define_x1(x,y,dik),define_y1(x,y,dik),define_dik1(x,y,dik));
    }
    return sign;
}
int main ()
{
    int i,j,t=0;
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    bool flag1;
    while(cin>>m>>n)
    {
        flag1=0;
        if(n==-1 && m==-1)break;
        for(i=0; i<n; i++)cin>>arr[i];
        if(t++)cout<<endl;
        ms(flag,0);
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(arr[i][j]=='.' && side_check(i,j))
                {
                    dfs(i,j,define_dik(i,j));
                    flag1=1;
                    break;
                }
            }
            if(flag1)break;
        }
        for(i=0;i<n;i++)
        cout<<arr[i]<<endl;
    }
    return 0;
}

