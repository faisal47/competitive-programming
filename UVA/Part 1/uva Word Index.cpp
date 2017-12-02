#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
using namespace std;
int main ()
{
    map<string,int>m;
    string str;
    int i,j,k,l,mi,count=1;
    map<string,int>::iterator it;
    for(i='a'; i<='z'; i++)
    {
        str=i;
        m[str]=count++;
    }
    for(i='a'; i<='z'; i++)
    {
        for(j=i+1; j<='z'; j++)
        {
            str=i;
            str+=j;
            m[str]=count++;
        }
    }
    for(i='a'; i<='z'; i++)
    {
        for(j=i+1; j<='z'; j++)
        {
            for(k=j+1; k<='z'; k++)
            {
                str=i;
                str+=j;
                str+=k;
                m[str]=count++;
            }
        }
    }
    for(i='a'; i<='z'; i++)
    {
        for(j=i+1; j<='z'; j++)
        {
            for(k=j+1; k<='z'; k++)
            {
                for(l=k+1; l<='z'; l++)
                {
                    str=i;
                    str+=j;
                    str+=k;
                    str+=l;
                    m[str]=count++;
                }
            }
        }
    }
    for(i='a'; i<='z'; i++)
    {
        for(j=i+1; j<='z'; j++)
        {
            for(k=j+1; k<='z'; k++)
            {
                for(l=k+1; l<='z'; l++)
                {
                    for(mi=l+1; mi<='z'; mi++)
                    {
                        str=i;
                        str+=j;
                        str+=k;
                        str+=l;
                        str+=mi;
                        m[str]=count++;
                    }
                }
            }
        }
    }
    while(cin>>str)
    {
        if(m.find(str)==m.end())
        cout<<0<<endl;
        else
        cout<<m[str]<<endl;
    }
    return 0;
}
