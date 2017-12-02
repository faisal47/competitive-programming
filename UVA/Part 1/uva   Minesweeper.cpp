#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main ()
{
    int a,b,i,j,test=0,arr1[102][102];
    char z,arr[102][102];
    while((scanf("%d %d",&a,&b))==2)
    {
        scanf("%c",&z);
        if(a==0&&b==0)
            break;
        memset(arr1,0,sizeof(arr1));
        for(i=0; i<a; i++)
            gets(arr[i]);
        for(i=0; i<a; i++)
            for(j=0; j<b; j++)
            {
                if(arr[i][j]=='*')
                {
                    if(j>0)
                        arr1[i][j-1]+=1;
                    if(i>0&&j>0)
                        arr1[i-1][j-1]+=1;
                    if(i>0)
                        arr1[i-1][j]+=1;
                    if(i>0)
                        arr1[i-1][j+1]+=1;
                    arr1[i][j+1]+=1;
                    arr1[i+1][j+1]+=1;
                    arr1[i+1][j]+=1;
                    if(j>0)
                        arr1[i+1][j-1]+=1;
                }
            }
        if(test>0)
        cout<<endl;
        printf("Field #%d:\n",++test);
        for(i=0; i<a; i++)
        {
            for(j=0; j<b; j++)
            {
                if(arr[i][j]=='*')
                cout<<arr[i][j];
                else
                cout<<arr1[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
