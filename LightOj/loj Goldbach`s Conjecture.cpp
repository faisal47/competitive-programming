#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int flag[10000010],i,j,test,t;
int main ()
{
    vector<int>v;
    v.clear();
    v.push_back(2);flag[2]=1;
    for(i=3;i<10000005;i+=2)
    {
        if(flag[i]==0)
        {
            flag[i]=1;
            v.push_back(i);
            for(j=i+i;j<10000005;j+=i)
            flag[j]=2;
        }
    }
    cin>>test;
    int number,now,c,mid;
    for(t=1;t<=test;t++)
    {
        cin>>number;c=0;mid=number/2;
        for(i=0;i<v.size();i++)
        {
            now=v[i];
            if(now>mid)
            break;
           // cout<<now<<" "<<number<<endl;
            if(flag[number-now]==1)
            c++;
        }
        printf("Case %d: %d\n",t,c);
    }
    return 0;
}
