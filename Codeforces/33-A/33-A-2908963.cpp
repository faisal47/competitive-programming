#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map>
#include <ctype.h>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#define inf 123456789
using namespace std;
int main ()
{
    int m,n,t,i,r,row[1100],j;
    row[0]=0;
    while(cin>>m>>n>>t)
    {
        for(i=1;i<=n;i++)
        row[i]=123456789;
        for(i=0;i<m;i++)
        {
            cin>>j>>r;
            if(row[j]>r)
            row[j]=r;
        }
        r=0;
        sort(row,row+n+1);
        for(i=n;i>=1;i--)
        {
            r+=row[i];
        }
        if(r<=t)
        cout<<r<<endl;
        else
        cout<<t<<endl;
    }
    return 0;
}