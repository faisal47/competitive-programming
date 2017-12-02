#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int arr[1100],arrtemp[1100];
int main ()
{
    int m,n,i,j;
    bool color[1100];
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(scanf("%d %d",&m,&n)==2)
    {
        memset(color,0,sizeof(color));
        for(i=0;i<m;i++)
        {
            cin>>arr[i];
            arrtemp[i]=arr[i];
        }
        sort(arrtemp,arrtemp+m);
        cout<<arrtemp[m-n]<<endl;
        for(i=m-1;i>(m-n);i--)
        {
            for(j=0;j<m;j++)
            {
                if(arr[j]==arrtemp[i]&&color[j]==0)
                {
                    color[j]=1;
                    cout<<j+1<<" ";
                    break;
                }
            }
        }
        for(j=0;j<m;j++)
            {
                if(arr[j]==arrtemp[m-n]&&color[j]==0)
                {
                    color[j]=1;
                    cout<<j+1<<endl;
                    break;
                }
            }
    }
    fclose(stdin);
    fclose(stdout);
}