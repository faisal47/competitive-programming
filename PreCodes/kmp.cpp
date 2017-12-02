#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
string text,pattern;
int f[2000010],c;
void kmp()
{
    int len1=text.size(),len2=pattern.size();
    pattern.push_back('#');
    pattern+=text;
    int k;
    f[0]=k=0;
    int i;
    for(i=1;i<pattern.size();i++)
    {
        while(k>0 && pattern[i]!=pattern[k])
        k=f[k-1];
        if(pattern[i]==pattern[k])
        k++;
        f[i]=k;
    }
    for(i=len2+1;i<pattern.size();i++)
    if(f[i]==len2)
    c++;
}

int main ()
{
    int test,t;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        c=0;
        cin>>text>>pattern;
        kmp();
        printf("Case %d: %d\n",t,c);
    }
    return 0;
}
