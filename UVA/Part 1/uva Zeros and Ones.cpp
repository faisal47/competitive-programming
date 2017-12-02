#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main ()
{
    char arr[1000020],temp;
    int i,a,b,flag,test,test1=1,a1,b1;
    while(cin>>arr>>test)
    {
        printf("Case %d:\n",test1++);
        while(test--)
        {
            flag=0;
            cin>>a1>>b1;
            a=min(a1,b1);
            b=max(a1,b1);
            temp=arr[a];
            for(i=a+1;i<=b;i++)
            if(temp!=arr[i])
            {
                flag=1;
                break;
            }
            if(flag==1)
            printf("No\n");
            else
            printf("Yes\n");
        }
    }
    return 0;
}
