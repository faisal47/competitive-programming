#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
    return a;
    else
    return gcd(b,a%b);
}
int main ()
{
    int test,arr1[110],c,i,j,maxi;
    char arr[10000],z,*ptr;
    scanf("%d",&test);
    scanf("%c",&z);
    while(test--)
    {
        gets(arr);
        c=0;maxi=1;
        ptr=strtok(arr," ");
        while(ptr!=NULL)
        {
            arr1[c++]=atoi(ptr);
            ptr=strtok(NULL," ");
        }
        for(i=0;i<c;i++)
        for(j=i+1;j<c;j++)
        maxi=max(maxi,gcd(arr1[i],arr1[j]));
        cout<<maxi<<endl;
    }
    return 0;
}
