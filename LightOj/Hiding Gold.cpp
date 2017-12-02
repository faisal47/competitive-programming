#include <bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define scch(a) scanf("%c",&a)
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sz(a) a.size()
#define mt 25
using namespace std;
int X[]= {-1,0,1,0};
int Y[]= {0,1,0,-1};
char arr[mt][mt];
int flag[mt][mt];
int r,c,m1,m2,map1[mt][mt],par[410],col[410],flag1,s1,e1;
vec_<int>v[410];
void bfs(int s,int e)
{
    queue<int>q;
    q.push(s);
    q.push(e);
    flag1=1;
    flag[s][e]=flag1;
    map1[s][e]=m1++;
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        e=q.front();
        q.pop();
        if(flag[s][e]==1)
        flag1=2;
        else
        flag1=1;
        for(int i=0; i<4; i++)
        {
            s1=s+X[i];
            e1=e+Y[i];
            if(!flag[s1][e1] && arr[s1][e1]=='*' && s1>=0 && e1>=0 && s1<r && e1<c)
            {

                flag[s1][e1]=flag1;
                q.push(s1);
                q.push(e1);
                if(flag1==2)
                {
                    //cout<<"lldjf";
                    map1[s1][e1]=m2++;
                    v[map1[s][e]].pb(map1[s1][e1]);
                }
                else
                {
                    map1[s1][e1]=m1++;
                    v[map1[s1][e1]].pb(map1[s][e]);
                }

            }
        }
    }
}
bool dfs(int node)
{
    int asi,p;
    for(p=0;p<sz(v[node]);p++)
    {
        asi=v[node][p];
        if(!col[asi])
        {
            col[asi]=1;
            if(par[asi]==-1 || dfs(par[asi]))
            {
                par[asi]=node;
                return 1;
            }
        }
    }
    return 0;
}
int bpm()
{
    int ans=0;
    int i,j;
    for(i=1;i<=m1;i++)
    {
        for(j=1;j<=m2;j++)
            col[j]=0;
        ans+=dfs(i);
    }
    return ans;
}
int main ()
{
    int test,t=1,i,j,ans;
    char z;
    sci1(test);
    while(test--)
    {
        ms(flag,0);
        ans=0;
        sci2(r,c);
        scch(z);
        m1=r*c;
        for(i=1;i<=m1;i++)
        {
            clr(v[i]);
            par[i]=-1;
        }
        m1=m2=1;
        for(i=0; i<r; i++)
            gets(arr[i]);
        for(i=0; i<r; i++)
            for(j=0; j<c; j++)
                {
                    if(arr[i][j]=='*')
                    ans++;
                    if(!flag[i][j] && arr[i][j]=='*')
                    bfs(i,j);
                }
        m1--;m2--;
        ans-=bpm();
        printf("Case %d: %d\n",t++,ans);
    }
    return 0;
}

