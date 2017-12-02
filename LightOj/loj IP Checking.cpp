#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int main ()
{
    int a[10],test,t,c,i,j,k,flag;
    char arr[10][20],z,arr1[100],*arr2;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        flag=c=0;
        scanf("%d.%d.%d.%d",&a[0],&a[1],&a[2],&a[3]);
       // printf("%d.%d.%d.%d\n",a[0],a[1],a[2],a[3]);
        scanf("%c",&z);
        gets(arr1);
        arr2=strtok(arr1,".");
     //   strcpy(arr[c++],arr2);
        while(arr2!=NULL)
        {
            strcpy(arr[c++],arr2);
            arr2=strtok(NULL,".");
            //(arr[c++],arr2);
        }
       // cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<endl;
        for(i=0;i<4;i++)
        {
            c=7;k=0;
            for(j=0;j<8;j++)
            k+=(arr[i][j]-'0')*pow(2,c--);
            if(k!=a[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        printf("Case %d: No\n",t);
        else
        printf("Case %d: Yes\n",t);
    }
    return 0;
}
