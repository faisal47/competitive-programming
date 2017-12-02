#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct inf
{
    string a;
    int b,c,d;
};
vector<inf>info;
bool sign(inf a,inf b)
{
    if(a.d!=b.d)
    return a.d<b.d;
    else if(a.c!=b.c)
    return a.c<b.c;
    else
    return a.b<b.b;
}
int main ()
{
    inf input;
    int test,i;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>input.a>>input.b>>input.c>>input.d;
        info.push_back(input);
    }
    sort(info.begin(),info.end(),sign);
    cout<<info[test-1].a<<endl;
    cout<<info[0].a<<endl;
    return 0;
}
