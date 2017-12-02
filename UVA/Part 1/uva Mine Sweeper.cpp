#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main ()
{
    int arr[20][20],test,t,i,n,j,flag;
    memset(arr,0,sizeof(arr));
    char z,arr1[20][20],arr2[20][20];
    cin>>test;
    for(t=0; t<test; t++)
    {
        flag=0;
        if(t)
            cout<<endl;
        scanf("%d",&n);
        scanf("%c",&z);
        for(i=0; i<n; i++)
            gets(arr1[i]);
        for(i=0; i<n; i++)
            gets(arr2[i]);
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
            {
                if(arr1[i][j]=='*')
                {
                    if((j-1)>=0)
                        arr[i][j-1]++;
                    if((i-1)>=0)
                        arr[i-1][j]++;
                    if((j+1)<=(n-1))
                        arr[i][j+1]++;
                    if((i+1)<=(n-1))
                        arr[i+1][j]++;
                    if((i-1)>=0&&(j-1)>=0)
                        arr[i-1][j-1]++;
                    if((i-1)>=0&&(j+1)<=n)
                        arr[i-1][j+1]++;
                    if((i+1)<=n&&(j+1)<=n)
                        arr[i+1][j+1]++;
                    if((i+1)<=n&&(j-1)>=0)
                        arr[i+1][j-1]++;
                }
            }
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                if(arr2[i][j]=='x'&&arr1[i][j]=='*')
                    flag=1;
        if(flag==1)
        {
            for(i=0; i<n; i++)
            {
                for(j=0; j<n; j++)
                    if(arr2[i][j]=='x'&&arr1[i][j]!='*')
                        cout<<arr[i][j];
                    else
                    cout<<arr1[i][j];
                cout<<endl;
            }
        }
        else
        {
            for(i=0; i<n; i++)
            {
                for(j=0; j<n; j++)
                    if(arr2[i][j]=='x'&&arr1[i][j]!='*')
                        cout<<arr[i][j];
                    else
                        cout<<".";
                cout<<endl;
            }
        }
        memset(arr,0,sizeof(arr));
    }
    return 0;
}
