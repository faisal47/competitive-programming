#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main ()
{
    char arr[1010];
    int c=1,len,i,arr1[150],arr2[150][3],temp,j;
    while(gets(arr))
    {
        if(c!=1)
        cout<<endl;
        memset(arr1,0,sizeof(arr1));
        len=strlen(arr);
        for(i=0;i<len;i++)
        arr1[arr[i]]++;
        c=0;
        for(i=0;i<140;i++)
        {
            if(arr1[i]>0)
            {
                arr2[c][0]=i;
                arr2[c][1]=arr1[i];
                c++;
            }
        }
        for(i=0;i<c-1;i++)
        for(j=i+1;j<c;j++)
        {
            if(arr2[i][1]>arr2[j][1])
            {
                temp=arr2[i][1];
                arr2[i][1]=arr2[j][1];
                arr2[j][1]=temp;
                temp=arr2[i][0];
                arr2[i][0]=arr2[j][0];
                arr2[j][0]=temp;

            }
            if(arr2[i][1]==arr2[j][1]&&arr2[i][0]<arr2[j][0])
            {
                temp=arr2[i][0];
                arr2[i][0]=arr2[j][0];
                arr2[j][0]=temp;
            }
        }
        for(i=0;i<c;i++)
            cout<<arr2[i][0]<<" "<<arr2[i][1]<<endl;
        c=2;
    }
    return 0;
}
