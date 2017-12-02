#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
char text[1000010],pattern[1000010];
int ans,f[1000010],len1,len2;
void prefix()
{
    f[0]=-1;
    int i,k=0;
    for(i=1;i<len2;i++)
    {
        k=f[i-1];
        while(k>=0)
        {
            if(pattern[i-1]==pattern[k])
            break;
            else
            k=f[k];
        }
        f[i]=k+1;
    }
}
void kmp()
{
    int i=0,k=0,s;
    bool flag=0;
    while(i<len1)
    {
        if(k==-1)
        {
            i++;
            k=0;
        }
        else if(pattern[k]==text[i])
        {
            if(flag==0)
            {
                s=i;
              //  cout<<"i== "<<i<<endl;
                flag=1;
            }
            i++;k++;
            if(k==len2)
            {
                ans++;
                //cout<<"i== "<<i-1<<endl;
                i=s+1;
                flag=0;
                k=0;
            }
        }
        else
        {
            k=f[k];
            flag=0;
        }
    }
}
int main ()
{
    int test,t;
    char z;
    scanf("%d",&test);
    scanf("%c",&z);
    for(t=1;t<=test;t++)
    {
        gets(text);
        gets(pattern);
        len1=strlen(text);
        len2=strlen(pattern);
        prefix();
        ans=0;
        kmp();
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
