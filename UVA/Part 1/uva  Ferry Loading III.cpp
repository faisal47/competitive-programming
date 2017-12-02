#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
struct ferry
{
    int time;
    char dir;
};
int main ()
{
    ferry arr[10050];
    int n,t,m,i,j,z,rtime=0,top,flag;
    char arr1[10],rdir;
    cin>>z;
    while(z--)
    {
        cin>>n>>t>>m;
        top=rtime=0;
        for(i=0; i<m; i++)
        {
            scanf("%d %s",&j,arr1);
            arr[i].time=j;
            if(strcmp("left",arr1)==0)
                arr[i].dir='L';
            else
                arr[i].dir='R';
        }
        rdir='L';
        while(1)
        {
            i=n;
            flag=j=0;
            while(i--)
            {
                if(rtime<arr[top].time)
                {
                    if(flag==0)
                    {
                        flag=1;
                        if(rdir!=arr[top].dir)
                            rtime=(arr[top].time)+t;
                        else
                            rtime=arr[top].time;
                        rdir=arr[top].dir;
                        top++;
                        j++;
                    }
                    else
                        break;
                }
                else if(rtime>=arr[top].time)
                {
                    if(arr[top].dir==rdir)
                    {
                        top++;
                        j++;
                    }
                    else
                        break;
                }
                flag=1;
                if(top>=m)
                break;
            }
            rtime+=t;
            while(j>0)
            {
                j--;
                cout<<rtime<<endl;
            }
            if(rdir=='L')
                rdir='R';
            else
                rdir='L';
            if(top>=m)
                break;
        }
        if(z!=0)
            cout<<endl;
    }
    return 0;
}
