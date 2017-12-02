#include <bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define clr(a) a.clear()
#define pb push_back
#define pob pop_back
#define vec_ vector
#define eps 1E-7
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define scch(a) scanf("%c",&a)
#define scll1(a) scanf("%lld",&a)
#define scll2(a,b) scanf("%lld %lld",&a,&b)
#define scll3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define scd1(a) scanf("%lf",&a)
#define scd2(a,b) scanf("%lf %lf",&a,&b)
#define scd3(a,b,c) scanf("%lf %lf %lf",&a,&b,&c)
#define mp make_pair
#define sz(a) a.size()
#define matra
using namespace std;
stack<int>st;
vec_<int>v[10010];
int col[10010],b_color,shuru,n,m;
void dfs(int s)
{
    int i,j,a;
    // cout<<"khdf";
    st.push(s);
    col[s]=b_color;
    for(i=0; i<sz(v[s]); i++)
    {
        j=v[s][i];
        if(!col[j])
            dfs(j);
        else if(col[j]==b_color && s!=j)
        {
            while(st.top()!=j)
            {
                col[j]= col[st.top()]=-1;
                st.pop();
            }
            // col[j]=-1;
        }
    }
    st.pop();
}
int main ()
{
    int i,j,test,t=1,ans;
    sci1(test);
    while(test--)
    {
        ans=0;
        sci2(n,m);
        for(i=1; i<=n; i++)
        {
            clr(v[i]);
            col[i]=0;
        }
        while(m--)
        {
            sci2(i,j);
            v[i].pb(j);
            v[j].pb(i);
        }
        for(i=1; i<=n; i++)
        {
            if(!col[i])
            {
                while(!st.empty())st.pop();
                col[i]=i;
                b_color=i;
                shuru=i;
                dfs(col[i]);
            }
        }
        for(i=1; i<=n; i++)
        {
            cout<<col[i]<<endl;
            if(col[i]!=-1)
            {
                for(j=0; j<sz(v[i]); j++)
                {
                    if(col[v[i][j]]!=-1)
                    {
                        col[i]=col[v[i][j]]=-1;
                        ans++;
                    }
                }
            }
        }
        printf("Case #%d: %d\n",t++,ans);
    }
    return 0;
}

