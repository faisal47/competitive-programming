#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <map>
#include <math.h>
#include <ctype.h>
using namespace std;
#define inf 1<<28
int ans[15],ins[15],n;
void bt(int in,int ansin)
{
    if(in>n)
    {
        if(ansin==7)
        {
            int i;
            cout<<ans[1];
            for(i=2;i<ansin;i++)
            cout<<" "<<ans[i];
            cout<<endl;
        }
        return;
    }
    ans[ansin]=ins[in];
    bt(in+1,ansin+1);
    bt(in+1,ansin);
}
int main ()
{
    int i,t=0;
    while(cin>>n)
    {
        if(n==0)
        break;
        if(t++)
        cout<<endl;
        for(i=1;i<=n;i++)
        cin>>ins[i];
        bt(1,1);
    }
    return 0;
}
