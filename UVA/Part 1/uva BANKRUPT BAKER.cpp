#include <stdio.h>
#include <iostream>
#include <map>
#include <ctype.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
struct lis
{
    string a;int cost;
};
bool sign (lis a,lis b)
{
    if(a.cost==b.cost)
    return a.a<b.a;
    else
    return a.cost<b.cost;
}
int main ()
{
    int test,z,n,dam,cost,k,o,flag;
    map<string,int>m;
    vector<lis>l;
    lis list;
    l.clear();
    char arr[1000];
    string a;
    scanf("%d",&test);
    gets(arr);
    while(test--)
    {
        m.clear();
        flag=0;
        l.clear();
        gets(arr);
        for(z=0;z<strlen(arr);z++)
        printf("%c",toupper(arr[z]));
        cout<<endl;
        scanf("%d %d %d",&z,&n,&o);
        while(z--)
        {
            cin>>a>>dam;
            gets(arr);
         //   cout<<a<<" "<<dam<<endl;
            m[a]=dam;
        }
        while(n--)
        {
            cost=0;
            gets(arr);
          // cout<<arr<<endl;
            scanf("%d",&k);
           // cout<<"k=="<<k<<endl;
            while(k--)
            {
                cin>>a>>dam;
                 // cout<<a<<" "<<dam<<endl;
                cost+=(m[a]*dam);
            }
            if(cost>o);
            else
            {
                 list.a=arr;
                 list.cost=cost;
                 l.push_back(list);
                flag=1;
            }
            gets(arr);
        }
        if(flag==0)
        cout<<"Too expensive!"<<endl;
        else
        {
           sort(l.begin(),l.end(),sign);
           for(z=0;z<l.size();z++)
           cout<<l[z].a<<endl;
        }
        cout<<endl;
    }
    return 0;
}
