#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
char arr[60][60];
int w,h,c;
bool color[60][60],color1[60][60];
void dfs1(int i,int j)
{
     if(i>-1&&j>-1&&i<h&&j<w)
    {
        if(color1[i][j]==0&&arr[i][j]=='X')
        {
            color1[i][j]=1;
            dfs1(i,j-1);
            dfs1(i-1,j);
            dfs1(i,j+1);
            dfs1(i+1,j);
        }
    }
    return;
}
void dfs(int i,int j)
{
    if(i>-1&&j>-1&&i<h&&j<w)
    {
        if(color[i][j]==0&&arr[i][j]!='.')
        {
            color[i][j]=1;
            if(arr[i][j]=='X'&&color1[i][j]==0)
            {
                dfs1(i,j);
                c++;
            }
           dfs(i,j-1);
            dfs(i-1,j);
            dfs(i,j+1);
            dfs(i+1,j);
        }
    }
    return;
}
int main ()
{
    int i,j,test=1;
    char z;
    vector<int>v;
    while(scanf("%d %d%c",&w,&h,&z)==3)
    {
        if(w==0&&h==0)
        break;
        memset(color,0,sizeof(color));
        memset(color1,0,sizeof(color1));
        v.clear();
        for(i=0;i<h;i++)
        gets(arr[i]);
        for(i=0;i<h;i++)
        for(j=0;j<w;j++)
        if(arr[i][j]!='.'&&color[i][j]==0)
        {
            c=0;
            dfs(i,j);
            v.push_back(c);
        }
        sort(v.begin(),v.end());
        printf("Throw %d\n",test++);
        cout<<v[0];
        for(i=1;i<v.size();i++)
        cout<<" "<<v[i];
        cout<<endl<<endl;
    }
    return 0;
}
