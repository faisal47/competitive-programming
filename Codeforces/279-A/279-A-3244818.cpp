#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    int x,y,i,a1[500][2],a2[500][2],a3[500][2],a4[500][2],c,x1,x2,y1,y2;
    bool flag;
    for(i=1;i<=110;i++)
    {
        a2[i][0]=i;
        a2[i][1]=i;
    }
    for(i=1;i<=110;i++)
    {
        a4[i][0]=-i;
        a4[i][1]=-i;
    }
    for(i=1;i<=110;i++)
    {
        a1[i][0]=i;
        a1[i][1]=1-i;
    }
    for(i=1;i<=110;i++)
    {
        a3[i][0]=-i;
        a3[i][1]=i;
    }
//    for(i=1;i<=20;i++)
//    {
//        cout<<a1[i][0]<<" "<<a1[i][1]<<endl;
//        cout<<a2[i][0]<<" "<<a2[i][1]<<endl;
//        cout<<a3[i][0]<<" "<<a3[i][1]<<endl;
//        cout<<a4[i][0]<<" "<<a4[i][1]<<endl;
//    }
    while(cin>>x>>y)
    {
        c=0;
        if((x==0 && y==0)||(x==1 && y==0))
        {
            cout<<"0"<<endl;
            continue;
        }
        for(i=1;i<=110;i++)
        {
            x1=a1[i][0];
            y1=a1[i][1];
            x2=a2[i][0];
            y2=a2[i][1];
//            cout<<x1<<" "<<y1<<endl;
//            cout<<x2<<" "<<y2<<endl;
            if(x1==x && x2==x && y>=y1 && y<= y2)
            {
                cout<<c+1<<endl;
                break;
            }
            c++;
            x1=a2[i][0];
            y1=a2[i][1];
            x2=a3[i][0];
            y2=a3[i][1];
            if(y1==y && y2==y && x>=x2 && x<=x1)
            {
                cout<<c+1<<endl;
                break;
            }
//            cout<<x1<<" "<<y1<<endl;
//            cout<<x2<<" "<<y2<<endl;
            c++;
            x1=a3[i][0];
            y1=a3[i][1];
            x2=a4[i][0];
            y2=a4[i][1];
            if(x1==x && x2==x && y<=y1 && y>=y2)
            {
                cout<<c+1<<endl;
                break;
            }
//            cout<<x1<<" "<<y1<<endl;
//            cout<<x2<<" "<<y2<<endl;
            c++;
            x1=a4[i][0];
            y1=a4[i][1];
            x2=a1[i+1][0];
            y2=a1[i+1][1];
            if(y1==y && y2==y && x<=x2 && x>=x1)
            {
                cout<<c+1<<endl;
                break;
            }
//            cout<<x1<<" "<<y1<<endl;
//            cout<<x2<<" "<<y2<<endl;
            c++;
        }
    }
    return 0;
}