#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int length,colour[35][35],finalflag;
void bfs(int arr1[][35],int start,int end,int m)
{
    int i,j,children1[35],children2[35],n=0,p=0,flag=1,c,y;
    memset(children1,0,sizeof(children1));
    memset(children2,0,sizeof(children2));
    children1[n++]=start;
    for(y=0; y<m; y++)
    {
        if(flag==1)
        {
            for(i=0; i<n; i++)
            {
                c=children1[i];
                if(finalflag==1)
                    break;
                for(j=1; j<=m; j++)
                {
                    if(colour[c][j]==0&&arr1[c][j]==1)
                    {
                        if(j==end)
                        {
                            length+=1;
                            finalflag=1;
                        }
                        if(finalflag==1)
                            break;
                        colour[c][j]=1;
                        children2[p++]=j;
                    }
                }
            }
            flag=2;
            n=0;
        }
        else
        {
            for(i=0; i<p; i++)
            {
                c=children2[i];
                for(j=1; j<=m; j++)
                {
                    if(colour[c][j]==0&&arr1[c][j]==1)
                    {
                        if(j==end)
                        {
                            length+=1;
                            finalflag=1;
                        }
                        if(finalflag==1)
                            break;
                        colour[c][j]=1;
                        children1[n++]=j;
                    }
                    if(finalflag==1)
                        break;
                }
            }
            flag=1;
            p=0;
        }
        if(finalflag==1)
            break;
        length+=1;
    }
    return;
}
int main ()
{
    int y,z,m,n,p,arr1[35][35],i,j,k,c,d,flag,dam,temp;
    char arr[35][3],a,cha[4][4];
    cin>>z;
    for(y=1; y<=z; y++)
    {
        memset(arr1,0,sizeof(arr1));
        scanf("%d %d %d%c",&m,&n,&p,&a);
        if(y==1)
            cout<<"SHIPPING ROUTES OUTPUT"<<endl;
        cout<<endl<<"DATA SET  "<<y<<endl<<endl;
        for(i=1; i<=m; i++)
        {
            scanf(" %s",arr[i]);
            arr1[i][i]=1;
        }
        for(i=1; i<=n; i++)
        {
            flag=0;
            for(j=1; j<=2; j++)
                scanf(" %s",cha[j]);
            j=1;
            for(k=1; k<=m; k++)
            {
                if((strcmp(cha[j],arr[k])==0||strcmp(cha[j+1],arr[k])==0)&&flag==0)
                {
                    if(strcmp(cha[j],arr[k])==0)
                        j+=1;
                    c=k;
                    flag=1;
                }
                else if(strcmp(cha[j],arr[k])==0)
                    d=k;
            }
            arr1[c][d]=1;
            arr1[d][c]=1;
        }
        for(i=1; i<=p; i++)
        {
            scanf("%d %s %s",&dam,cha[0],cha[1]);
            j=0;
            flag=0;
            for(k=1; k<=m; k++)
            {
                if((strcmp(cha[j],arr[k])==0||strcmp(cha[j+1],arr[k])==0)&&flag==0)
                {
                    if(strcmp(cha[j],arr[k])==0)
                        j+=1;
                    c=k;
                    flag=1;
                }
                else if(strcmp(cha[j],arr[k])==0)
                    d=k;
            }
            if(c>d)
            {
                temp=c;
                c=d;
                d=temp;
            }
            length=0;
            memset(colour,0,sizeof(colour));
            for(k=1; k<=m; k++)
                colour[k][k]=1;
            finalflag=0;
            bfs(arr1,c,d,m);
            if(finalflag==0)
                cout<<"NO SHIPMENT POSSIBLE"<<endl;
            else
                cout<<"$"<<(100*length*dam)<<endl;
        }
        if(y==z)
            cout<<endl<<"END OF OUTPUT"<<endl;
    }
    return 0;
}
