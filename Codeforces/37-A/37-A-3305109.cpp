#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main ()
{
    int count[1010],n,i,ans1,ans2;
    while(cin>>n)
    {
        memset(count,0,sizeof(count));
        for(i=0;i<n;i++)
        {
            cin>>ans1;
            count[ans1]++;
        }
        ans1=ans2=0;
        for(i=0;i<=1003;i++)
        {
            if(count[i]!=0)
            {
                ans1=max(ans1,count[i]);
                ans2++;
            }
        }
        cout<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}