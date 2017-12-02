#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int main ()
{
    char arr[15],z;
    int i,len,test;
    scanf("%d",&test);
    scanf("%c",&z);
    while(test--)
    {
        gets(arr);
        len=strlen(arr);
        vector<char>v(arr,arr+len);
        sort(v.begin(),v.begin()+len);
        do
        {
            for(i=0;i<len;i++)
            cout<<v[i];
            cout<<endl;
        }
        while(next_permutation(v.begin(),v.begin()+len));
        cout<<endl;
    }
    return 0;
}
