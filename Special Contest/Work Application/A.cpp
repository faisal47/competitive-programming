#include <bits/stdc++.h>
using namespace std;

string arr[10];

int dp[105][16],total_length,total_blocks,total_bit;

int solve(int position,int mask)
{

    if(position >= total_length)
    {
        if(__builtin_popcount(mask) == total_bit)
            return 0;
        return inf;
    }

    int &ret=dp[position][mask];

    if(ret != -1)
        return ret;

    ret=inf;
    int now_bit;

    for(int i=0; i<total_blocks; i++)
        for(int j=i+1; j<total_blocks; j++)
        {
            now_bit=i*total_blocks+j;
            if(mask&(1<<now_bit))
                continue;
            if(arr[i][position] != arr[j][position])
                ret=min(ret,1+solve(position+1,mask|(1<<now_bit))); /// here we are considering the position as a difference between two specific blocks
        }

    ret=min(ret,solve(position+1,mask));

    return ret;
}

int main ()
{
    int i,j,test,n,t=1,m,k;
    cin>>n>>m>>k;
    string temp;

    for(int i=0;i<k;i++)
        for(int j=0;j<n;j++)
        {
            cin>>temp;
            arr[i]+=temp;
        }

    total_length=n*m;
    total_blocks=k;
    total_bit=k*(k-1)/2;

    memset(dp,-1,sizeof(dp));

    cout<<solve(0,0);

    return 0;
}









