#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
bool comp(const char &a,const char &b)
{
    int dushang=tolower(a)-tolower(b);
    if(dushang)
        return dushang<0;
    else
    return a<b;
}
int main ()
{
    int i,j,test,len;
    char temp,a[1000000];
    scanf("%d",&test);
    scanf("%c",&temp);
    while(test--)
    {
        gets(a);
        len=strlen(a);
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(toupper(a[i])==toupper(a[j]))
                {
                    if(a[i]>a[j])
                    {
                        temp=a[i];
                        a[i]=a[j];
                        a[j]=temp;
                    }
                }
                else if(toupper(a[i])>toupper(a[j]))
                {
                    temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
            }
        }
        do
        {
            for(i=0; i<len; i++)
                cout<<a[i];
            cout<<endl;
        }while(next_permutation(a,a+len,comp));
    }
    return 0;
}
