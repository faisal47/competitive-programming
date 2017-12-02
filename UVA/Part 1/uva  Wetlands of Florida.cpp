#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int colour[101][101],count;
void dfs(char arr[][101],int m,int n,int i,int j)
{
    if(i>-1&&j>-1&&i<m&&j<n)
    {
        if(arr[i][j]=='W'&&colour[i][j]==0)
        {
            ++count;
            colour[i][j]=1;
            dfs(arr,m,n,i,j-1);
            dfs(arr,m,n,i-1,j-1);
            dfs(arr,m,n,i-1,j);
            dfs(arr,m,n,i-1,j+1);
            dfs(arr,m,n,i,j+1);
            dfs(arr,m,n,i+1,j+1);
            dfs(arr,m,n,i+1,j);
            dfs(arr,m,n,i+1,j-1);
        }
    }
    return;
}
int main ()
{
    int test,mlomba,m,n,i,j,k,len,y,z,p,q,flag;
    char a,arr[101][101],arr1[101];
    scanf("%d",&z);
    scanf("%c",&a);
    scanf("%c",&a);
    for(y=0; y<z; y++)
    {
        if(y)
            cout<<endl;
        if(y==(z-1))
        {
            mlomba=0;
            while(gets(arr1))
            {
                if(arr1[0]!='W'&&arr1[0]!='L')
                {
                    len=strlen(arr1);
                    flag=p=q=0;
                    for(i=0; i<len; i++)
                    {
                        if(arr1[i]==' ')
                            flag=1;
                        else if(flag==0)
                            p=((p*10)+(arr1[i]-'0'));
                        else
                            q=((q*10)+(arr1[i]-'0'));
                    }
                    p-=1;
                    q-=1;
                    dfs(arr,m,n,p,q);
                    cout<<count<<endl;
                    count=0;
                    memset(colour,0,sizeof(colour));

                }
                else
                {
                    strcpy(arr[mlomba],arr1);
                    ++mlomba;
                    n=strlen(arr[mlomba-1]);
                    m=mlomba;
                }
            }
        }
        else
        {
            mlomba=0;
            while(gets(arr[mlomba]))
            {
                if(arr[mlomba][0]!='W'&&arr[mlomba][0]!='L')
                    break;
                ++mlomba;
            }
            strcpy(arr1,arr[mlomba]);
            m=mlomba;
            n=strlen(arr[mlomba-1]);
            len=strlen(arr1);
            while(1)
            {
                flag=p=q=0;
                for(i=0; i<len; i++)
                {
                    if(arr1[i]==' ')
                        flag=1;
                    else if(flag==0)
                        p=((p*10)+(arr1[i]-'0'));
                    else
                        q=((q*10)+(arr1[i]-'0'));
                }
                p-=1;
                q-=1;
                dfs(arr,m,n,p,q);
                cout<<count<<endl;
                count=0;
                memset(colour,0,sizeof(colour));
                gets(arr1);
                len=strlen(arr1);
                if(len==0)
                    break;
            }
        }
    }
    return 0;
}
