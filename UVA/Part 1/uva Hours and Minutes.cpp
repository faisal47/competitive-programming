#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
bool flag[200];
int main ()
{
    memset(flag,0,sizeof(flag));
    int a,b;
    int i,j;
    for(i=1;i<=12;i++)
    for(j=0;j<60;j++)
    {
        a=i;b=j;
        a*=5;
      a+=(b/12);
      if(a<=b)
      a=b-a;
      else
      a-=b;
      a*=6;
      if(a>180)
      a=360-a;
      if((int)a==a)
      {
          flag[(int)a]=1;
          // cout<<a<<endl;
      }
//      cout<<a<<endl;
//      cout<<i<<" "<<j<<endl;
     // flag[(int)a]=1;
    }
    while(cin>>i)
    {
        if(flag[i]==1)
        cout<<"Y"<<endl;
        else
        cout<<"N"<<endl;
    }
    return 0;
}

