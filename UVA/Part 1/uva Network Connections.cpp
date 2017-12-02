#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int par[100000],n1,n2;
int find_parent(int a)
{
    if(par[a]==a)
    return a;
    else
    return par[a]=find_parent(par[a]);
}
void make_parent(int a,int b)
{
    int u=find_parent(a);
    int v=find_parent(b);
    if(u!=v)
    par[u]=v;
    return;
}
int main ()
{
    int test,len,j,i,flag,n,a,b;
    char z,arr[100];
    scanf("%d",&test);
    scanf("%c",&z);
    for(i=0; i<test-1; i++)
    {
        flag=n1=n2=0;
        scanf("%d",&n);
        scanf("%c",&z);
        for(j=1; j<=n; j++)
            par[j]=j;
        while(gets(arr))
        {
            len=strlen(arr);
            if(len==0)
                break;
            a=b=flag=0;
            for(j=2; j<len; j++)
            {
                if(arr[j]==' ')
                    flag=1;
                else if(flag==0)
                    a=(a*10)+arr[j]-'0';
                else
                    b=(b*10)+arr[j]-'0';
            }
            if(arr[0]=='c')
            {
                make_parent(a,b);
            }
            else
            {
                int u=find_parent(a);
                int v=find_parent(b);
                if(u==v)
                n1++;
                else
                n2++;
            }
        }
        printf("%d,%d\n\n",n1,n2);
    }
    flag=n1=n2=0;
        scanf("%d",&n);
        scanf("%c",&z);
        for(j=1; j<=n; j++)
            par[j]=j;
        while(gets(arr))
        {
            len=strlen(arr);
            if(len==0)
                break;
            a=b=flag=0;
            for(j=2; j<len; j++)
            {
                if(arr[j]==' ')
                    flag=1;
                else if(flag==0)
                    a=(a*10)+arr[j]-'0';
                else
                    b=(b*10)+arr[j]-'0';
            }
            if(arr[0]=='c')
            make_parent(a,b);
            else
            {
                int u=find_parent(a);
                int v=find_parent(b);
                if(u==v)
                n1++;
                else
                n2++;
            }
        }
        printf("%d,%d\n",n1,n2);
    return 0;
}
