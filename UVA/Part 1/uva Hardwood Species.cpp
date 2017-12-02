#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main ()
{
    string a;
    char z;
    int test,i=0;
    double result;
    map<string,int>m;
    map<string,int>::iterator it;
    cin>>test;
    scanf("%c",&z);
    scanf("%c",&z);
    while(test--)
    {
        while(getline(cin,a))
        {
            if(a.size()==0)
            break;
            i++;
            if(m.find(a)==m.end())
            {
                m[a]=1;
            }
            else
            {
                m.find(a)->second+=1;
            }
        }
        for(it=m.begin();it!=m.end();it++)
        {
            cout<<it->first;
            result=((double)it->second/(double)i)*100;
            printf(" %.4lf",result);
            cout<<endl;
        }
        i=0;
        if(test!=0)
        cout<<endl;
        m.clear();
    }
    return 0;
}
