#include <stdio.h>
#include <iostream>
#include <map>
#include <string.h>
using namespace std;
#define inf 1<<28
int main ()
{
    int test,t,len,dist[205][205],i,len1,len2,a,b,j,k,c;
    char z,arr1[205][15],arr2[25],*ptr,arr3[15],arr4[15];
    map<string,int>m;
    scanf("%d",&test);
    scanf("%c",&z);
    scanf("%c",&z);
    while(test--)
    {
        m.clear();
        t=1;
        while(gets(arr1[t]))
        if(arr1[t][0]=='*')
        break;
        else
        m[arr1[t]]=t++;
        for(i=1;i<t;i++)
        for(j=1;j<t;j++)
        if(i==j)
        dist[j][i]=dist[i][j]=0;
        else
        {
            len1=strlen(arr1[i]);
            len2=strlen(arr1[j]);
            a=m[arr1[i]];
            b=m[arr1[j]];
            if(len1!=len2)
            dist[a][b]=dist[b][a]=inf;
            else
            {
                c=0;
                for(k=0;k<len1;k++)
                if(arr1[i][k]!=arr1[j][k])
                c++;
                if(c==1)
                dist[a][b]=dist[b][a]=1;
                else
                dist[a][b]=dist[b][a]=inf;
            }

        }
        for(k=1;k<t;k++)
        for(i=1;i<t;i++)
        for(j=1;j<t;j++)
        if(i!=j)
        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
//         for(i=1;i<t;i++)
//        for(j=1;j<t;j++)
//        cout<<dist[i][j]<<endl;
        while(gets(arr2))
        {
            if(strlen(arr2)==0)
            break;
            ptr=strtok(arr2," ");
            strcpy(arr3,ptr);
            ptr=strtok(NULL," ");
            strcpy(arr4,ptr);
//            a=m[arr2];
//            b=m[arr3];
//            cout<<a<<" "<<b<<endl;
            //cout<<arr3<<" "<<arr4<<endl;
            cout<<arr3<<" "<<arr4<<" "<<dist[m[arr3]][m[arr4]]<<endl;
        }
        if(test)
        cout<<endl;
    }
    return 0;
}
