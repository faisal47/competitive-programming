#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    char arr[100010],z;
    int test,t,t1,a,b,i;
    scanf("%d",&test);
    scanf("%c",&z);
    for(t=1;t<=test;t++)
    {
        printf("Case %d:\n",t);
        gets(arr);
        //scanf("%c",&z);
        scanf("%d",&t1);
        while(t1--)
        {
            scanf(" %c",&z);
            if(z=='Q')
            {
                scanf("%d",&a);
                cout<<arr[a-1]<<endl;
            }
            else
            {
                scanf("%d %d",&a,&b);
                for(i=a-1;i<b;i++)
                {
               if(arr[i]=='1')
                 arr[i]='0';
                 else
                 arr[i]='1';
                }
            }
        }
        scanf("%c",&z);
    }
    return 0;
}
