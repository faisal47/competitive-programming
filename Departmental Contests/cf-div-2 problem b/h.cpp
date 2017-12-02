#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <utility>
#define sz(a) a.size()
using namespace std;
int main ()
{
    string st;
    cin>>st;
    int i,j;
    if(sz(st)&1)
    cout<<"No";
    else
    {
        //cout<<"test\n";
        i=0;j=sz(st);
        stack<char>s;
        s.push(st[i++]);
        while(i<j)
        {
//            cout<<"test\n";
          //  cout<<st[i]<<" "<<i<<endl;
            if(!s.empty() && s.top()==st[i])s.pop();
            else s.push(st[i]);
            i++;
        }
//        cout<<"test\n";
        if(s.empty())
        cout<<"Yes";
        else cout<<"No";

//        cout<<"test\n";
    }
    return 0;
}

