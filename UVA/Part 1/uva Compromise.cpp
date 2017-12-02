#include <stdio.h>
#include <iostream>
#include <map>
#include <string.h>
#include <vector>
using namespace std;
int a1[110],a2[110],len1,len2,C[110][110];
int lcsf(void)
{
    int i,j;
    for(i=1; i<len1; i++)
        for(j=1; j<len2; j++)
            if(a1[i]==a2[j])
                C[i][j]=C[i-1][j-1]+1;
            else
                C[i][j]=max(C[i-1][j],C[i][j-1]);
    return C[len1-1][len2-1];
}
int main ()
{
    len1=len2=1;
    int fend=0,t=1,lcs,i,j;
    map<string,int>m1;
    map<int,string>m2;
    vector<int>v;
    char *ptr,arr[100000];
    while(gets(arr))
    {
        if(arr[0]=='#')
            fend=1;
        if(fend==0)
        {
            ptr=strtok(arr," ");
            while(ptr!=NULL)
            {
                if(m1.find(ptr)==m1.end())
                {
                    m1[ptr]=t;
                    m2[t]=ptr;
                    t++;
                }
                a1[len1++]=m1[ptr];
                ptr=strtok(NULL," ");
            }
        }
        else
        {
            while(gets(arr))
            {
                if(arr[0]=='#')
                    break;
                ptr=strtok(arr," ");
                while(ptr!=NULL)
                {
                    if(m1.find(ptr)==m1.end())
                    {
                        m1[ptr]=t;
                        m2[t]=ptr;
                        t++;
                    }
                    a2[len2++]=m1[ptr];
                    ptr=strtok(NULL," ");
                }
            }
            lcs=lcsf();
            t=lcs;
            fend=0;
            for(i=len1-1; i>0; i--)
            {
                for(j=len2-1; j>0; j--)
                {
                    if(C[i][j]==t&&C[i-1][j]!=t&&C[i][j-1]!=t)
                    {
                        v.push_back(a2[j]);
                       // if(fend++)
                           // cout<<" ";
                       // cout<<m2[a2[j]];
                        t--;
                        if(t<1)
                            break;
                    }
                }
                if(t<1)
                    break;
            }
            for(i=v.size()-1;i>-1;i--)
            {
                cout<<m2[v[i]];
                if(i)
                cout<<" ";
            }
            cout<<endl;
            fend=0;
            len1=len2=t=1;
            m1.clear();
            v.clear();
            m2.clear();
        }
    }
    return 0;
}
