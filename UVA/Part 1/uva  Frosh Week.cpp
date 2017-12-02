#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
long long int arr[100000010],tempo[100000010];
long long int c;
void merging(int left,int mid,int right)
{
    int len=mid-left,lp=0;len++;
    int pos=0,lpos = left,rpos = mid+1;
    while(lpos<=mid && rpos<=right)
    {
        if(arr[lpos] <= arr[rpos])
            {
                tempo[pos++] = arr[lpos++];lp++;
            }
        else
            {
                c+=len-lp;
                tempo[pos++] = arr[rpos++];
            }
    }
    while(lpos <= mid)tempo[pos++] = arr[lpos++];
    while(rpos <= right)tempo[pos++] = arr[rpos++];
    int i;
    for(i=0;i<pos;i++)
    {
        arr[left+i] = tempo[i];
    }
    return;
}

void merge(int left,int right)
{
    int mid = (left + right) / 2;
    if(left < right)
    {
        merge(left,mid);
        merge(mid+1,right);
        merging(left,mid,right);
    }
    return;
}

int main()
{
    int test,n;
    while(cin>>test)
    {
        n=1;
        while(test--)
        cin>>arr[n++];
        c=0;n--;
        merge(1,n);
        cout<<c<<endl;
    }
    return 0;
}


