#include <stdio.h>
#include <iostream>
using namespace std;
int col[10],add[20],biog[20],flag[10],a,b,t1;
void bt(int c)
{
    if(c==b)
    {
        col[c]=a;
        bt(c+1);
    }
    else if(c>8)
    {
        printf("%2d     ",t1++);
        for(int i=1;i<9;i++)
        cout<<" "<<col[i];
        cout<<endl;
    }
    else
    {
        for(int i=1;i<9;i++)
        {
            if(flag[i]==1 || add[i+c]==1 || biog[c-i+8]==1)
            {
                continue;
            }
            else
            {
                col[c]=i;
                flag[i]=add[i+c]=biog[c-i+8]=1;
                bt(c+1);
                flag[i]=add[i+c]=biog[c-i+8]=0;
            }
        }
    }
}
int main ()
{
    int test;
    cin>>test;
    while(test--)
    {
        t1=1;
        cin>>a>>b;
        printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n");
        cout<<endl;
        flag[a]=add[a+b]=biog[b-a+8]=1;
        bt(1);
        flag[a]=add[a+b]=biog[b-a+8]=0;
        if(test)
        cout<<endl;
    }
    return 0;
}
