#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main ()
{
    int prime[2010];
    int flag,t,test,len,i,a,count[305],j;
    char arr[2010],z;
    memset(prime,0,sizeof(prime));
    prime[2]=1;
    for(i=3;i<2005;i+=2)
    {
        if(prime[i]==0)
        {
            prime[i]=1;
            for(j=i+i;j<2005;j+=i)
            prime[j]=2;
        }
    }
    scanf("%d",&test);
    scanf("%c",&z);
    for(t=1;t<=test;t++)
    {
        flag=0;
        memset(count,0,sizeof(count));
        gets(arr);
        len=strlen(arr);
        for(i=0;i<len;i++)
        {
            a=(int)arr[i];
            count[a]++;
        }
        printf("Case %d: ",t);
        for(i=0;i<300;i++)
        {
            if(prime[count[i]]==1)
            {
                printf("%c",(char)i);
                flag=1;
            }
        }
        if(flag==0)
        cout<<"empty";
        cout<<endl;
    }
    return 0;
}
