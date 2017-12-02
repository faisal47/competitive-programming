#include <stdio.h>
#include <iostream>
#include <map>
#include <string.h>
using namespace std;
int main ()
{
    char a[800],b[800];
    string a1;
    map<string,string>team;
    map<string,int>vote;
    map<string,int>::iterator it;
    int test,m,maxi,flag,team_number,i;
    char z;
    cin>>test;
    while(test--)
    {
        flag=0;
        team.clear();
        vote.clear();
        scanf("%d",&team_number);
        scanf("%c",&z);
        for(i=0;i<team_number;i++)
        {
            scanf(" %[^\n]",&a);
            scanf(" %[^\n]",&b);
            team[a]=b;
            vote[a]=0;
        }
        scanf("%d",&m);
        scanf("%c",&z);
        while(m--)
        {
            scanf(" %[^\n]",&a);
            if(vote.find(a)!=vote.end())
            vote[a]++;
        }
        maxi=0;
        for(it=vote.begin();it!=vote.end();it++)
        {
            if(maxi<it->second)
            {
                a1=it->first;
                maxi=it->second;
            }
        }
        for(it=vote.begin();it!=vote.end();it++)
        {
            if(maxi==it->second)
            flag++;
        }
        if(flag>1||maxi==0)
        cout<<"tie"<<endl;
        else
        cout<<team[a1]<<endl;
        if(test)
        cout<<endl;
    }
    return 0;
}
