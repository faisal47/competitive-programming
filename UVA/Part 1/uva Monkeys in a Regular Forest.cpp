#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map>
using namespace std;
int main ()
{
    char arr[1000][1000];
    int c=0,len,count,j,i,flag;
    map<char,int>m;
    map<char,int>::iterator it;
    while(gets(arr[c++]))
    {
        if(arr[c-1][0]=='%')
        {
            m.clear();
            count=1;
            len=strlen(arr[c-2]);
            for(i=0; i<c-1; i++)
            {
                for(j=0; j<len; j++)
                {
                    if(arr[i][j]!=' ')
                    {
                        if(m.find(arr[i][j])==m.end())
                        {
                            m[arr[i][j]]=count++;
                        }
                    }
                }
            }
            count--;
            if(count<10)
                flag=1;
            else if(count<100)
                flag=2;
            else if(count<1000)
                flag=3;
            else if(count<10000)
                flag=4;
            for(i=0; i<c-1; i++)
            {
                for(j=0; j<len; j++)
                {
                    if(arr[i][j]!=' ')
                    {
                        it=m.find(arr[i][j]);
                        if(flag==1)
                            cout<<it->second;
                        else if(flag==2)
                            printf("%2d",it->second);
                        else if(flag==3)
                            printf("%3d",it->second);
                        else if(flag==4)
                            printf("%4d",it->second);
                    }
                    else
                        cout<<" ";
                }
                cout<<endl;
            }
            cout<<"%"<<endl;
            c=0;
        }
    }
    m.clear();
    count=1;
    len=strlen(arr[c-2]);
    for(i=0; i<c-1; i++)
    {
        for(j=0; j<len; j++)
        {
            if(arr[i][j]!=' ')
            {
                if(m.find(arr[i][j])==m.end())
                {
                    m[arr[i][j]]=count++;
                }
            }
        }
    }
    count--;
    if(count<10)
        flag=1;
    else if(count<100)
        flag=2;
    else if(count<1000)
        flag=3;
    else if(count<10000)
        flag=4;
    for(i=0; i<c-1; i++)
    {
        for(j=0; j<len; j++)
        {
            if(arr[i][j]!=' ')
            {
                it=m.find(arr[i][j]);
                if(flag==1)
                    cout<<it->second;
                else if(flag==2)
                    printf("%2d",it->second);
                else if(flag==3)
                    printf("%3d",it->second);
                else if(flag==4)
                    printf("%4d",it->second);
            }
            else
                cout<<" ";
        }
        cout<<endl;
    }
    cout<<"%"<<endl;
    return 0;
}
