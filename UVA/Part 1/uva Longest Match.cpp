#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map>
using namespace std;
map<string,int>m;
char arr1[1010],arr2[1010];
int a1[1010],a2[1010],c[1010][1010],len1,len2;
int lcsf(void)
{
    int i,j;
    len1--;len2--;
    for(i=1;i<=len1;i++)
    for(j=1;j<=len2;j++)
    if(a1[i]==a2[j])
    c[i][j]=c[i-1][j-1]+1;
    else
    c[i][j]=max(c[i-1][j],c[i][j-1]);
    return c[len1][len2];
}
int main ()
{
    int i,chinno,lcs,test=1;
    char *ptr;
    while(gets(arr1))
    {
        gets(arr2);
        len1=strlen(arr1);
        len2=strlen(arr2);
        for(i=0;i<len1;i++)
        if((arr1[i]>='0'&&arr1[i]<='9')||(arr1[i]>='A'&&arr1[i]<='Z')||(arr1[i]>='a'&&arr1[i]<='z'))
        ;
        else
        arr1[i]=' ';
        for(i=0;i<len2;i++)
        if((arr2[i]>='0'&&arr2[i]<='9')||(arr2[i]>='A'&&arr2[i]<='Z')||(arr2[i]>='a'&&arr2[i]<='z'))
        ;
        else
        arr2[i]=' ';
        len1=len2=chinno=1;
        m.clear();
        ptr=strtok(arr1," ");
        while(ptr!=NULL)
        {
            if(m.find(ptr)==m.end())
            m[ptr]=chinno++;
            a1[len1++]=m[ptr];
            ptr=strtok(NULL," ");
        }
        ptr=strtok(arr2," ");
        while(ptr!=NULL)
        {
            if(m.find(ptr)==m.end())
            m[ptr]=chinno++;
            a2[len2++]=m[ptr];
            ptr=strtok(NULL," ");
        }
        lcs=lcsf();
        if(lcs==0)
        printf("%2d. Blank!\n",test++);
        else
        printf("%2d. Length of longest match: %d\n",test++,lcs);
    }
    return 0;
}
