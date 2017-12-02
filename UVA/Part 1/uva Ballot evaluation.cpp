#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main ()
{
    string sign,a;
    int m,n,flag,dam2,dam3;
    double dam,dam1;
    char arr[1000],*ptr;
    map<string,double>m1;
    m1.clear();
    cin>>m>>n;
    //cout<<m<<" "<<n<<endl;
    while(m--)
    {
        cin>>a>>dam;
        m1[a]=dam;
        gets(arr);
    }
    for(m=1;m<=n;m++)
    {
        gets(arr);
        dam=0;flag=0;
        ptr=strtok(arr," +");
        while(ptr!=NULL)
        {
            if(m1.find(ptr)!=m1.end())
            dam+=m1[ptr];
            else if(flag==0)
            {
                flag=1;
                sign=ptr;
            }
            else
            {
                dam1=atof(ptr);
            }
            ptr=strtok(NULL," +");
        }
        //dam2=(int)dam;
     //   dam3=(int)dam1;
      //  cout<<sign<<" "<<dam<<" "<<dam1<<endl;
        printf("Guess #%d was ",m);
        if(sign==">")
        {
            if(dam>dam1)
            cout<<"correct.\n";
            else
            cout<<"incorrect.\n";
        }
        else if(sign=="<")
        {
            if(dam<dam1)
            cout<<"correct.\n";
            else
            cout<<"incorrect.\n";
        }
        else if(sign=="<=")
        {
            if(dam<=dam1)
            cout<<"correct.\n";
            else
            cout<<"incorrect.\n";
        }
        else if(sign==">=")
        {
            if(dam>=dam1)
            cout<<"correct.\n";
            else
            cout<<"incorrect.\n";
        }
         else if(sign=="=")
        {
            if(dam==dam1)
            cout<<"correct.\n";
            else
            cout<<"incorrect.\n";
        }
    }
    return 0;
}
