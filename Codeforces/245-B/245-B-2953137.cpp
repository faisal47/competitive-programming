#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "string"
#include "vector"
#include "math.h"
#include "map"
#include "stack"
#include "queue"
#include "algorithm"
#include "iostream"

#define inf 1<<28
#define SD(n) scanf("%d",&n)
#define SS(n) scanf("%s",n)
#define SLF(n) scanf("%lf",n)
#define FOR(i,n) for(i=0;i<n;i++)
#define FORI(i,a,n) for(i=a;i<=n;i++)
#define SZ 1010
using namespace std;
char arr[110];

int main()
{
    int i,j,k,n,len,f,h,flag;
    string a;
    while(scanf(" %[^\n]",arr) == 1)
    {

        a.clear();
        if(arr[0] == 'f')
        {
            flag=1;
            cout<<"ftp://";
        }
        else
        {
            flag=2;
            cout<<"http://";
        }
        if(flag==1)
        f=3;
        else
        f=4;
        cout<<arr[f];
        for(i=f+1;i<strlen(arr)-1;i++)
        {
            if(arr[i]=='r'&&arr[i+1]=='u')
            {
                cout<<a<<'.'<<"ru";
                f=i+2;
                break;
            }
            else
            {
                a+=arr[i];
            }
        }
        for(i=f;i<strlen(arr);i++)
        {
            if(i==f)
            cout<<'/';
            cout<<arr[i];
        }
        cout<<endl;
    }



    return 0;
}