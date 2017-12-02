#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main ()
{
    int arr[20][3],flag=0;
    char arr1[30],z;
    int n,count=0,i;
    while((scanf("%d%c",&n,&z))==2)
    {
        if(n==0)
            break;
        gets(arr1);
        if(strcmp(arr1,"too high")==0)
        {
            arr[count][0]=n;
            arr[count][1]=1;
            count++;
        }
        else if(strcmp(arr1,"too low")==0)
        {
            arr[count][0]=n;
            arr[count][1]=2;
            count++;
        }
        else
        {
            for(i=0; i<count; i++)
                {
                    if(arr[i][1]==1&&arr[i][0]<=n)
                    {
                        flag=1;
                        break;
                    }
                    else if(arr[i][1]==2&&arr[i][0]>=n)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                cout<<"Stan may be honest"<<endl;
                else
                cout<<"Stan is dishonest"<<endl;
                flag=0;count=0;
        }
    }
    return 0;
}
