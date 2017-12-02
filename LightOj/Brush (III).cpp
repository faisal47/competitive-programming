#include <bits/stdc++.h>
using namespace std;
int dp[110][110],n,w,k;
vector<int>v;
int maan_de(int s,int used)
{
    if(s>=n || used>=k)return 0;
    int &ret=dp[s][used];
    if(ret!=-1)return ret;
    int i,s1,w1,j;
    ret=0;
    for(i=s;i<n;i++)
    {
        w1=v[i]+w;
        s1=i;
        for(j=i+1;j<n;j++)
        if(v[j]<=w1)
        s1++;
        ret=max(ret,s1+1-i+maan_de(s1+1,used+1));
    }
    return dp[s][used]=ret;
}
int main ()
{
    int i,j,test,t=1,l;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d %d",&n,&w,&k);
        v.clear();
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&j,&l);
            v.push_back(l);
            for(j=0;j<k;j++)dp[i][j]=-1;
        }
        sort(v.begin(),v.end());
        printf("Case %d: %d\n",t++,maan_de(0,0));
    }
    return 0;
}
