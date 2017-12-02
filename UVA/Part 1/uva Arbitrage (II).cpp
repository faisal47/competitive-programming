#include <stdio.h>
#include <iostream>
#include <map>
#include <string.h>
#include <stdlib.h>
using namespace std;
double arr[35][35];
#define inf -1.
int main ()
{
    map<string,int>m;
    int n,i,t=1,j,a,b,k,flag;
    double c;
    char arr1[10000],*ptr,arr2[100];
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        flag=0;
        gets(arr1);
        m.clear();
        for(i=1; i<=n; i++)
        {
            gets(arr1);
            m[arr1]=i;
        }
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                arr[i][j]=-inf;
        scanf("%d",&j);
        gets(arr1);
        while(j--)
        {
            gets(arr1);
            ptr=strtok(arr1," ");
            //strcpy(arr2,ptr);
            a=m[ptr];
            ptr=strtok(NULL," ");
            c=atof(ptr);
            ptr=strtok(NULL," ");
            //strcpy(arr2,ptr);
            b=m[ptr];
            arr[a][b]=c;
        }
        for(k=1; k<=n; k++)
        {
            for(i=1; i<=n; i++)
            {
                for(j=1; j<=n; j++)
                {
                    arr[i][j]=max(arr[i][j],arr[i][k]*arr[k][j]);
                }
            }
        }
        for(i=1;i<=n;i++)
        if(arr[i][i]>1.)
        {
            flag=1;
            break;
        }
        if(flag)
        printf("Case %d: Yes\n",t++);
        else
        printf("Case %d: No\n",t++);
    }
    return 0;
}
