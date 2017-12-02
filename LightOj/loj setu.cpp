#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int main ()
{
    unsigned long long tes,test,u,n;int t,i;char arr[20],z;
    cin>>test;
    for(tes=1;tes<=test;tes++)
    {
        u=0;
        printf("Case %d:\n",tes);
        scanf("%d%c",&t,&z);
    for(i=0;i<t;i++)
    {
        scanf("%s",arr);
        if(strcmp(arr,"donate")==0)
        {
            scanf("%llu",&n);u+=n;
        }
        else
        printf("%llu\n",u);
    }
    }
    return 0;
}

