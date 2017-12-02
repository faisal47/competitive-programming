#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int arr[25],n,dp[25][210],cap;
int kn(int i,int w)
{
    if(i==n)
    return 0;
    if(dp[i][w]!=-1)
    return dp[i][w];
    int prof1,prof2;
    if(w+arr[i]<=cap)
    prof1=arr[i]+kn(i+1,w+arr[i]);
    else
    prof1=0;
    prof2=kn(i+1,w);
    prof1=max(prof1,prof2);
    dp[i][w]=prof1;
    return dp[i][w];
};
int main ()
{
    int test,sum,i,man;
    char z,arr1[2000],*ptr;
    scanf("%d",&test);
    scanf("%c",&z);
    while(test--)
    {
        n=sum=0;
        gets(arr1);
        ptr=strtok(arr1," ");
        while(ptr!=NULL)
        {
            arr[n]=atoi(ptr);
            sum+=arr[n];
            n++;
            ptr=strtok(NULL," ");
        }
        cap=sum/2;
        memset(dp,-1,sizeof(dp));
        man=kn(0,0);
        man*=2;
        if(sum-man==0)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
    return 0;
}
