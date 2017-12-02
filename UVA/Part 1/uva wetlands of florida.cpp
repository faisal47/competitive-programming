#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int arr[102][102],m,arr2[102][102];
void bfs(int sa,int sb,int arr2[][102],int a,int b)
{
    if(a<sa&&b<sb&&a>-1&&b>-1)
    {
        if(arr2[a][b]==1)
        {
            arr2[a][b]=0;
            m+=1;
            bfs(sa,sb,arr2,a,b-1);
            bfs(sa,sb,arr2,a-1,b-1);
            bfs(sa,sb,arr2,a-1,b);
            bfs(sa,sb,arr2,a-1,b+1);
            bfs(sa,sb,arr2,a,b+1);
            bfs(sa,sb,arr2,a+1,b+1);
            bfs(sa,sb,arr2,a+1,b);
            bfs(sa,sb,arr2,a+1,b-1);
        }
    }
    return;
}
int main ()
{
    int a,b,i=0,flag2=0,j,k,sa,sb,flag=0,flag1=0,len,test;
    char arr1[102],z;
    scanf("%d%c",&test,&z);
    cout<<endl;
    flag++;
    while(test--)
    {
        memset(arr,0,sizeof(arr));
        while(1)
        {
            gets(arr1);
            if(arr1[0]!='L'&&arr1[0]!='W')
                {
                    flag2=1;flag=0;
                    break;
                }
                if(flag==0)
                cout<<endl;
                flag++;
                flag2=0;
            len=strlen(arr1);
            for(k=0; k<len; k++)
            {
                if(arr1[k]=='W')
                    arr[i][k]=1;
            }
            ++i;
            sa=i;
            sb=len;
        }
        len=strlen(arr1);
        if(flag2==1)
        {
            flag1=a=b=m=0;
            flag=1;
            for(k=0; k<len; k++)
            {
                if(arr1[k]==' ')
                    flag1=1;
                else if(flag1==1)
                    b=((b*10)+(arr1[k]-'0'));
                else
                    a=((a*10)+(arr1[k]-'0'));
            }
            a-=1;
            b-=1;
            for(i=0; i<sa; i++)
                for(j=0; j<sb; j++)
                    arr2[i][j]=arr[i][j];
            if(arr2[a][b]==1)
                bfs(sa,sb,arr2,a,b);
            cout<<m<<endl;
            i=0;
        }
    }
    return 0;
}
