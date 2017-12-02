#include <bits/stdc++.h>
using namespace std;
int dp[(1<<16)+10],arr[16][2],n;
bool check(int pos,int number)
{
    return (1<<pos)&number;
}
int suf(int pos,int number)
{
    return ~(1<<pos)&number;
}
int maan_de(int mask)
{
    if(!mask)return 0;
    int &ret=dp[mask];
    if(ret!=-1)return ret;
    int i,x,new_mask,j,y,d1,d2;
    bool flag;
    ret=1<<28;
    for(i=0;i<n;i++)
    if(check(i,mask))
    {
        x=arr[i][0];
        y=arr[i][1];
        new_mask=mask;
        flag=0;
        new_mask=suf(i,new_mask);
        for(j=0;j<n;j++)
        {
            if(!flag && check(j,new_mask))
            {
                flag=1;
                d1=arr[i][0]-arr[j][0];
                d2=arr[i][1]-arr[j][1];
                new_mask=suf(j,new_mask);
            }
            else if(check(j,new_mask) && (arr[j][0]-x)*d2-d1*(arr[j][1]-y)==0)
            {
                new_mask=suf(j,new_mask);
            }
        }
        ret=min(ret,1+maan_de(new_mask));
    }
    return ret;
}
int main ()
{
    int i,j,test,t=1,l;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        l=(1<<n)+3;
        for(i=0;i<l;i++)
        dp[i]=-1;
        for(i=0;i<n;i++)
            scanf("%d %d",&arr[i][0],&arr[i][1]);
        printf("Case %d: %d\n",t++,maan_de((1<<n)-1));
    }
    return 0;
}

