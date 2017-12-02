#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <map>
#include <math.h>
#include <ctype.h>
using namespace std;
#define inf 1<<28
bool sign1(char a,char b)
{
    if(tolower(a)==tolower(b))
    {
        return a<b;
    }
    else
    return tolower(a)<tolower(b);
}
bool sign2(char a,char b)
{
    int d=(int)(tolower(a))-(int)(tolower(b));
    if(d)
    return d<0;
    else
    return a<b;
}
int main ()
{
    char arr[105],z;
    int test,len;
    scanf("%d",&test);
    scanf("%c",&z);
    while(test--)
    {
        gets(arr);
        len=strlen(arr);
        sort(arr,arr+len,sign1);
        do
        {
            cout<<arr<<endl;
        }
        while(next_permutation(arr,arr+len,sign2));
    }
    return 0;
}

