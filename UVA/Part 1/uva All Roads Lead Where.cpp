#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int arr2[300][300],q[300],colour[300][300],p[300];
void bfs(int count,int a,int b)
{
    int i,push=0,pop=0,m,c=0,flag=0;
    q[push++]=a;
    while(1)
    {
        m=q[pop++];
        p[a]=0;
        for(i=1; i<=count; i++)
        {
            if(colour[m][i]==0&&arr2[m][i]==1)
            {
                colour[m][i]=colour[i][m]=1;
                q[push++]=i;
                if(i==b)
                    flag=1;
                p[i]=m;
                if(flag==1)
                    break;
            }
        }
        if(flag==1)
            break;
    }
    return;
}
int main ()
{
    int i,z,y,m,n,len,j,flag,flag1,flag2,count,a1,b1,ab,pou;
    char a,arr1[10000],arr[30],b;
    scanf("%d",&z);
    for(y=1; y<=z; y++)
    {
        memset(arr2,0,sizeof(arr2));
        scanf("%d %d",&m,&n);
        scanf("%c",&a);
        count=0;
        for(i=0; i<m; i++)
        {
            flag=flag1=flag2=0;
            gets(arr1);
            a=arr1[0];
            len=strlen(arr1);
            for(j=1; j<len; j++)
            {
                if(arr1[j]==' ')
                {
                    b=arr1[j+1];
                    break;
                }
            }
            for(j=0; j<count; j++)
            {
                if(a==arr[j])
                    flag1=1;
                else if(b==arr[j])
                    flag2=1;
            }
            if(flag1==0)
                arr[count++]=a;
            if(flag2==0)
                arr[count++]=b;
            for(j=0; j<count; j++)
            {
                if(a==arr[j])
                    a1=j+1;
                else if(b==arr[j])
                    b1=j+1;
            }
            arr2[a1][b1]=arr2[b1][a1]=1;
        }
        while(n--)
        {
            gets(arr1);
            a=arr1[0];
            len=strlen(arr1);
            for(j=1; j<len; j++)
            {
                if(arr1[j]==' ')
                {
                    b=arr1[j+1];
                    break;
                }
            }
            for(j=0; j<count; j++)
            {
                if(a==arr[j])
                    a1=j+1;
                else if(b==arr[j])
                    b1=j+1;
            }
            memset(q,0,sizeof(q));
            memset(colour,0,sizeof(colour));
            memset(p,0,sizeof(p));
            for(j=1; j<=count; j++)
                colour[j][j]=1;
            bfs(count,a1,b1);
            ab=b1,pou=0;
            while(1)
            {
                arr1[pou++]=arr[ab-1];
                ab=p[ab];
                if(p[ab]==0)
                    break;
            }
            cout<<arr[a1-1];
            for(j=pou-1; j>=0; j--)
                cout<<arr1[j];
            cout<<endl;
        }
        if(y!=z)
            cout<<endl;
    }
    return 0;
}
