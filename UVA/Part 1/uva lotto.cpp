#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    int n,arr[30],i,j,k,l,m,p,c=0;
    while(cin>>n)
    {
        if(n==0)
        break;
        if(c)
        cout<<endl;
        for(i=0;i<n;i++)
        cin>>arr[i];
        for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
        for(k=j+1;k<n;k++)
        for(l=k+1;l<n;l++)
        for(m=l+1;m<n;m++)
        for(p=m+1;p<n;p++)
        printf("%d %d %d %d %d %d\n",arr[i],arr[j],arr[k],arr[l],arr[m],arr[p]);
    c++;
    }
    return 0;
}
