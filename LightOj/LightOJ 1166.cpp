#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map>
#include <ctype.h>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#define inf 123456789
using namespace std;
int arr[110];
bool flag[110];
int main ()
{
    int test,i,c=0,s,test1,test2=1;
    cin>>test1;
    while(test1--)
    {
        cin>>test;c=0;
        for(i=1;i<=test;i++)
        {
            cin>>arr[i];
            flag[i]=0;
        }
        for(i=1;i<=test;i++)
        {
            if(flag[i]==1||arr[i]==i)
            continue;
            s=i;
            while(1)
            {
                if(flag[s]==1)
                break;
                flag[s]=1;
                c++;
                s=arr[s];
            }
            c--;
        }
        printf("Case %d: ",test2++);
        cout<<c<<endl;
    }
    return 0;
}
