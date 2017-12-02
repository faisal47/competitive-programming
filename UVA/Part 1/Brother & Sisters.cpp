#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define sz 100010
using namespace std;
int maan[235],input[sz];
int main ()
{
    int test,n,i,j,q;
    cin>>test;
    while(test--)
    {
        cin>>n>>q;
        for(i=0;i<n;i++)
        cin>>input[i];
        for(j=0;j<231;j++)
        {
            maan[j]=-1;
            for(i=0;i<n;i++)
            maan[j]=max(maan[j],(j&input[i]));
        }
        while(q--)
        {
            cin>>j;
            cout<<maan[j]<<endl;
        }
    }
    return 0;
}
