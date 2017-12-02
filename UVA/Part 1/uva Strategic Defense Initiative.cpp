#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
using namespace std;
int inf=123456789;
int main ()
{
    char arr[100];
    vector<int>v;
    int len,test,c,i,arr1[100000],l[100000],I[100000],lis,low,high,mid,lis1;
    scanf("%d",&test);
    gets(arr);
    gets(arr);
    while(test--)
    {
        c=0;
        v.clear();
        I[c]=-inf;
        while(gets(arr))
        {
            len=strlen(arr);
            if(len==0)
            break;
            len=atoi(arr);
            arr1[c]=len;
            I[c+1]=inf;
            c++;
        }
        lis=0;
        for(i=0;i<c;i++)
        {
            low=0;high=lis;
            while(low<=high)
            {
                mid=(low+high)/2;
                if(I[mid]<arr1[i])
                low=mid+1;
                else
                high=mid-1;
            }
            I[low]=arr1[i];
            l[i]=low;
            lis=max(lis,low);
        }
        lis1=lis;
        printf("Max hits: ");
        cout<<lis<<endl;
        for(i=c-1;i>=0;i--)
        {
            if(l[i]==lis1)
            {
                v.push_back(arr1[i]);
                lis1--;
            }
            if(lis1<1)
            break;
        }
        for(i=v.size()-1;i>=0;i--)
        cout<<v[i]<<endl;
        if(test)
        cout<<endl;
    }
    return 0;
}
