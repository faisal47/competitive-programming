#include <bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define clr(a) a.clear()
#define pb push_back
#define pob pop_back
#define vec_ vector
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sz(a) a.size()
using namespace std;
int X[]= {-1,0,1,0};
int Y[]= {0,1,0,-1};
int arr[55][55],n,m,ans,upopoth[55][55];
bool col[55][55];
int dfs(int i,int j)
{
    col[i][j]=1;
    bool dfs_called=0;
    int a,b;
    for(int k=0; k<4; k++)
    {
        a=i+X[k];
        b=j+Y[k];
        if(a<n && b<m && a>-1 && b>-1 && !col[a][b] && arr[a][b]<arr[i][j])
        {

           upopoth[i][j]+=dfs(a,b);
            dfs_called=1;
        }
        else if(a<n && b<m && a>-1 && b>-1&& arr[a][b]<arr[i][j])
        {
            if(col[a][b])
            {
                dfs_called=1;
                upopoth[i][j]+= upopoth[a][b];
            }
        }
    }
    if(!dfs_called)
        {
           upopoth[i][j]=1;
        }
    return upopoth[i][j];
}
bool check(int i,int j)
{
    int a,b,k;
    for(k=0; k<4; k++)
    {
        a=i+X[k];
        b=j+Y[k];
        if(a<n && b<m && a>-1 && b>-1 && arr[a][b]>=arr[i][j])
            return 0;
    }
    return 1;
}
int main ()
{
    int i,j,test,t=1;
    sci1(test);
    vec_<int>agas;
    while(test--)
    {
        sci2(n,m);
        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
            {
                sci1(arr[i][j]);
                col[i][j]=0;
                upopoth[i][j]=0;
            }
        ans=0;
        clr(agas);
        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
                if(check(i,j))
                {
                    agas.pb(i);
                    agas.pb(j);
                }
        for(i=0;i<sz(agas);i+=2)
        {
           ans+= dfs(agas[i],agas[i+1]);
        }
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        if(!col[i][j])
        ans++;
        printf("Case #%d: %d\n",t++,ans);
    }
    return 0;
}

