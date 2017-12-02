#include <stdio.h>
#include <iostream>
#include <stack>
#include <string.h>
#include <vector>
#include <map>
using namespace std;
int main ()
{
    char arr[10];
    map<char,int>m;
    m['+']=1;
    m['-']=1;
    m['*']=2;
    m['/']=2;
    stack<char>s;
    vector<char>v;
    int len,i,test,c,c1,flag;
    scanf("%d",&test);
    gets(arr);
    gets(arr);
    while(test--)
    {
        v.clear();
        while(!s.empty())
        s.pop();
        while(gets(arr))
        {
            len=strlen(arr);
            if(len==0)
            break;
            c=arr[0];
            if(c>='0'&&c<='9')
            v.push_back(c);
            else if(c=='(')
            s.push(c);
            else if(c==')')
            {
                while(!s.empty())
                {
                    if(s.top()=='(')
                       {
                           s.pop();
                           break;
                       }
                    else
                    {
                        v.push_back(s.top());
                        s.pop();
                    }
                }
            }
            else
            {
                while(!s.empty())
                {
                   if(s.top()=='(')
                      {
                          break;
                      }
                    c1=s.top();
                    if(m[c1]<m[c])
                    {
                        break;
                    }
                    else
                    {
                        v.push_back(c1);
                        s.pop();
                    }
                }
                s.push(c);
            }
        }
        while(!s.empty())
            {
                c1=s.top();
                v.push_back(c1);
                s.pop();
            }
        for(i=0;i<v.size();i++)
            cout<<v[i];
            cout<<endl;
            if(test)
            cout<<endl;
    }
    return 0;
}
