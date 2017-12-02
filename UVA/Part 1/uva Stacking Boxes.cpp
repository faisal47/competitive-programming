#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct l
{
    //long long prod;
    int index;
};
//bool sign(l a,l b)
//{
//    return a.prod<b.prod;
//}
int main ()
{
    vector<l>line;
    vector<int>ans;
    int m,n,arr[35][35];
    int i,j,lis,LIS[35],e;
    l line1;
    bool flag;
    //long long a;
    while(cin>>n>>m)
    {
        line.clear();
        ans.clear();
        for(i=1; i<=n; i++)
        {
            //a=1;
            LIS[i]=1;
            for(j=0; j<m; j++)
            {
                cin>>arr[i][j];
                // a*=arr[i][j];
            }
            sort(arr[i],arr[i]+m);
//            for(j=0; j<m; j++)
//            cout<<arr[i][j]<<" ";
//            cout<<endl;
            //line1.prod=arr[i][0];
            line1.index=i;
            line.push_back(line1);
        }
        //sort(line.begin(),line.end(),sign);
        for(i=0; i<line.size(); i++)
            for(j=i+1; j<line.size(); j++)
            {
                for(e=0; e<m; e++)
                {
                    if(arr[line[i].index][e]<arr[line[j].index][e])
                    {
                        break;
                    }
                    else if(arr[line[i].index][e]>arr[line[j].index][e])
                    {
                        swap(line[i],line[j]);
                        break;
                    }
                }
            }
        lis=1;
        LIS[0]=1;
//        for(i=0;i<line.size();i++)
//        printf("%d\n",line[i].index);
        for(i=0; i<line.size(); i++)
        {
            for(j=i+1; j<line.size(); j++)
            {
                flag=0;
                for(e=0; e<m; e++)
                    if(arr[line[j].index][e]<=arr[line[i].index][e])
                    {
                        flag=1;
                        break;
                    }
                if(flag==0)
                {
                    if(LIS[j]<LIS[i]+1)
                    {
                        LIS[j]=LIS[i]+1;
                        lis=max(lis,LIS[j]);
                    }
                }
            }
        }
        //cout<<"lis"<<" "<<lis<<endl;
//        for(i=0; i<line.size(); i++)
//            cout<<LIS[i]<<" "<<"ks"<<endl;
        cout<<lis<<endl;
        bool flag1=0;
        for(i=line.size()-1; i>=0; i--)
        {
            if(LIS[i]==lis)
            {
                if(flag1==0)
                {
                    ans.push_back(line[i].index);
                    lis--;
                    flag1=1;
                }
                else
                {
                    flag=0;
                    for(e=0; e<m; e++)
                        if(arr[ans[ans.size()-1]][e]<=arr[line[i].index][e])
                    {
                        flag=1;
                        break;
                    }
                if(flag==0)
                {
                    ans.push_back(line[i].index);
                        lis--;
                    }
                }
            }
            if(!lis)
                break;
        }
        cout<<ans[ans.size()-1];
        for(i=ans.size()-2; i>=0; i--)
            cout<<" "<<ans[i];
        cout<<endl;
    }
    return 0;
}
