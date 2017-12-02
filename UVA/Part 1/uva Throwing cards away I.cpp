#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main ()
{
    int arr[10000],dc[10000],n,i,j,k,l,c1,c2,c3;
    memset(arr,0,sizeof(arr));
    memset(dc,0,sizeof(dc));
    while((scanf("%d",&n))==1)
    {
        if(n==0)
        break;
        if(n==1)
        {
            printf("Discarded cards:\nRemaining card: 1\n");
            continue;
        }
        else if(n==2)
        {
            printf("Discarded cards: 1\nRemaining card: 2\n");
            continue;
        }
        for(i=0;i<n;i++)
        arr[i]=i+1;
        c1=n;c2=c3=0;
        while(1)
        {
            if(arr[c1-3]==0)
            break;
            dc[c2++]=arr[c3];
            arr[c1++]=arr[c3+1];
            arr[c3]=arr[c3+1]=0;
            c3+=2;
        }
        dc[c2++]=arr[c1-2];
        cout<<"Discarded cards:";
        for(i=0;i<c2;i++)
        {
            if(i>0)
            printf(",");
            printf(" %d",dc[i]);
        }
        cout<<endl<<"Remaining card: "<<arr[c1-1]<<endl;
        memset(arr,0,sizeof(arr));
        memset(dc,0,sizeof(dc));
    }
    return 0;
}
