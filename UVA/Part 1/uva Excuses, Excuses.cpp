#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map>
#include <ctype.h>
using namespace std;
int main ()
{
    map<string,int>key;
    int n,m,i,len,c[25],j,maxi,test=1;
    char *pch,arr[80],arr1[25][80];
    while(scanf("%d %d",&n,&m)==2)
    {
        gets(arr);
        key.clear();
        while(n--)
        {
            gets(arr);
            key[arr]=1;
        }
        for(i=0;i<m;i++)
        {
            gets(arr1[i]);
            c[i]=0;
            len=strlen(arr1[i]);
            for(j=0;j<len;j++)
            {
                arr[j]=tolower(arr1[i][j]);
                if(arr[j]<'a'||arr[j]>'z')
                arr[j]='.';
            }
            pch=strtok(arr,".");
            while(pch!=NULL)
            {
                if(key[pch]==1)
                c[i]++;
                pch=strtok(NULL,".");
            }
        }
        maxi=0;
        for(i=0;i<m;i++)
        if(maxi<c[i])
        maxi=c[i];
        printf("Excuse Set #%d\n",test++);
        for(i=0;i<m;i++)
        if(maxi==c[i])
        cout<<arr1[i]<<endl;
        cout<<endl;
    }
    return 0;
}
