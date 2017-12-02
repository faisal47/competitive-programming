#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
struct node
{
    int serial;
    int time;
};
int main ()
{
    node lferry[10099],rferry[10099];
    char arr[10],rdir;
    int a,b,i,z,n,m,t,p,time[10099],top1,top2,rtime,flag,flag2,flag1,timeflag;
    cin>>z;
    while(z--)
    {
        a=b=top1=top2=rtime=flag=0;
        cin>>n>>t>>m;
        for(i=0; i<m; i++)
        {
            scanf("%d %s",&p,arr);
            if(strcmp("left",arr)==0)
            {
                lferry[a].serial=i;
                lferry[a].time=p;
                a++;
            }
            else
            {
                rferry[b].serial=i;
                rferry[b].time=p;
                b++;
            }
        }
        rtime=0;
        rdir='L';
        flag1=0;
        flag2=0;
        while(1)
        {
            i=n;
            flag=timeflag=0;
            if(top2>=b)
                flag2=1;
            if(top1>=a)
                flag1=1;
            if(rdir=='L')
            {
                if(1)
                {
                    while(i--)
                    {
                        if(top1<a)
                        {
                            if(lferry[top1].time<=rtime)
                            {
                                flag=1;
                                time[lferry[top1].serial]=rtime+t;
                                top1++;
                            }
                            else
                                break;
                        }
                        else
                            break;
                    }
                }
                if(top1>=a)
                    flag1=1;
                if(flag==0&&flag1==0&&flag2==0)
                {
                    if(lferry[top1].time<=rferry[top2].time)
                    {
                        rtime=lferry[top1].time;
                        rdir='L';
                        timeflag=1;
                    }
                    else
                    {
                        rtime=rferry[top2].time;
                        rdir='R';
                    }
                }
                else if(flag==0&&flag1==1&&flag2==0)
                {
                    rtime=rferry[top2].time;
                    rdir='R';
                }
                else if(flag==0&&flag1==0&&flag2==1)
                {
                    rdir='L';
                    timeflag=1;
                    rtime=lferry[top1].time;
                }
                else
                {
                    rdir='R';
                }
            }
            else
            {
                if(1)
                {
                    while(i--)
                    {
                        if(top2<b)
                        {
                            if(rferry[top2].time<=rtime)
                            {
                                flag=1;
                                time[rferry[top2].serial]=rtime+t;
                                top2++;
                            }
                            else
                                break;
                        }
                        else
                            break;
                    }
                }
                if(top2>=b)
                    flag2=1;
                if(flag==0&&flag1==0&&flag2==0)
                {
                    if(rferry[top2].time<=lferry[top1].time)
                    {
                        rtime=rferry[top2].time;
                        rdir='R';
                        timeflag=1;
                    }
                    else
                    {
                        rtime=lferry[top1].time;
                        rdir='L';
                    }
                }
                else if(flag==0&&flag1==0&&flag2==1)
                {
                    rtime=lferry[top1].time;
                    rdir='L';
                }
                else if(flag==0&&flag1==1&&flag2==0)
                {
                    rdir='R';
                    timeflag=1;
                    rtime=rferry[top2].time;
                }
                else
                {
                    rdir='L';
                }
            }
            if(timeflag==0)
                rtime+=t;
            if(flag1==1&&flag2==1)
                break;
        }
        for(i=0; i<m; i++)
            cout<<time[i]<<endl;
        if(z!=0)
            cout<<endl;
    }
    return 0;
}
