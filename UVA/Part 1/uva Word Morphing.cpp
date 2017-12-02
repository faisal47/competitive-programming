#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
char arr[5000],arr1[2000][50000],start[5000],end[5000],z;
int main ()
{
    int i,j,count,k,l;
    while(scanf("%d %d",&i,&j)==2)
    {
        scanf("%c",&z);
       // cout<<i<<" "<<j<<endl;
        gets(start);
        gets(end);
        for(k=0;k<i-2;k++)
        {
            gets(arr);
            count=0;
            for(l=0;l<j;l++)
            if(arr[l]!=start[l])
            count++;
            strcpy(arr1[count],arr);
        }
        cout<<start<<endl;
        for(k=1;k<=i-2;k++)
        cout<<arr1[k]<<endl;
        cout<<end<<endl;
    }
    return 0;
}
