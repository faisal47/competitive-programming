#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
    int test,t,i,n,k,c;
    char z;
    char v[30];
    cin>>test;
    for(t=1; t<=test; t++)
    {
        z='A';
        c=0;
        cin>>n>>k;
        for(i=0; i<n; i++)
            v[i]=z++;
        printf("Case %d:\n",t);
        do
        {
            for(i=0; i<n; i++)
              cout<<v[i];
            cout<<endl;
            c++;
            if(c>=k)
                break;
        }
        while(next_permutation(v,v+n));
    }

}
