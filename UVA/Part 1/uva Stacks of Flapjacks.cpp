#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>
using namespace std;
vector<int>v;
void rev(int start,int end)
{
    while(1)
    {
        if(start>=end)
        break;
        swap(v[start],v[end]);
        start++;end--;
    }
    return;
}
int main ()
{
    vector<int>out;
    char *ptr,arr[10000];
    int i,maxi,pos,s;
    bool flag;
    while(gets(arr))
    {
        cout<<arr<<endl;
        v.clear();
        out.clear();
        ptr=strtok(arr," ");
        while(ptr!=NULL)
        {
            v.push_back(atoi(ptr));
            ptr=strtok(NULL," ");
        }
        s=v.size();
        while(1)
        {
            flag=0;
            maxi=v[0];
            pos=0;
            for(i=1;i<v.size();i++)
            {
                if(v[i]<v[i-1])
                flag=1;
                if(v[i]>maxi)
                {
                    maxi=v[i];
                    pos=i;
                }
            }
            if(flag==0)
            {
                out.push_back(0);
                break;
            }
            else if(flag==1&&pos==v.size()-1)
            {
                v.pop_back();
            }
            else if(pos==0)
            {
                rev(0,v.size()-1);
                out.push_back(s-v.size()+1);
                v.pop_back();
            }
            else
            {
                rev(0,pos);
                out.push_back(s-pos);
                rev(0,v.size()-1);
                out.push_back(s-v.size()+1);
                v.pop_back();
            }
        }
        cout<<out[0];
        for(i=1;i<out.size();i++)
        cout<<" "<<out[i];
        cout<<endl;
    }
    return 0;
}
